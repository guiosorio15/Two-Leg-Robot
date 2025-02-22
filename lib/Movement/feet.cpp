#include <feet.h>

Adafruit_PWMServoDriver pca9685 = Adafruit_PWMServoDriver(PCA9685_I2C_ADDRESS, Wire);



void Feet::move_l_foot_inicial_pos() {
    Serial.println("Retornando pé esquerdo à posição inicial...");
    Serial.print("Pé esquerdo atual antes de mover: "); Serial.println(pwm_l_atual);

    if (pwm_l_atual > INICIAL_L) {
        for (int i = pwm_l_atual; i >= INICIAL_L; i -= step) {
            pca9685.writeMicroseconds(L_foot, i);
        }
    } else if (pwm_l_atual < INICIAL_L) {
        for (int i = pwm_l_atual; i <= INICIAL_L; i += step) {
            pca9685.writeMicroseconds(L_foot, i);
        }
    }

    pwm_l_atual = INICIAL_L;  // Atualiza o valor correto
    Serial.print("Novo valor de pwm_l_atual: "); Serial.println(pwm_l_atual);
    Serial.println("Pé esquerdo na posição inicial.");
}

void Feet::move_r_foot_inicial_pos() {
    Serial.println("Retornando pé direito à posição inicial...");
    Serial.print("Pé direito atual: "); Serial.println(pwm_r_atual);

    if (pwm_r_atual > INICIAL_R) {
        for (int i = pwm_r_atual; i >= INICIAL_R; i -= step) {  // Correção aqui
            pca9685.writeMicroseconds(R_foot, i);
        }
    } else if (pwm_r_atual < INICIAL_R) {
        for (int i = pwm_r_atual; i <= INICIAL_R; i += step) {  // Correção aqui
            pca9685.writeMicroseconds(R_foot, i);
        }
    }
    pwm_r_atual = INICIAL_R;
    Serial.println("Pé direito na posição inicial.");
}

void Feet::move_l_leg_inicial_pos() {
    Serial.println("Retornando perna esquerda à posição inicial...");
    Serial.print("Perna esquerda atual: "); Serial.println(pwm_l_leg_atual);

    if (pwm_l_leg_atual > INICIAL_L_P) {
        for (int i = pwm_l_leg_atual; i >= INICIAL_L_P; i -= step) {
            pca9685.writeMicroseconds(L_leg, i);
        }
    } else if (pwm_l_leg_atual < INICIAL_L_P) {
        for (int i = pwm_l_leg_atual; i <= INICIAL_L_P; i += step) {
            pca9685.writeMicroseconds(L_leg, i);
        }
    }
    pwm_l_leg_atual = INICIAL_L_P;
    Serial.println("Perna esquerda na posição inicial.");
}

void Feet::move_r_leg_inicial_pos() {
    Serial.println("Retornando perna direita à posição inicial...");
    Serial.print("Perna direita atual: "); Serial.println(pwm_r_leg_atual);

    if (pwm_r_leg_atual > INICIAL_R_P) {
        for (int i = pwm_r_leg_atual; i >= INICIAL_R_P; i -= step) {
            pca9685.writeMicroseconds(R_leg, i);
        }
    } else if (pwm_r_leg_atual < INICIAL_R_P) {
        for (int i = pwm_r_leg_atual; i <= INICIAL_R_P; i += step) {
            pca9685.writeMicroseconds(R_leg, i);
        }
    }
    pwm_r_leg_atual = INICIAL_R_P;
    Serial.println("Perna direita na posição inicial.");
}

void Feet::move_all_initial() {
    Serial.println("Movendo todas as partes para a posição inicial...");
    move_l_foot_inicial_pos();
    move_r_foot_inicial_pos();
    move_l_leg_inicial_pos();
    move_r_leg_inicial_pos();
    Serial.println("Posição inicial concluída.");
}

