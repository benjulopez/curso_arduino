#define VELOCIDAD 14  // enable 1,2
#define DIRPIN_1 12  // input 1
#define DIRPIN_2 13  // input 2

//estados
#define PARO 0
#define DERECHA 1
#define IZQUIERDA 2 

//diodos leds
#define LED_VERDE 15
#define LED_ROJO 0
#define LED_AZUL 2

//potenciometro
#define POT 32

void setup() {
  Serial.begin(115200);
  delay(200);

  pinMode(VELOCIDAD, OUTPUT);  // con este controlamos velocidad
  pinMode(DIRPIN_1, OUTPUT);  // con la combinación de éstos controlamos la dirección
  pinMode(DIRPIN_2, OUTPUT);

  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_ROJO, OUTPUT);
  pinMode(LED_AZUL, OUTPUT);

  pinMode(POT, OUTPUT);

}

void loop() {
  cambioEstado(DERECHA);
  delay(5000);

  cambioEstado(PARO);
  delay(3000);
  
  cambioEstado(IZQUIERDA);
  delay(5000);

  cambioEstado(PARO);
  delay(3000);  
}


//// FUNCIONES ////

void cambioEstado(int estadoNuevo){
  switch(estadoNuevo){
    case PARO:
      Serial.println("Motor parado");
      //digitalWrite(VELOCIDAD, LOW);  // apagamos el motor
      analogWrite(VELOCIDAD, 0);  // apagamos el motor
      digitalWrite(LED_ROJO, HIGH);
      digitalWrite(LED_VERDE, LOW);
      digitalWrite(LED_AZUL, LOW);
      break;
    case IZQUIERDA:
      Serial.println("Girando en un sentido");
      //digitalWrite(VELOCIDAD, LOW);  // apagamos el motor
      analogWrite(VELOCIDAD, leerPot());  // establecemos velocidad de giro, hasta 255. En nuestro caso no arranca con menos de 70
      digitalWrite(DIRPIN_1, 0);
      digitalWrite(DIRPIN_2, 1);
      digitalWrite(LED_ROJO, LOW);
      digitalWrite(LED_VERDE, HIGH);
      digitalWrite(LED_AZUL, LOW);
      break;
    case DERECHA:
      Serial.println("Girando en el otro sentido");
      //digitalWrite(VELOCIDAD, LOW);  // apagamos el motor
      analogWrite(VELOCIDAD, leerPot());  // establecemos velocidad de giro, hasta 255. En nuestro caso no arranca con menos de 70
      digitalWrite(DIRPIN_1, 1);
      digitalWrite(DIRPIN_2, 0);
      digitalWrite(LED_ROJO, LOW);
      digitalWrite(LED_VERDE, LOW);
      digitalWrite(LED_AZUL, HIGH);
      break;
    }
  }

  int leerPot(){
    int valorPot = 0;
    int valorVel = 0;

    valorPot=analogRead(POT);
    valorVel=map(valorPot,0,4096,80,255);

    Serial.println("Velocidad: " + String(valorVel));
    return valorVel;
  }

