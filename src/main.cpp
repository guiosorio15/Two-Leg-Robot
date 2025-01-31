#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <Arduino.h>
#include <feet.h>
#include <mpu6050.h>


Feet pes;


void setup() {
    Serial.begin(9600);
    Wire.begin();
    pes.initialize_feet();

}



void loop() {
    pes.walk_forward();
}
