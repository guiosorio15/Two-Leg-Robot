#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <Arduino.h>
#include <feet.h>

Feet pes;

void setup() {
    // Inicializa a comunicação I2C
    Serial.begin(9600);
    Wire.begin();
    pes.initialize_feet();
    //pes.move_inicial_pos();
    delay(2000);


    
}


void loop() {

    pes.move_inicial_pos();
    delay(3000);
    pes.move_r_foot_up();
    delay(3000);
    pes.move_l_foot_down();
    delay(3000);
    pes.move_l_leg_forward();
    delay(3000);


  
   


}
