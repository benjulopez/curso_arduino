#include <DHT.h>

// Pin del DHT22 y del ventilador
#define DHTPIN 4
#define DHTTYPE DHT11
#define FAN_PIN 12

// Objeto DHT
DHT dht(DHTPIN, DHTTYPE);

// Variables compartidas --------
float temperature = 0.0;

// Mutex (mutuamente excluyentes, tambien denominados semáforos) para proteger acceso a las variables compartidas
SemaphoreHandle_t tempMutex;

//--------------------------------

// Tarea 1: Lee el sensor de temperatura
void readTemperatureTask(void *pvParameters) {
  while (true) {
    float temp = dht.readTemperature();
    Serial.print("Temperatura actual: ");
    Serial.println((String) temp);
    if (!isnan(temp)) {
      xSemaphoreTake(tempMutex, portMAX_DELAY); //reservamos las variables globales, para evitar que no se usen al mismo tiempo por otros hilos
      temperature = temp;
      xSemaphoreGive(tempMutex); //liberamos las variables, para que puedan ser utilizadas por otros hilos
    }
    vTaskDelay(pdMS_TO_TICKS(2000));  // cada 2 segundos
  }
}

// Tarea 2: Controla el ventilador
void fanControlTask(void *pvParameters) {
  const float threshold = 27.0;  // temperatura umbral

  while (true) {
    xSemaphoreTake(tempMutex, portMAX_DELAY);
    float currentTemp = temperature;
    xSemaphoreGive(tempMutex);

    if (currentTemp >= threshold) {
      digitalWrite(FAN_PIN, HIGH);  // encender ventilador
    } else {
      digitalWrite(FAN_PIN, LOW);   // apagar ventilador
    }

    vTaskDelay(pdMS_TO_TICKS(1000));  // revisar cada 1 segundo
  }
}

void setup() {
  Serial.begin(115200);
  dht.begin();

  pinMode(FAN_PIN, OUTPUT);
  digitalWrite(FAN_PIN, LOW);

  tempMutex = xSemaphoreCreateMutex();

  // Crear tareas
  xTaskCreatePinnedToCore(readTemperatureTask, "ReadTemp", 2048, NULL, 1, NULL, 0);
  xTaskCreatePinnedToCore(fanControlTask, "FanControl", 2048, NULL, 1, NULL, 1);
}

void loop() {
  // No necesitamos usarlo en este ejercicio, pero Arduino debe tener obligatoriamente ea función interna, al igual que la de Setup 
}