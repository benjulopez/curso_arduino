#define POTLED 4
#define LED 13

#define POTZUM 14
#define ZUMBA 5


int valorPotled = 0;  // el rango del potenciómetro va de 0 a 4095
int valorLed = 0;  // el rango del led va de 0 a 255

int valorPotzum = 0;  // el rango del potenciómetro va de 0 a 4095
int valorZumba = 0;  // el rango del zumbador va de 0 a 255

void setup() {
  Serial.begin(115200);

  pinMode(LED, OUTPUT);
  pinMode(POTLED, INPUT);

  pinMode(ZUMBA, OUTPUT);
  pinMode(POTZUM, INPUT);

}

void loop() {
  valorPotled = analogRead(POTLED);
  valorLed = map(valorPotled,0,4095,0,255); // convertimos el valor del potenciómetro al valor del led
  analogWrite(LED, valorLed);

  //escribimos en monitor serie el valor de POT para ir viéndolo
  Serial.print("Valor de POTLED= " + String(valorPotled) + " , ");

  //escribimos en monitor serie el valor de LED para ir viéndolo
  Serial.println("Valor de LED= " + String(valorLed));


//----------------------------------------------------------------

  valorPotzum = analogRead(POTZUM);
  digitalWrite(ZUMBA, HIGH);
  delay(valorPotzum);
  digitalWrite(ZUMBA, LOW);
  delay(valorPotzum);

  //escribimos en monitor serie el valor de POT para ir viéndolo
  Serial.print("Valor de POTZUM= " + String(valorPotzum));

  //delay(500);

}
