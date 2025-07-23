#include <WiFi.h>
#include <WebServer.h>

#define LED 2

char* ssid="Aula 1"; //nombre de la red wifi
char* pwd="Horus.2025"; //clave rel wifi

WebServer servidor(80); //establece puerto de conexión en la variable "servidor" del tipo "WebServer"

// Páginas
String home="<!DOCTYPE html><html lang=\"es\"><head><meta charset=\"UTF-8\"><meta name=\"viewport\" content=\"width=device-width,initial-scale=1\"><title>Pagina Arduino MABL</title></head><body><h1>Hola Mundo</h1><h2>Página de prueba MABL para Arduino</h2><a href=\"/segunda\">Ir a la segunda página</a></body></html>";
// metemos el código de la web en la variable "home"
// tiene que estar minificado, es decir, sin espacios ni tabuladores, todo de corrido
// ojo con las comillas dentro del código html: hay que "escaparlas" para que no se confundan con las de apertura y cierre de String
// para ello las sustituimos por \", es decir, las comillas son literales

String segunda="<!DOCTYPE html><html lang=\"es\"><head><meta charset=\"UTF-8\"><meta name=\"viewport\" content=\"width=device-width,initial-scale=1\"><title>Segunda página</title></head><body><h1>Esta es la segunda página</h1></body></html>";

String pinON="<!DOCTYPE html><html lang=\"en\"><head><meta charset=\"UTF-8\"><meta name=\"viewport\" content=\"width=device-width,initial-scale=1\"><title>led ON</title></head><body><h1>led ON</h1></body></html>";

String pinOFF="<!DOCTYPE html><html lang=\"en\"><head><meta charset=\"UTF-8\"><meta name=\"viewport\" content=\"width=device-width,initial-scale=1\"><title>led OFF</title></head><body><h1>led OFF</h1></body></html>";

void setup() {
  Serial.begin(115200);  //activar monitor serie
  
  //////// CONEXION AL WIFI ////////
  WiFi.mode(WIFI_STA); //modo de conectarnos al wifi STA=Wifi Station, cliente wifi
  WiFi.begin(ssid, pwd); //conexión con nombre y clave indicados en variables
  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.print("\n");
  Serial.print("Conectado a la IP: ");
  Serial.println(WiFi.localIP());

  ////// SERVIDOR WEB //////
  servidor.begin();
  Serial.println("Servidor Web iniciado");

  ////// SOLICITUDES WEB //////
  servidor.on("/", handle_OnConnect); //"handle_OnConnect" puede ser cualquier otro nombre que nosotros queramos
  // cuando alguien llame a la página, en este caso "\" (página raiz), llama a la función "handle_OnConnect"

  servidor.on("/segunda", handle_Segunda);

  servidor.on("/led_on", handle_encenderLed);

  servidor.on("/led_off", handle_apagarLed);

  ////// LED //////
  pinMode(LED, OUTPUT);

}

void loop() {
  servidor.handleClient(); //esta pendiente de una peticion de la web

}

////// FUNCIONES //////////////////////////////////

// Función que devuelve una página html //
void handle_OnConnect(){
  servidor.send(200, "text/html", home);
}
void handle_Segunda(){
  servidor.send(200, "text/html", segunda);
}

void handle_encenderLed(){
  digitalWrite(LED, HIGH);
  servidor.send(200, "text/html", pinON);
}

void handle_apagarLed(){
  digitalWrite(LED, LOW);
  servidor.send(200, "text/html", pinOFF);
}
