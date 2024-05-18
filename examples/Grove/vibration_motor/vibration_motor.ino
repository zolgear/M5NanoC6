/**
 * @file vibration_motor.ino
 * @author zolgear
 * @brief This program controls a Grove - Vibration Motor connected to an M5NanoC6 board.
 *        The motor is activated when the A button on the M5NanoC6 is pressed and deactivated
 *        when the button is released. An LED on the M5NanoC6 is also turned on and off in sync 
 *        with the motor to provide a visual indication of the motor's state.
 * @version 0.1
 * @date 2024-05-19
 *
 *
 * @Hardwares: M5NanoC6
 * @Platform Version: Arduino ESP32 Board Manager v3.0.0-alpha3
 * @Dependent Library:
 * M5NanoC6: https://github.com/m5stack/M5NanoC6
 * Grove - Vibration Motor: https://wiki.seeedstudio.com/Grove-Vibration_Motor/
 */

#include "M5NanoC6.h"

int VibratorOn = 0;

void setup() {
    NanoC6.begin();

    pinMode(M5NANO_C6_GROVE_IO1_PIN, OUTPUT);
    pinMode(M5NANO_C6_BLUE_LED_PIN, OUTPUT);
}

void loop() {
    NanoC6.update();
    if (NanoC6.BtnA.wasPressed()) {
        VibratorOn = 1;
    }

    if (NanoC6.BtnA.wasReleased()) {
        VibratorOn = 0;
    }

    if (VibratorOn) {
        digitalWrite(M5NANO_C6_BLUE_LED_PIN, HIGH);
        digitalWrite(M5NANO_C6_GROVE_IO1_PIN, HIGH);
    } else {
        digitalWrite(M5NANO_C6_BLUE_LED_PIN, LOW);
        digitalWrite(M5NANO_C6_GROVE_IO1_PIN, LOW);
    }
}