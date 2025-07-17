#include <DHT.h>

#define DHTPIN 13
#define DHTTYPE DHT11
#define LED 15

DHT dht(DHTPIN, DHTTYPE);

float temp = 0.0;
float hume = 0.0;


//---------------------------------------------------------

void setup() {
  Serial.begin(115200);
  delay(1000);
  dht.begin();
  pinMode(LED, OUTPUT);

}

//---------------------------------------------------------

void loop() {
  
  temp = dht.readTemperature();
  hume = dht.readHumidity();
  
  digitalWrite(LED, HIGH);

  Serial.print("Temperatura: ");
  Serial.println(temp);

  Serial.println("Humedad: " + String(hume));
  
  digitalWrite(LED, LOW);

  delay(1000);

}