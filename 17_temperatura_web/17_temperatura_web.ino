#include <DHT.h>  // llamo a la libreria del sensor DTH de temperatura y humedad
#include <WiFi.h>  // llamo a la libreriad del conector Wifi integrado en Arduino
#include <HTTPClient.h>  // lamo a la libreria de conexión con cliente web

#define DHTPIN 13       //defino el pin donde lo conecto
#define DHTTYPE DHT11   //defino tipo de DTH

DHT miSensor(DHTPIN, DHT11);

// creo variables para guardar los datps
float temp = 0.0;
float hum = 0.0;

// conexión a internet
WiFiClient clienteWifi;  // variable para gestionar un cliente wifi: tipo_variable + nombre_variable
HTTPClient http;          // variable para gestionar un cliente http: tipo_variable + nombre_variable

//char * servidor = "http://192.168.0.25:5000/datos";  // servidor web en ordenador de Teo   IP:puerto/servicio
char * servidor = "http://192.168.0.60:5000/datos";  // servidor web en mi ordenado  IP:puerto/servicio


//datos de la conexión WIFI de clase
char * ssid = "Aula 1";   // nombre de la red
char * pwd = "Horus.2025"; // contraseña



void setup() {
  // arrancamps el monitor serie
  Serial.begin(115200);

  // arrancamos el sensor DHT, con el nombre que le hemos dado nosotros
  miSensor.begin();

  // arrancamos el Wifi en la red y con la contraseña indicados antes
  WiFi.begin(ssid, pwd);

  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.print("Conectado a la IP: ");
  Serial.println(WiFi.localIP());
  delay(2000);

}


void loop() {
  // recojo los datos de temperatura y humedad
  temp = miSensor.readTemperature();
  hum = miSensor.readHumidity();

  // muestromlos datos en monitor serie
  // Serial.println("La temperatura actual es: " + String(temp));
  // Serial.println("La humedad actual es: " + String(hum));

  // y envío los datos al servidor web
  postData(temp, hum, "Miguel Ángel local"); 

  delay(5000);

}

/*
creamos una función, que llamamos postData, para enviar los datos al servidor a traves de POST
temp, hum y persona son las variables definidas en el servidor
(no confundir con las que hemos creado nosotros en el loop)
*/

void postData(float t, float h, String per){
  String parametros = "temp=" + String(t) + "&hum=" + String(h) + "&persona=" + per;
  int httpCode;
  String payLoad;

  if(WiFi.status() == WL_CONNECTED){
    http.begin(clienteWifi, servidor);
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");
    http.POST(parametros);
    httpCode = http.POST(parametros);
    payLoad = http.getString();
    
    Serial.print("HTTP Code: ");
    Serial.println(httpCode);
    Serial.print("Mensaje: ");
    Serial.println(payLoad);
    
  }
}
