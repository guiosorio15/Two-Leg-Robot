#ifndef FEET_H
#define FEET_H
//PÉS 
#define L_foot 0
#define R_foot 1

#define INICIAL_R 1000
#define INICIAL_L 1225
#define MIN_R 1500  
#define MIN_L 800  
#define MAX_R 500 
#define MAX_L 1800
#define PCA9685_I2C_ADDRESS 0x40


//PERNAS
#define L_leg 3
#define R_leg 2

#define INICIAL_R_P 2200
#define INICIAL_L_P 1575
#define MIN_FRONT_R 1150  
#define MIN_BACK_R 2600   
#define MAX_FRONT_L 2550 
#define MAX_BACK_L 550

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <Arduino.h>

class Feet
{
    public:
    // Declaração externa do PCA9685 para evitar redefinições
    Adafruit_PWMServoDriver pca9685;

    int step = 1;
    int pwm_l_atual = INICIAL_L;
    int pwm_r_atual = INICIAL_R;
    int pwm_l_leg_atual = INICIAL_L_P;
    int pwm_r_leg_atual = INICIAL_R_P;


    void initialize_feet();
    void move_l_foot_up();
    void move_l_foot_down();
    void move_inicial_pos();
    void move_r_foot_down();
    void move_r_foot_up();
    void move_l_leg_backward();
    void move_r_leg_forward();
    void move_r_leg_backward();
    void move_l_leg_forward();
    int find_ServoDriver(int addr);

};

#endif
