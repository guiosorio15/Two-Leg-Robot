#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <Arduino.h>
#include <feet.h>

// Definição dos tempos e distância limite
#define TEMPO_PARAR 3000  // 15 segundos parado antes de tomar decisão
#define TEMPO_RODAR 5000   // Tempo a rodar antes de avançar novamente
#define DISTANCIA_LIMITE 30.0  // Distância limite para evitar colisão (cm)
#define TIME_BETWEEN_CYCLES 100 // Tempo entre ciclos da FSM

// Máquina de estados
typedef enum {
    AVANCAR,
    PARAR,
    RODAR
} state_t;

// Estrutura para armazenar o estado atual e o próximo estado
typedef struct {
    state_t state, new_state;
    unsigned long tis, tes;
} fsm_t;

Feet pes;
fsm_t state_machine;

unsigned long last_cycle = 0;
unsigned long tempo_inicio_estado = 0;

// **Converte o estado para string (para debug)**
const char* stateToString(state_t state) {
    switch (state) {
        case AVANCAR: return "AVANCAR";
        case PARAR: return "PARAR";
        case RODAR: return "RODAR";
        default: return "UNKNOWN";
    }
}

// **Define o novo estado**
void set_state(fsm_t& fsm, state_t new_state) {
    if (fsm.state != new_state) {
        Serial.println("--------------------------------------------------");
        Serial.print("Mudança de estado: "); Serial.print(stateToString(fsm.state));
        Serial.print(" → "); Serial.println(stateToString(new_state));
        Serial.println("--------------------------------------------------");

        fsm.state = new_state;
        fsm.tes = millis();
        fsm.tis = 0;
        tempo_inicio_estado = millis();  // Guarda o tempo em que entrou no estado

        if (new_state == PARAR) {
            pes.move_all_initial(); // Para todos os motores
        }
    }
}

void setup() {
    Serial.begin(9600);
    Wire.begin();
    pes.initialize_feet();
    pes.move_all_initial();
    delay(2000);

    Serial.println("Robô iniciado. Começando FSM...");

    state_machine.new_state = AVANCAR; // Começa a avançar automaticamente
    set_state(state_machine, state_machine.new_state);
}

void loop() {
    uint32_t now = millis();
    if (now - last_cycle > TIME_BETWEEN_CYCLES) {
        state_machine.tis += (now - last_cycle);
        last_cycle = now;

        // **Lê a distância do sensor**
        static float last_distance = DISTANCIA_LIMITE + 10; // Iniciar com um valor alto

        float distancia = pes.measure_distance();
        if (distancia == 0 || distancia < 2.0) {
            distancia = last_distance; // Usa a última leitura válida
        } else {
            last_distance = distancia; // Atualiza a última leitura válida
        }

        // **Verifica se os motores estão a ser chamados corretamente**
        if (state_machine.state == AVANCAR) {
            Serial.println("Executando: AVANCAR");
        } else if (state_machine.state == PARAR) {
            Serial.println("Executando: PARAR");
        } else if (state_machine.state == RODAR) {
            Serial.println("Executando: RODAR");
        }

        // **Transições de estado**
        if (state_machine.state == AVANCAR) {
            if (distancia > 0 && distancia <= DISTANCIA_LIMITE) {
                state_machine.new_state = PARAR;
            }
        } 
        else if (state_machine.state == PARAR) {
            if (distancia > DISTANCIA_LIMITE) {
                state_machine.new_state = AVANCAR;
            } else if ((millis() - tempo_inicio_estado) >= TEMPO_PARAR) { // Espera o tempo necessário
                state_machine.new_state = RODAR;
            }
        }

        else if (state_machine.state == RODAR) { 
                if (pes.measure_distance() > DISTANCIA_LIMITE) { // Só avança se a distância estiver OK
                    state_machine.new_state = AVANCAR;
                } else {
                    state_machine.new_state = RODAR; // Continua a rodar até estar livre
                }
            }
        }


        set_state(state_machine, state_machine.new_state);

        // **Execução dos estados**
        switch (state_machine.state) {
            case AVANCAR:
                pes.hello_all();
                //delay(2000);
                Serial.println("Iniciando movimento para frente...");
                //pes.walk_forward(); // Move para frente
                
                break;

            case PARAR:
                Serial.println("Robô parou.");
                pes.move_all_initial(); // Para completamente
                break;

            case RODAR:
                Serial.println("Rodando para evitar obstáculo...");
                pes.turn_right();
                //pes.hello_all();
 // Simula rotação lateral
                break;
        }
    
}