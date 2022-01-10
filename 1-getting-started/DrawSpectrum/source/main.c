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

    // Remember our horizontal resolution is 240 pixels, pixels 0 through to 239
    for (int x = 0; x < 239; x++) {
        // 160 pixels, 0 through 159
        for (int y = 0; y < 159; y++) {
            frameBuffer[y * 240 + x] = RGB(255-x, 255-y, x);
        }
    }
    
    return 0;
}
