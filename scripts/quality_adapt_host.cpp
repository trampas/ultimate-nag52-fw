// Host driver for the quality adaptation rule, so the exact firmware decision
// (src/adaptation/quality_adapt.cpp) can be replayed against logged drives.
//
// Reads one shift per line on stdin:
//   change agility manual kickdown flared atf output_rpm terrain conf spc_now pre_now
//   response_ms duration_ms peak_jerk_mms3 torque_hole slip_energy_j valid
// and writes "spc_delta prefill_delta reason learned reason_text" per line.
// Settings overrides come as "name=value" arguments and apply to the ADP struct.
//
// Built by scripts/quality_adapt_sim.py; not part of the firmware.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "adaptation/quality_adapt.h"

int SIM_LOG_VERBOSE = 0;
void sim_log(const char*, const char*, const char*, ...) {}

#define SET(name) if (0 == strcmp(k, #name)) { s.name = (decltype(s.name))atof(v); return true; }
static bool apply_override(ADP_MODULE_SETTINGS& s, char* kv) {
    char* eq = strchr(kv, '=');
    if (!eq) { return false; }
    *eq = 0; const char* k = kv; const char* v = eq + 1;
    SET(min_atf_temp) SET(max_atf_temp) SET(prefill_max_pressure_delta)
    SET(quality_adapt) SET(quality_max_agility) SET(quality_jerk_target_mms3)
    SET(quality_response_hi_ms) SET(quality_response_lo_ms) SET(quality_hole_target)
    SET(quality_slip_budget_j) SET(quality_duration_hi_ms) SET(quality_spc_step_mbar)
    SET(quality_flare_spc_step_mbar) SET(quality_prefill_step_cycles)
    SET(quality_flare_prefill_step_cycles) SET(quality_prefill_max_cycles)
    SET(quality_min_output_rpm) SET(quality_max_terrain)
    fprintf(stderr, "unknown setting %s\n", k);
    return false;
}

int main(int argc, char** argv) {
    ADP_MODULE_SETTINGS s = ADP_DEFAULT_SETTINGS;
    s.quality_adapt = true;
    for (int i = 1; i < argc; i++) {
        if (!apply_override(s, argv[i])) { return 2; }
    }
    char line[512];
    while (fgets(line, sizeof(line), stdin)) {
        int change, agility, manual, kickdown, flared, atf, out_rpm, terrain, conf, spc_now, pre_now;
        unsigned resp, dur, jerk, hole, slip, valid;
        int n = sscanf(line, "%d %d %d %d %d %d %d %d %d %d %d %u %u %u %u %u %u",
                       &change, &agility, &manual, &kickdown, &flared, &atf, &out_rpm, &terrain, &conf,
                       &spc_now, &pre_now, &resp, &dur, &jerk, &hole, &slip, &valid);
        if (n != 17) { fprintf(stderr, "bad line: %s", line); continue; }
        ShiftQuality q = {};
        q.response_ms = (uint16_t)resp; q.duration_ms = (uint16_t)dur;
        q.peak_jerk = (uint16_t)(jerk > 65535 ? 65535 : jerk);
        q.torque_hole = (uint16_t)hole; q.slip_energy_j = slip; q.valid = (uint8_t)valid;
        QualityContext c = {};
        c.change = (GearChange)change; c.agility_score = (uint8_t)agility;
        c.manual = manual != 0; c.kickdown = kickdown != 0; c.flared = flared != 0;
        c.atf_temp = (int16_t)atf; c.output_rpm = (uint16_t)out_rpm;
        c.terrain_coeff = (int16_t)terrain; c.road_confidence = (uint8_t)conf;
        c.spc_offset_now = (int16_t)spc_now; c.prefill_offset_now = (int16_t)pre_now;
        QualityDecision d = quality_decide(&q, &c, &s);
        printf("%d %d %d %d %s\n", d.spc_delta, d.prefill_delta, d.reason, d.learned ? 1 : 0,
               quality_reason_text(d.reason));
        fflush(stdout);
    }
    return 0;
}