void Feet::move_l_foot_up() {
    Serial.println("Levantando pé esquerdo...");
    Serial.print("Pé esquerdo atual antes de mover: "); Serial.println(pwm_l_atual);

    int novo_pwm = pwm_l_atual;
    while (novo_pwm <= MAX_L) {  // Corrigido: agora inclui o MAX_L corretamente
        pca9685.writeMicroseconds(L_foot, novo_pwm);
        novo_pwm += step;
    }

    pwm_l_atual = MAX_L;  // Atualiza o valor corretamente
    Serial.print("Novo valor de pwm_l_atual: "); Serial.println(pwm_l_atual);
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
        //delay(10);
        novo_pwm_l += step;
    }
    pwm_l_leg_atual = MAX_FRONT_L;  // Atualiza a posição da perna esquerda
}

void Feet::move_l_leg_backward() {
    Serial.println("Movendo perna esquerda para trás...");

    int novo_pwm_l = pwm_l_leg_atual - step;
    while (novo_pwm_l > MAX_BACK_L) {  
        pca9685.writeMicroseconds(L_leg, novo_pwm_l);
        //delay(10);
        novo_pwm_l -= step;
    }
    pwm_l_leg_atual = MAX_BACK_L;  // Atualiza a posição da perna esquerda
}

void Feet::move_r_leg_forward() {
    Serial.println("Movendo perna direita para frente...");

    int novo_pwm_r = pwm_r_leg_atual - step;
    while (novo_pwm_r > MAX_FRONT_R) {  
        pca9685.writeMicroseconds(R_leg, novo_pwm_r);
        //delay(10);
        novo_pwm_r -= step;
    }
    pwm_r_leg_atual = MAX_FRONT_R;  // Atualiza a posição da perna direita
}

void Feet::move_r_leg_backward() {
    Serial.println("Movendo perna direita para trás...");

    int novo_pwm_r = pwm_r_leg_atual + step;
    while (novo_pwm_r < MAX_BACK_R) {  
        pca9685.writeMicroseconds(R_leg, novo_pwm_r);
        //delay(10);
        novo_pwm_r += step;
    }
    pwm_r_leg_atual = MAX_BACK_R;  // Atualiza a posição da perna direita
}

void Feet::walk_forward() {
    move_all_initial();
    move_l_foot_down();
    move_l_leg_forward();
    move_l_foot_inicial_pos();
    move_r_foot_up();
    move_r_leg_backward();
    move_r_foot_inicial_pos();
    move_all_initial();

}

void Feet::initialize_feet() {
    while (!find_ServoDriver(PCA9685_I2C_ADDRESS)) {
        Serial.println("No PCA9685 found ... check your connections");
        delay(200);
    }

    Serial.println("Found PCA9685");
    pca9685.begin();
    pca9685.setPWMFreq(50); // Frequência padrão para servos (50 Hz)
}

void Feet::turn_around() {
    Serial.println("Rodando 180 graus...");

    for (int i = 0; i < 4; i++) {  // 4 passos para uma volta completa
        move_r_foot_up();           // Levanta o pé direito
        move_l_leg_backward();      // Move a perna esquerda para trás
        move_r_foot_inicial_pos();  // Volta o pé direito para a posição inicial

        move_l_foot_up();           // Levanta o pé esquerdo
        move_r_leg_forward();       // Move a perna direita para frente
        move_l_foot_inicial_pos();  // Volta o pé esquerdo para a posição inicial
    }

    move_all_initial(); // Garante que os pés ficam na posição inicial após a rotação
    Serial.println("Rotação completa.");
}

int Feet::measure_distance() {
    Serial.println("Medindo distância...");

    // Garante que TRIG está baixo antes de enviar o pulso
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);

    // Envia pulso de 10µs no TRIG para ativar a medição
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);

    // Mede o tempo de resposta do ECHO
    long duration = pulseIn(ECHO_PIN, HIGH);

    // Calcula a distância (tempo * velocidade do som / 2)
    int distancia = (duration * 0.0343) / 2;

    Serial.print("Distância medida: ");
    Serial.print(distancia);
    Serial.println(" cm");

    return distancia;
}

void Feet::move_l_leg_forward_full() {
    Serial.println("Movendo perna esquerda para frente...");

    int novo_pwm_l = pwm_l_leg_atual + step;
    while (novo_pwm_l < 2000) {  
        pca9685.writeMicroseconds(L_leg, novo_pwm_l);
        //delay(10);
        novo_pwm_l += step;
    }
    pwm_l_leg_atual = 2000;  // Atualiza a posição da perna esquerda
}

