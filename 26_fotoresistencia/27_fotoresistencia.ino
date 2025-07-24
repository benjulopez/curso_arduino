#define FOTO_PIN 4
#define LED 2

int valorLuz = 0;
int valorLed = 0;

#define UMBRAL 2000


void setup() {
  Serial.begin(115200);
  pinMode(FOTO_PIN, INPUT);
  pinMode(LED, OUTPUT);

}

void loop() {
  valorLuz = analogRead(FOTO_PIN);
  valorLed = map(valorLuz, 0, 4096, 0, 255);
  // analogWrite(LED, valorLed);

  if(valorLuz > UMBRAL){
    digitalWrite(LED, HIGH);
  }
  else{
    digitalWrite(LED, LOW);
  }
  
  Serial.print(valorLuz);
  delay(200);

}
