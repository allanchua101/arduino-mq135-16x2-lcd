### Arduino Stabilized PPM capture via MQ135 and display to 16x2 LCD

In order to prevent continous abrupt changes in MQ135 PPM captures due to inaccuracy, this repository implements a sample stabilization code that requires a minimum of 30-second worth of PPM capture to compute a sliding average of captured PPM.

### Context

Test output was captured during cooking time around the evening.

![Arduino Layout](https://github.com/allanchua101/arduino-mq135-16x2-lcd/blob/main/snaps/final-output.jfif)
