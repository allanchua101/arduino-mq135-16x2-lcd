### Arduino Stabilized PPM capture via MQ135

![Banner](https://github.com/allanchua101/arduino-mq135-16x2-lcd/blob/main/snaps/banner.png)

In order to prevent continuos drastic shifts in MQ135 PPM captures due to inaccuracy, this repository implements a sample stabilization code that requires a minimum of 10-second worth of PPM capture to compute a sliding average of captured PPM. The final output is then displayed on both serial monitor and 16x2 LCD display.

### MQ135 - Core Sensor

This project revolves around data collected from MQ135:

![Core Sensor](https://github.com/allanchua101/arduino-mq135-16x2-lcd/blob/main/snaps/core-sensor.png)

### Context

Test output was captured during cooking time around the evening.

![Arduino Layout](https://github.com/allanchua101/arduino-mq135-16x2-lcd/blob/main/snaps/final-output.jfif)

### Improvement Opportunities

- We could add HDT11 or HDT22 sensors to capture stabilized humidity and temperature to adapt use-case on any environment (Country, Time of Day, Weather)
- We could use ESP8266 to integrate circuit and send batches of data to AWS.
- We could also play with Raspberry PI detection to capture image of room reporting high levels of PPM so we could perform some CV-based verification of potential fire.
