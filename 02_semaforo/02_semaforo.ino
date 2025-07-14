#define PIN_ROJO 12
#define PIN_VERDE 13
#define PIN_AZUL 25

void setup() {
 pinMode(PIN_ROJO, OUTPUT);
 pinMode(PIN_VERDE, OUTPUT);
 pinMode(PIN_AZUL, OUTPUT);
 Serial.begin(115200); //conectamos con monitor serie a velocidad de 115200
}

void loop() {
  //ROJO encendido
   digitalWrite(PIN_ROJO, HIGH);
   digitalWrite(PIN_VERDE, LOW);
   digitalWrite(PIN_AZUL, LOW);
   Serial.println("led rojo encendido, verde y azul apagados");
   delay(2000);
  
  //VERDE encendido
   digitalWrite(PIN_ROJO, LOW);
   digitalWrite(PIN_VERDE, HIGH);
   digitalWrite(PIN_AZUL, LOW);
   Serial.print("led verde encendido, rojo y azul apagados \n"); //aqui pruebo salto de linea manual \n
   delay(2000);

  //AZUL encendido
   digitalWrite(PIN_ROJO, LOW);
   digitalWrite(PIN_VERDE, LOW);
   digitalWrite(PIN_AZUL, HIGH);
   Serial.println("led azul encendido, verde y rojo apagados");
   delay(2000);
}