#ifndef FEET_H
#define FEET_H

#pragma once

//PÉS 
#define L_foot 0
#define R_foot 1

#define INICIAL_R 1000
#define INICIAL_L 1225
#define MIN_R 1150  
#define MIN_L 1000 
#define MAX_R 800 
#define MAX_L 1400
#define PCA9685_I2C_ADDRESS 0x40
#define MPU_I2C_ADRESS 0x68


//PERNAS
#define L_leg 3
#define R_leg 2

#define INICIAL_R_P 2200
#define INICIAL_L_P 1000
#define MAX_FRONT_R 1700 
#define MAX_BACK_R 2400   
#define MAX_FRONT_L 700 
#define MAX_BACK_L 450




//OLHOS

#define TRIG_PIN 17
#define ECHO_PIN 16

#define MPU_SDA 6  // GPIO onde está o SDA
#define MPU_SCL 7  // GPIO onde está o SCL

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <Arduino.h>



class Feet
{
    public:
    // Declaração externa do PCA9685 para evitar redefinições
    Adafruit_PWMServoDriver pca9685;

    int step = 2;
    int pwm_l_atual = 0;
    int pwm_r_atual = 0;
    int pwm_l_leg_atual = 0;
    int pwm_r_leg_atual = 0;


    void initialize_feet();

    void walk_forward();
    void move_l_foot_up();
    void move_l_foot_down();
    void move_r_foot_down();
    void move_r_foot_up();

    void move_l_leg_backward();
    void move_r_leg_forward();
    void move_r_leg_backward();
    void move_l_leg_forward();

    void move_l_foot_inicial_pos();
    void move_r_foot_inicial_pos();
    void move_l_leg_inicial_pos();
    void move_r_leg_inicial_pos();
    void move_all_initial();

    int measure_distance();

    void turn_right();
    void turn_around();
    void move_l_leg_backward_full();
    void move_r_leg_backward_full();
    void move_l_leg_forward_full();
    void move_r_leg_forward_full();

    void  move_l_foot_up_full();
    void  move_l_foot_down_full();
    void  move_r_foot_up_full();
    void  move_r_foot_down_full();

    void hello_all();
    int find_ServoDriver(int addr);

};

#endif
