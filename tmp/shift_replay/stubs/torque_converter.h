#ifndef TCC_STUB_H
#define TCC_STUB_H
#define TORQUE_CONVERTER_H__
#include <stdint.h>
class TorqueConverter {
public:
    int starts = 0, ends = 0;
    bool shifting = false;
    void shift_start(bool upshift, bool release_shifting) { starts++; shifting = true; }
    void shift_end() { ends++; shifting = false; }
    void reset() {}
};
#endif
