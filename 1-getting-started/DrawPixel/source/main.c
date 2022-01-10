#include <stdint.h>

#define MODE3 0x3
#define ENABLEBG2 0x400

void setVideoMode(uint16_t flags) {
    *(uint16_t*) 0x4000000 = flags;
}

#define RGB(r,g,b) (uint16_t) ((b >> 3) << 10) + ((g >> 3) << 5) + (r >> 3)

int main() {
    setVideoMode(MODE3|ENABLEBG2);

    uint16_t *frameBuffer = (uint16_t *) 0x6000000;

    frameBuffer[80 * 240 + 120] = RGB(255, 0, 0);
    
    return 0;
}
