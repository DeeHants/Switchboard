# Switchboard
Switchboard experimental project

## The plan

The idea of this project is to:

- have a box/panel covered in switches, buttons, and other inputs
- with a controller reading all the inputs
- and a web interface with a live display of the panel

The end result should be a device, which when accessed in a web browser, should show a live copy of that device.

This should involve the following technologies:

- Electronics with various different ways of multiplexing inputs and outputs to the limited pins on a microcontroller
- Embedded programming (e.g. C++ or MicroPython)
- WebSockets for device <-> browser communications
- Responsive web inteface (e.g. React or Canvas)

## Hardware

### Inputs

After raiding various local electronics shops, I have a selection of switches, buttons, and other inputs ([full details](inputs.md)).

## Copyright

Licensed under the BSD 3-Clause License.
Code copyright (c) 2025, Deanna Earley.
