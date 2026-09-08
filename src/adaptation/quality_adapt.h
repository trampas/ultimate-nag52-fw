#ifndef QUALITY_ADAPT_H
#define QUALITY_ADAPT_H

#include <stdint.h>
#include "common_structs.h"
#include "shift_trace.h"
#include "nvs/module_settings.h"

/**
 * @brief Shift pressure and fill time trimmed from the measured shift quality.
 *
 * The closed loop the pressure calibration's margin has been waiting for. The
 * TCU already measures every shift (ShiftQuality); this turns the measurement
 * into a per-cell nudge of the same adaptation maps the built-in fill time and
 * fill pressure adaptation write, with the gating the literature insists on:
 * learn only from shifts the driver did not ask to be sporty, on the flat, warm,
 * and moving.
 *
 * Direction is asymmetric by design (recommendation.md, step 1b): a clutch that
 * slips under load is destroyed, one that is over-clamped is merely harsh. So
 * flare and slip-energy breaches raise pressure by a large step at once, and a
 * harsh shift lowers it by a small one.
 *
 * quality_decide() is a pure function of (quality, context, settings) so the
 * rule can be replayed on the host against logged drives before it is trusted
 * on the car - scripts/quality_adapt_sim.py compiles this file and does that.
 * Nothing in here touches hardware; applying the decision is the caller's job.
 */

enum QualityReason : uint8_t {
    QR_NOT_EVALUATED = 0,
    QR_DISABLED      = 1,   // ADP quality_adapt is off
    QR_NO_QUALITY    = 2,   // the trace had no valid vector for this shift
    QR_NOT_FORWARD   = 3,   // garage / reverse / unknown change
    QR_MANUAL        = 4,   // driver-requested shift
    QR_KICKDOWN      = 5,
    QR_AGILITY       = 6,   // driver was asking for performance
    QR_ATF_TEMP      = 7,
    QR_TOO_SLOW      = 8,   // output shaft below quality_min_output_rpm
    QR_GRADE         = 9,   // on a hill, per the road load estimator
    QR_FLARE         = 10,  // raised prefill and pressure
    QR_SLIP_BUDGET   = 11,  // raised pressure
    QR_SLOW_RESPONSE = 12,  // raised prefill
    QR_EARLY_BITE    = 13,  // lowered prefill
    QR_HARSH         = 14,  // lowered pressure
    QR_SOFT_LONG     = 15,  // raised pressure
    QR_IN_TARGET     = 16,  // nothing to do
    QR_CLAMPED       = 17,  // wanted to move, already at the clamp
};

struct QualityContext {
    GearChange change;
    uint8_t  agility_score;     // when the shift started
    bool     manual;
    bool     kickdown;
    bool     flared;            // turbine ran away during the shift
    int16_t  atf_temp;          // deg C
    uint16_t output_rpm;        // at shift start
    int16_t  terrain_coeff;     // road load estimate, sin(grade) x 10000
    uint8_t  road_confidence;   // 0-100
    int16_t  spc_offset_now;    // current cell contents, so the clamp can be honoured
    int16_t  prefill_offset_now;
};

struct QualityDecision {
    int16_t spc_delta;          // mBar, already clamped against the cell contents
    int16_t prefill_delta;      // cycles, likewise
    uint8_t reason;             // QualityReason
    bool    learned;            // true when the shift passed every gate, even if nothing moved
};

/// Which SPC adaptation cell a change reads and writes. Mirrors the EGS
/// convention: 2-1, 3-2 and 5-4 share the cell of the matching upshift; 4-3
/// has its own. Cell 0xFF for anything that is not a forward change.
uint8_t adapt_spc_cell(GearChange change);
/// True when the change is the owner of its SPC cell, i.e. learning pressure
/// from it does not silently recalibrate a different shift.
bool adapt_spc_cell_owner(GearChange change);
/// Prefill offset cell (the EGS map index of the change), 0xFF if not forward.
uint8_t adapt_prefill_cell(GearChange change);

QualityDecision quality_decide(const ShiftQuality* q, const QualityContext* c,
                               const ADP_MODULE_SETTINGS* s);
const char* quality_reason_text(uint8_t reason);

#endif // QUALITY_ADAPT_H
