#include "kickdownswitch.hpp"
#include "board_config.h"


bool KickdownSwitch::is_pressed(EgsBaseCan *egs_can_hal, uint32_t expire_time_ms)
{
    return pcb_gpio_matrix->is_kickdown_pressed() || egs_can_hal->get_kickdown(expire_time_ms);
}
