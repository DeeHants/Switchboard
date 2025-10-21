#include "hardware/i2c.h"
#include "hardware/pio.h"

int i2c_init2(i2c_inst_t *port, uint baud_rate, uint sda, uint scl) {
    // I2C Initialisation. Using it at 400Khz.
    i2c_init(port, baud_rate);

    gpio_set_function(sda, GPIO_FUNC_I2C);
    gpio_set_function(scl, GPIO_FUNC_I2C);
    gpio_pull_up(sda);
    gpio_pull_up(scl);

    return 0;
}
