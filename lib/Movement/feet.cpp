#include <feet.h>

Adafruit_PWMServoDriver pca9685 = Adafruit_PWMServoDriver(PCA9685_I2C_ADDRESS, Wire);

void Feet::move_inicial_pos() {
    Serial.println("Retornando à posição inicial...");

    // **Mover o pé esquerdo para INICIAL_L**
    if (pwm_l_atual > INICIAL_L) {
        for (int i = pwm_l_atual; i > INICIAL_L; i -= step) {
            pca9685.writeMicroseconds(L_foot, i);
            //delay(10);
        }
    } else if (pwm_l_atual < INICIAL_L) {
        for (int i = pwm_l_atual; i < INICIAL_L; i += step) {
            pca9685.writeMicroseconds(L_foot, i);
            //delay(10);
        }
    }
    pwm_l_atual = INICIAL_L;  // Atualiza a posição do servo esquerdo

    // **Mover o pé direito para INICIAL_R**
    if (pwm_r_atual > INICIAL_R) {
        for (int i = pwm_r_atual; i > INICIAL_R; i -= step) {
            pca9685.writeMicroseconds(R_foot, i);
            //delay(10);
        }
    } else if (pwm_r_atual < INICIAL_R) {
        for (int i = pwm_r_atual; i < INICIAL_R; i += step) {
            pca9685.writeMicroseconds(R_foot, i);
            //delay(10);
        }
    }
    pwm_r_atual = INICIAL_R;  // Atualiza a posição do servo direito

    Serial.println("Posição inicial alcançada.");
}

void Feet::move_l_foot_up() {
    Serial.println("Levantando pé esquerdo...");

    int novo_pwm = pwm_l_atual - step;
    while (novo_pwm < MAX_L) {  // Garante que não ultrapassa o limite superior
        pca9685.writeMicroseconds(L_foot, novo_pwm);
        //delay(10);
        novo_pwm += step;
    }
    pwm_l_atual = MAX_L;  // Atualiza a posição atual do servo
}

void Feet::move_l_foot_down() {
    Serial.println("Baixando pé esquerdo...");

    int novo_pwm = pwm_l_atual + step;
    while (novo_pwm > MIN_L) {  // Garante que não ultrapassa o limite inferior
        pca9685.writeMicroseconds(L_foot, novo_pwm);
        //delay(10);
        novo_pwm -= step;
    }
    pwm_l_atual = MIN_L;  // Atualiza a posição atual do servo
}

void Feet::move_r_foot_down() {
    Serial.println("Baixando pé direito...");

    int novo_pwm = pwm_r_atual + step;
    while (novo_pwm < MIN_R) {
        pca9685.writeMicroseconds(R_foot, novo_pwm);
        //delay(5);
        novo_pwm += step;
    }
    pwm_r_atual = MIN_R;
}

void Feet::move_r_foot_up() {
    Serial.println("Levantando pé direito...");

    int novo_pwm = pwm_r_atual - step;
    while (novo_pwm > MAX_R) {
        pca9685.writeMicroseconds(R_foot, novo_pwm);
        //delay(5);
        novo_pwm -= step;
    }
    pwm_r_atual = MAX_R;
}

void Feet::move_l_leg_forward() {
    Serial.println("Movendo perna esquerda para frente...");

    int novo_pwm_l = pwm_l_leg_atual + step;
    while (novo_pwm_l < MAX_FRONT_L) {  
        pca9685.writeMicroseconds(L_leg, novo_pwm_l);
        delay(10);
        novo_pwm_l += step;
    }
    pwm_l_leg_atual = MAX_FRONT_L;  // Atualiza a posição da perna esquerda
}

void Feet::move_l_leg_backward() {
    Serial.println("Movendo perna esquerda para trás...");

    int novo_pwm_l = pwm_l_leg_atual - step;
    while (novo_pwm_l > MAX_BACK_L) {  
        pca9685.writeMicroseconds(L_leg, novo_pwm_l);
        delay(10);
        novo_pwm_l -= step;
    }
    pwm_l_leg_atual = MAX_BACK_L;  // Atualiza a posição da perna esquerda
}

void Feet::move_r_leg_forward() {
    Serial.println("Movendo perna direita para frente...");

    int novo_pwm_r = pwm_r_leg_atual - step;
    while (novo_pwm_r > MIN_FRONT_R) {  
        pca9685.writeMicroseconds(R_leg, novo_pwm_r);
        delay(10);
        novo_pwm_r -= step;
    }
    pwm_r_leg_atual = MIN_FRONT_R;  // Atualiza a posição da perna direita
}

void Feet::move_r_leg_backward() {
    Serial.println("Movendo perna direita para trás...");

    int novo_pwm_r = pwm_r_leg_atual + step;
    while (novo_pwm_r < MIN_BACK_R) {  
        pca9685.writeMicroseconds(R_leg, novo_pwm_r);
        delay(10);
        novo_pwm_r += step;
    }
    pwm_r_leg_atual = MIN_BACK_R;  // Atualiza a posição da perna direita
}

void Feet::initialize_feet()
{
    while (!find_ServoDriver(PCA9685_I2C_ADDRESS)) {
    Serial.println("No PCA9685 found ... check your connections");
    delay(200);
  }

  delay(10);

  Serial.println("Found PCA9685");

    // Inicializa o PCA9685
    pca9685.begin();
    pca9685.setPWMFreq(50); // Frequência padrão para servos (50 Hz)
}

int Feet::find_ServoDriver(int addr)
{

  // test PCA9685 presence
  // write8(PCA9685_MODE1, MODE1_RESTART);

  Wire.beginTransmission(addr);
  Wire.write(PCA9685_MODE1);
  Wire.write(MODE1_RESTART);

  int err = Wire.endTransmission();

  return !err;
  
}






