#ifndef KICKDOWNSWITCH_HPP
#define KICKDOWNSWITCH_HPP

#include "canbus/can_hal.h"

class KickdownSwitch {

public:
    static bool is_pressed(EgsBaseCan *egs_can_hal, uint32_t expire_time_ms);
};

#endif
