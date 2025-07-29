#define PIN_X 13
#define PIN_Y 12
#define PIN_SW 14

// leds
#define LED_IZQ 4
#define LED_DER 15
#define LED_ARR 19
#define LED_ABA 5

int cero_x = 1915;
/* este es el valor que, según nos muestra el monitor serie,
es el valor que mi dispositivo en concreto marca como centro de x
(debería ser 2048 (rango de 0-4095), pero no es muy sensible) */

int cero_y = 1870;
/* este es el valor que, según nos muestra el monitor serie,
es el valor que mi dispositivo en concreto marca como centro de y
(debería ser 2048 (rango de 0-4095), pero no es muy sensible) */

void setup() {
  Serial.begin(115200); //iniciar monitor serie

  pinMode(PIN_X, INPUT);
  pinMode(PIN_Y, INPUT);
  pinMode(PIN_SW, INPUT_PULLUP);

  pinMode(LED_IZQ,OUTPUT);
  pinMode(LED_DER,OUTPUT);
  pinMode(LED_ARR,OUTPUT);
  pinMode(LED_ABA,OUTPUT);

}

void loop() {
  int valor_x = analogRead(PIN_X);
  int valor_y = analogRead(PIN_Y);
  int valor_sw = digitalRead(PIN_SW);

  /*Serial.print("X, Y, SW: ");
  Serial.print(String(valor_x) + ", ");
  Serial.print(String(valor_y) + ", ");
  Serial.println(String(valor_sw));*/

  digitalWrite(LED_DER, LOW);
  digitalWrite(LED_IZQ, LOW);
  digitalWrite(LED_ARR, LOW);
  digitalWrite(LED_ABA, LOW);

  if (valor_x - cero_x < -10){
    Serial.println("Izquierda: " + String(valor_x - cero_x));
    digitalWrite(LED_IZQ, HIGH);
  }
  
  if (valor_x - cero_x > 10){
    Serial.println("Derecha: " + String(valor_x - cero_x));
    digitalWrite(LED_DER, HIGH);
  }
  
    if (valor_y - cero_y < -10){
    Serial.println("Arriba: " + String(valor_y - cero_y));
    digitalWrite(LED_ARR, HIGH);
  }
  
  if (valor_y - cero_y > 10){
    Serial.println("Abajo: " + String(valor_y - cero_y));
    digitalWrite(LED_ABA, HIGH);
  }

  if (valor_sw == 0){
    digitalWrite(LED_DER, HIGH);
    digitalWrite(LED_IZQ, HIGH);
    digitalWrite(LED_ARR, HIGH);
    digitalWrite(LED_ABA, HIGH);
  }

  delay(100);

}
