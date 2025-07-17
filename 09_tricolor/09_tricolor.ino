#define ROJO 12
#define VERDE 13
#define AZUL 14

// -----------------------------------

void setup() {
  pinMode(ROJO, OUTPUT);
  pinMode(VERDE, OUTPUT);
  pinMode(AZUL, OUTPUT);

}

// -----------------------------------

void loop() {

 /*  // Encendido ROJO
  digitalWrite(ROJO, LOW);
  digitalWrite(VERDE, HIGH);
  digitalWrite(AZUL, HIGH);

  delay(500);

  // Encendido VERDE
  digitalWrite(ROJO, HIGH);
  digitalWrite(VERDE, LOW);
  digitalWrite(AZUL, HIGH);

  delay(500);

  // Encendido AZUL
  digitalWrite(ROJO, HIGH);
  digitalWrite(VERDE, HIGH);
  digitalWrite(AZUL, LOW);

  delay(500);

   // Encendido MAGENTA
  digitalWrite(ROJO, LOW);
  digitalWrite(VERDE, HIGH);
  digitalWrite(AZUL, LOW);

  delay(500);
  
   // Encendido CYAN
  digitalWrite(ROJO, HIGH);
  digitalWrite(VERDE, LOW);
  digitalWrite(AZUL, LOW);

  delay(500);

  // Encendido AMARILLO
  digitalWrite(ROJO, LOW);
  digitalWrite(VERDE, LOW);
  digitalWrite(AZUL, HIGH);

  delay(500);

  // Encendido BLANCO
  digitalWrite(ROJO, LOW);
  digitalWrite(VERDE, LOW);
  digitalWrite(AZUL, LOW);

  delay(500);

  // Encendido NEGRO
  digitalWrite(ROJO, HIGH);
  digitalWrite(VERDE, HIGH);
  digitalWrite(AZUL, HIGH);

  delay(500); */

  int r = 0;
  int g = 0;
  int b = 0;
  
  // vamos a realizar un bucle
  
for (;;) {
r = random(0,255);
g = random(0,255);
b = random(0,255);

analogWrite(ROJO, r);
analogWrite(VERDE, g);
analogWrite(AZUL, b);

delay(1000);
}
}