void Feet::move_l_leg_backward_full() {
    Serial.println("Movendo perna esquerda para trás...");

    int novo_pwm_l = pwm_l_leg_atual - step;
    while (novo_pwm_l > 500) {  
        pca9685.writeMicroseconds(L_leg, novo_pwm_l);
        //delay(10);
        novo_pwm_l -= step;
    }
    pwm_l_leg_atual = 500;  // Atualiza a posição da perna esquerda
}

void Feet::move_r_leg_forward_full() {
    Serial.println("Movendo perna direita para frente...");

    int novo_pwm_r = pwm_r_leg_atual - step;
    while (novo_pwm_r > 1150) {  
        pca9685.writeMicroseconds(R_leg, novo_pwm_r);
        //delay(10);
        novo_pwm_r -= step;
    }
    pwm_r_leg_atual = 1150;  // Atualiza a posição da perna direita
}

void Feet::move_r_leg_backward_full() {
    Serial.println("Movendo perna direita para trás...");

    int novo_pwm_r = pwm_r_leg_atual + step;
    while (novo_pwm_r < 2600) {  
        pca9685.writeMicroseconds(R_leg, novo_pwm_r);
        //delay(10);
        novo_pwm_r += step;
    }
    pwm_r_leg_atual = 2600;  // Atualiza a posição da perna direita
}

void Feet::move_l_foot_up_full() {
    Serial.println("Levantando pé esquerdo...");
    Serial.print("Pé esquerdo atual antes de mover: "); Serial.println(pwm_l_atual);

    int novo_pwm = pwm_l_atual;
    while (novo_pwm <= 1800) {  // Corrigido: agora inclui o MAX_L corretamente
        pca9685.writeMicroseconds(L_foot, novo_pwm);
        novo_pwm += step;
    }

    pwm_l_atual = 1800;  // Atualiza o valor corretamente
    Serial.print("Novo valor de pwm_l_atual: "); Serial.println(pwm_l_atual);
}

void Feet::move_l_foot_down_full() {
    Serial.println("Baixando pé esquerdo...");

    int novo_pwm = pwm_l_atual + step;
    while (novo_pwm > 800) {  // Garante que não ultrapassa o limite inferior
        pca9685.writeMicroseconds(L_foot, novo_pwm);
        //delay(10);
        novo_pwm -= step;
    }
    pwm_l_atual = 800;  // Atualiza a posição atual do servo
}

void Feet::move_r_foot_down_full() {
    Serial.println("Baixando pé direito...");

    int novo_pwm = pwm_r_atual + step;
    while (novo_pwm < 1500) {
        pca9685.writeMicroseconds(R_foot, novo_pwm);
        //delay(5);
        novo_pwm += step;
    }
    pwm_r_atual = 1500;
}

void Feet::move_r_foot_up_full() {
    Serial.println("Levantando pé direito...");

    int novo_pwm = pwm_r_atual - step;
    while (novo_pwm > 500) {
        pca9685.writeMicroseconds(R_foot, novo_pwm);
        //delay(5);
        novo_pwm -= step;
    }
    pwm_r_atual = 500;
}


void Feet::turn_right(){
    
    move_r_foot_up();
    move_l_foot_up();
    move_r_foot_down();
    move_l_foot_down();

    Serial.println("90 graus para a direita...");

    move_all_initial();      // Garante que os pés começam alinhados
    move_r_foot_up_full();        // Levanta o pé direito para reduzir atrito
    move_l_leg_forward_full();  // Move a perna esquerda para frente
    move_r_leg_backward_full(); // Move a perna direita para trás
    move_r_foot_inicial_pos();  // Coloca o pé direito no chão

    move_all_initial();      // Retorna à posição base

    Serial.println("90 graus completa.");
    


    

}

void Feet::hello_all() {
    Serial.println("Executando hello_all() 3 vezes...");

    for (int i = 0; i < 9; i++) {  // Repete 3 vezes
        Serial.print("Execução número: "); Serial.println(i + 1);
        
        move_l_foot_down_full();  // Movimento correto
        move_l_foot_inicial_pos();

        delay(500);  // Pequena pausa para evitar sobrecarga mecânica
    }

    Serial.println("Finalizado hello_all() 3 vezes.");
}

//void Feet::move_sideway(){




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






