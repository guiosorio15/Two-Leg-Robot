#include "pico/stdlib.h"
#include "hardware/pwm.h"

#define SERVO_PIN 10

void setupPWM(uint pin) {
    gpio_set_function(pin, GPIO_FUNC_PWM);
    uint slice_num = pwm_gpio_to_slice_num(pin);
    pwm_set_wrap(slice_num, 20000); // 50 Hz (20 ms)
    pwm_set_enabled(slice_num, true);
}

void setServoAngle(uint pin, float angle) {
    uint slice_num = pwm_gpio_to_slice_num(pin);
    float pulse_width = 1000 + (angle / 180.0) * 1000; // 1ms-2ms
    uint level = (pulse_width * 4096) / 20000;         // Ajusta para 12 bits
    pwm_set_gpio_level(pin, level);
}

int main() {
    setupPWM(SERVO_PIN);

    while (true) {
        setServoAngle(SERVO_PIN, 0);    // Ângulo 0°
        sleep_ms(1000);
        setServoAngle(SERVO_PIN, 90);   // Ângulo 90°
        sleep_ms(1000);
        setServoAngle(SERVO_PIN, 180);  // Ângulo 180°
        sleep_ms(1000);
    }
}
