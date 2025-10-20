# Inputs

After raiding various local electronics shops, I have:

## Basic (digital) inputs

* 1x large on/off toggle (1 input)
* 1x large on/off/on toggle (2 inputs)
* 2x toggle button (2 inputs)
* 2x push to make momentary buttons (2 inputs)
* 1x key switch (1 input)
* 1x joystick press (1 input)

These can be connected using a scanning input matrix of 3x3, requiring 6 GPIO pins.
This could be reduced to 5 using a "decoder" (binary to individual pins) for the output.

## Analogue inputs

* 4x 10KΩ variable resistors (4 inputs)
* 1x X/Y joystick (2 inputs)

Using the same idea as the digital inputs, we can split these into 2 groups of 3, reading each group one at a time.
This would require 2 digital GPIO pins, and 3 ADC GPIO pins (or with a decoder, 3 digital and 1 ADC).

## Complex inputs

* 1x rotary encoder (2 inputs)
* 1x i2c rotary encoder (2 GPIO pins)
* 1x 12 position rotary switch (4 inputs using an encoder for binary input)

## Outputs

* 5x neopixel (1 output)

## GPIO pins

* 9 digital input pins
* 6 digital output pins
* 3 analogue inputs pins
* 2 (i2c) special pins

Using an RPi Pico 2, the suggested pinout:

* GP00 - UART TX
* GP01 - UART Rx
* GP02 - DI - Rotary encoder A
* GP03 - DI - Rotary encoder B
* GP04 - I2C SDA
* GP05 - I2C SCL
* GP06 - DO - Input matrix A
* GP07 - DO - Input matrix B
* GP08 - DO - Input matrix C
* GP09 - DI - Input matrix 1
* GP10 - DI - Input matrix 2
* GP11 - DI - Input matrix 3
* GP12 - DI - Rotary switch b1
* GP13 - DI - Rotary switch b2
* GP14 - DI - Rotary switch b4
* GP15 - DI - Rotary switch b8
* GP16 - SPI Rx (unused)
* GP17 - SPI CSn (unused)
* GP18 - SPI SCK (unused)
* GP19 - SPI Tx (unused)
* GP20 - DO - Neopixel
* GP21 - AO - Selector
* GP22 - AO - Selector
* GP26 - ADC 0
* GP27 - ADC 1
* GP28 - ADC 2
