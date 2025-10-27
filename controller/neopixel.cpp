#include <stdio.h>
#include <stdlib.h>

#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"

#include "ws2812.pio.h"
#include "neopixel.h"

#define NUM_PIXELS 5

static inline void put_pixel(PIO pio, uint sm, uint32_t pixel_grb);
static inline uint32_t urgb_u32(uint8_t r, uint8_t g, uint8_t b);

PIO pio;
uint sm;
uint offset;

int neopixel_init(uint pin, uint frequency) {
    // Check the pin is compatible with the platform
    if (pin >= NUM_BANK0_GPIOS) {
        printf("Attempting to use a pin>=32 on a platform that does not support it.\n");
        return 1;
    }

    // This will find a free pio and state machine for our program and load it for us
    bool success = pio_claim_free_sm_and_add_program_for_gpio_range(&ws2812_program, &pio, &sm, &offset, pin, 1, true);
    if (!success) {
        printf("No free PIOs or state machines for WS2812\n");
        return 1;
    }
    printf("WS2812 got PIO %d, SM %d at 0x%d\n", pio, sm, offset);

    // Initialise the program
    ws2812_program_init(pio, sm, offset, pin, frequency, false);

    return 0;
}

void neopixel_step() {
    for (uint i = 0; i < NUM_PIXELS; ++i)
        put_pixel(pio, sm, rand());

    // sleep is called in the main loop
    // sleep_ms(10);
}

static inline void put_pixel(PIO pio, uint sm, uint32_t pixel_grb) {
    pio_sm_put_blocking(pio, sm, pixel_grb << 8u);
}

static inline uint32_t urgb_u32(uint8_t r, uint8_t g, uint8_t b) {
    return
            ((uint32_t) (r) << 8) |
            ((uint32_t) (g) << 16) |
            (uint32_t) (b);
}
