#define PIN_LED 2
#define PIN_VERDE 12
int contador_encendidos = 0;

void setup() {
  Serial.begin(115200);
  pinMode(PIN_LED, OUTPUT);
  pinMode(PIN_VERDE, OUTPUT);
}

void loop() {
  digitalWrite(PIN_LED, HIGH);
  digitalWrite(PIN_VERDE, LOW);
  Serial.println("led azul encendido, verde apagado");
  /*contador_encendidos ++;
  Serial.print("Se ha encendido ");
  Serial.print(contador_encendidos);
  Serial.println(" veces.");*/
  delay(1000);
  digitalWrite(PIN_LED, LOW);
  digitalWrite(PIN_VERDE, HIGH);
    Serial.println("led azul apagado, verde encendido");
  delay(1000);
}
