#pragma once
#include <cmath>
#include <cstdint>

namespace Egs51Torque {
constexpr uint8_t INACTIVE = 0xFE;
// GS218 is 3 Nm/count. Its gross/net convention must be explicitly selected;
// never allow negative, non-finite or overflowing input to wrap into a byte.
inline uint8_t encode(float net_nm, int16_t drag_nm, bool gross) {
    if (!std::isfinite(net_nm) || (gross && (drag_nm < 0 || drag_nm == INT16_MAX))) {
        return INACTIVE;
    }
    const float wire_nm = net_nm + (gross ? drag_nm : 0);
    if (wire_nm <= 0) { return 0; }
    if (wire_nm >= 3 * 0xFD) { return 0xFD; }
    return static_cast<uint8_t>(wire_nm / 3);
}
}
