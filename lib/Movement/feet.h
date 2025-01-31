#ifndef FEET_H
#define FEET_H

#pragma once

//PÉS 
#define L_foot 0
#define R_foot 1

#define INICIAL_R 1000
#define INICIAL_L 1225
#define MIN_R 1100  
#define MIN_L 1125  
#define MAX_R 900 
#define MAX_L 1325
#define PCA9685_I2C_ADDRESS 0x40
#define MPU_I2C_ADRESS 0x68


//PERNAS
#define L_leg 3
#define R_leg 2

#define INICIAL_R_P 2000
#define INICIAL_L_P 800
#define MAX_FRONT_R 1700 
#define MAX_BACK_R 2200   
#define MAX_FRONT_L 900 
#define MAX_BACK_L 450
#define WALK_FRONT_R 1150
#define WALK_FRONT_L 900

//OLHOS

#define TRIG_PIN 17
#define ECHO_PIN 16

#define MPU_SDA 6  // GPIO onde está o SDA
#define MPU_SCL 7  // GPIO onde está o SCL

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <Arduino.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>



class Feet
{
    public:
    // Declaração externa do PCA9685 para evitar redefinições
    Adafruit_PWMServoDriver pca9685;

    int step = 1;
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


    int find_ServoDriver(int addr);

};

#endif
