### Arduino Stabilized PPM capture via MQ135

In order to prevent continous abrupt changes in MQ135 PPM captures due to inaccuracy, this repository implements a sample stabilization code that requires a minimum of 30-second worth of PPM capture to compute a sliding average of captured PPM. The final output is then displayed on both serial monitor and 16x2 LCD display.

### Context

Test output was captured during cooking time around the evening.

![Arduino Layout](https://github.com/allanchua101/arduino-mq135-16x2-lcd/blob/main/snaps/final-output.jfif)

### Improvement Opportunities

- We could add HDT11 or HDT22 sensors to capture stabilized humidity and temperature to adapt use-case on any environment (Country, Time of Day, Weather)
- We could use ESP8266 to integrate circuit and send microbatches of data to AWS.
- We could also play with Raspberry PI detection to capture image of room reporting high levels of PPM so we could perform some CV-based verification of potential fire.
