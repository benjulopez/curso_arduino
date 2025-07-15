#define LED 2
#define ZUMBADOR 15

void setup() {
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
  pinMode(ZUMBADOR, OUTPUT);

}

int tiempoEncendido=20;
int tiempoApagado=200;
void loop() {
  int tiempoEncendido=20;
  for (int i=0; i<10; i++) {
  digitalWrite(LED, HIGH);
  digitalWrite(ZUMBADOR, HIGH);
  delay(tiempoEncendido);
  tiempoEncendido += i * 10;
  digitalWrite(LED, LOW);
  digitalWrite(ZUMBADOR, LOW);
  delay(tiempoApagado);
  }

}
