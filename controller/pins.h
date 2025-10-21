// Pin definitions for the "switchboard" device.

// STDIO on UART0 (0/1)
#define STDIO_PORT uart0
#define STDIO_BAUD_RATE 115200
#define STDIO_OUT 0
#define STDIO_IN 1

// I2C on I2C0 (4/5)
#define I2C_PORT i2c0
#define I2C_BAUD_RATE 400 * 1000 // 400KHz
#define I2C_SDA 4
#define I2C_SCL 5

// Rotary encoder (2/3)
#define DIO_ENCODER_A 2
#define DIO_ENCODER_B 3

// Scanning matrix (6-8/9-11)
#define DIO_MATRIX_DO_A 6
#define DIO_MATRIX_DO_B 7
#define DIO_MATRIX_DO_C 8
#define DIO_MATRIX_DI_1 9
#define DIO_MATRIX_DI_2 10
#define DIO_MATRIX_DI_3 11

// 12 rotary switch
#define DIO_ROTARY_BIT_1 12
#define DIO_ROTARY_BIT_2 13
#define DIO_ROTARY_BIT_4 14
#define DIO_ROTARY_BIT_8 15

// Analogue inputs
#define AIO_SEL_1 21
#define AIO_SEL_2 22
#define AIO_ADC_0 26
#define AIO_ADC_1 27
#define AIO_ADC_2 28

// Neopixel output
#define DIO_NEOP_DATA 20
