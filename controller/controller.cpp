#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"
#include "hardware/clocks.h"

// Modularised functionality
#include "blink.h"
#include "i2c.h"
#include "wifi.h"

// Local pin definitions
#include "pins.h"

int64_t alarm_callback(alarm_id_t id, void *user_data) {
    // Put your timeout handler code in here
    return 0;
}

int main()
{
    stdio_init_all();

    // Initialise the Wi-Fi chip
    wifi_init();

    // I2C Initialisation
    i2c_init2(I2C_PORT, I2C_BAUD_RATE, I2C_SDA, I2C_SCL);

    // PIO Blinking example
    blink_init();

    // Timer example code - This example fires off the callback after 2000ms
    add_alarm_in_ms(2000, alarm_callback, NULL, false);
    // For more examples of timer use see https://github.com/raspberrypi/pico-examples/tree/master/timer

    printf("System Clock Frequency is %d Hz\n", clock_get_hz(clk_sys));
    printf("USB Clock Frequency is %d Hz\n", clock_get_hz(clk_usb));
    // For more examples of clocks use see https://github.com/raspberrypi/pico-examples/tree/master/clocks

    // Initialise the Wi-Fi chip
    wifi_connect();

    while (true) {
        printf("Hello, world!\n");
        sleep_ms(1000);
    }
}
