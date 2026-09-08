#include "quality_adapt.h"

uint8_t adapt_spc_cell(GearChange change) {
    switch (change) {
        case GearChange::_1_2:
        case GearChange::_2_1: return 0;
        case GearChange::_2_3:
        case GearChange::_3_2: return 1;
        case GearChange::_3_4: return 2;
        case GearChange::_4_5:
        case GearChange::_5_4: return 3;
        case GearChange::_4_3: return 6;
        default:               return 0xFF;
    }
}

bool adapt_spc_cell_owner(GearChange change) {
    switch (change) {
        case GearChange::_1_2:
        case GearChange::_2_3:
        case GearChange::_3_4:
        case GearChange::_4_5:
        case GearChange::_4_3: return true;
        default:               return false;
    }
}

uint8_t adapt_prefill_cell(GearChange change) {
    if (GearChange::_IDLE < change && change <= GearChange::_5_4) {
        return (uint8_t)change - 1;
    }
    return 0xFF;
}

static int16_t clamp_step(int32_t now, int32_t step, int32_t lim) {
    int32_t want = now + step;
    if (want > lim)  { want = lim; }
    if (want < -lim) { want = -lim; }
    return (int16_t)(want - now);
}

QualityDecision quality_decide(const ShiftQuality* q, const QualityContext* c,
                               const ADP_MODULE_SETTINGS* s) {
    QualityDecision d = { .spc_delta = 0, .prefill_delta = 0, .reason = QR_NOT_EVALUATED, .learned = false };
    if (nullptr == q || nullptr == c || nullptr == s) { return d; }

    // ---- gates: is this a shift worth learning from? -------------------------
    if (!s->quality_adapt)                          { d.reason = QR_DISABLED;    return d; }
    if (0 == q->valid)                              { d.reason = QR_NO_QUALITY;  return d; }
    if (0xFF == adapt_prefill_cell(c->change))      { d.reason = QR_NOT_FORWARD; return d; }
    if (c->manual)                                  { d.reason = QR_MANUAL;      return d; }
    if (c->kickdown)                                { d.reason = QR_KICKDOWN;    return d; }
    if (c->agility_score > s->quality_max_agility)  { d.reason = QR_AGILITY;     return d; }
    if (c->atf_temp < s->min_atf_temp || c->atf_temp > s->max_atf_temp) { d.reason = QR_ATF_TEMP; return d; }
    if (c->output_rpm < s->quality_min_output_rpm)  { d.reason = QR_TOO_SLOW;    return d; }
    if (c->road_confidence >= 50 &&
        (c->terrain_coeff > (int16_t)s->quality_max_terrain ||
         c->terrain_coeff < -(int16_t)s->quality_max_terrain)) { d.reason = QR_GRADE; return d; }
    d.learned = true;

    const bool owns_spc = adapt_spc_cell_owner(c->change);
    const int32_t spc_lim = s->prefill_max_pressure_delta;
    const int32_t pre_lim = s->quality_prefill_max_cycles;
    int32_t spc_want = 0;
    int32_t pre_want = 0;
    uint8_t reason = QR_IN_TARGET;

    // ---- safety first: anything that says the clutch was under-clamped ------
    if (c->flared) {
        pre_want = s->quality_flare_prefill_step_cycles;
        spc_want = s->quality_flare_spc_step_mbar;
        reason = QR_FLARE;
    } else if (q->slip_energy_j > s->quality_slip_budget_j) {
        spc_want = s->quality_flare_spc_step_mbar;
        reason = QR_SLIP_BUDGET;
    } else {
        // ---- fill time from response ----------------------------------------
        // response_ms == 0 means the ratio never crossed the 10 % mark before
        // the shift ended (or the car was too slow to judge); learn nothing.
        if (q->response_ms > s->quality_response_hi_ms) {
            pre_want = s->quality_prefill_step_cycles;
            reason = QR_SLOW_RESPONSE;
        } else if (q->response_ms != 0 && q->response_ms < s->quality_response_lo_ms &&
                   q->torque_hole > s->quality_hole_target) {
            pre_want = -s->quality_prefill_step_cycles;
            reason = QR_EARLY_BITE;
        }
        // ---- pressure from feel ----------------------------------------------
        if (q->peak_jerk > s->quality_jerk_target_mms3) {
            spc_want = -s->quality_spc_step_mbar;
            if (QR_IN_TARGET == reason) { reason = QR_HARSH; }
        } else if (q->peak_jerk < s->quality_jerk_target_mms3 / 2 &&
                   q->duration_ms > s->quality_duration_hi_ms) {
            spc_want = s->quality_spc_step_mbar;
            if (QR_IN_TARGET == reason) { reason = QR_SOFT_LONG; }
        }
    }

    if (!owns_spc) { spc_want = 0; }     // shared cell: fill time only
    d.prefill_delta = clamp_step(c->prefill_offset_now, pre_want, pre_lim);
    d.spc_delta = clamp_step(c->spc_offset_now, spc_want, spc_lim);
    if ((0 != spc_want || 0 != pre_want) && 0 == d.spc_delta && 0 == d.prefill_delta) {
        reason = QR_CLAMPED;
    }
    d.reason = reason;
    return d;
}

const char* quality_reason_text(uint8_t reason) {
    switch (reason) {
        case QR_NOT_EVALUATED: return "not evaluated";
        case QR_DISABLED:      return "disabled";
        case QR_NO_QUALITY:    return "no quality vector";
        case QR_NOT_FORWARD:   return "not a forward shift";
        case QR_MANUAL:        return "manual shift";
        case QR_KICKDOWN:      return "kickdown";
        case QR_AGILITY:       return "agility score too high";
        case QR_ATF_TEMP:      return "ATF temperature";
        case QR_TOO_SLOW:      return "output speed too low";
        case QR_GRADE:         return "on a grade";
        case QR_FLARE:         return "flare";
        case QR_SLIP_BUDGET:   return "slip energy over budget";
        case QR_SLOW_RESPONSE: return "slow response";
        case QR_EARLY_BITE:    return "early bite";
        case QR_HARSH:         return "harsh";
        case QR_SOFT_LONG:     return "soft and long";
        case QR_IN_TARGET:     return "in target";
        case QR_CLAMPED:       return "at clamp";
        default:               return "?";
    }
}
