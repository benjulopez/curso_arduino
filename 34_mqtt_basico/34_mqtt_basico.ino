#include <WiFi.h>  // conexion wifi
#include <PubSubClient.h>  //publicador-subcriptor

// WIFI ----------------
char* ssid = "Aula 1";  // nombre wifi de clase
char* pwd = "Horus.2025";  // clave

// MQTT ----------------
char* mqtt_server = "192.168.0.25";  // servidor web
int mqtt_port = 1883;  // puerto de conexión al servidor

WiFiClient espClient;
PubSubClient client(espClient);

char* mqtt_topic_sub = "curso_arduino/#";  // topic del mqtt al que me voy a suscribir, de donde recojo los datos
char* mqtt_topic_pub = "curso_arduino/miguel";  // topic del mqtt en el que voy a publicar, es decir, donde enviar los datos
char* mqtt_client_id = "ESP_Miguel";  // identificacion del cliente, en nuestro caso, nuestro Arduino

static unsigned long lastMsg = 0;
unsigned long now;

// ---------------------

String miMensaje = "Te quiero mucho, le dijo la trucha al trucho";


void setup() {
  Serial.begin(115200);  // inicializar monitor serie

  // conexión wifi
  WiFi.begin(ssid, pwd);  // inicializar wifi

  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }

  Serial.print("\n");
  Serial.print("Conectado a: ");
  Serial.println(WiFi.localIP());

  // MQTT
  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback); // llama a una función, a la que llamamos "callback" (la podemos llamar como queramos)

}

void loop() {
  if(!client.connected()){
    reconnect();
  }
  client.loop();

  if(Serial.available() > 0){
    miMensaje = Serial.readStringUntil('\n');
    miMensaje.trim();
  }

  now = millis();  // fecha-hora actual en milisegundos
  if(now - lastMsg > 10000){  // si han pasado más de 10 segundos (fecha-hora actual menos fecha-hora en que se envió el mensaje)
    lastMsg = now;  // guardamos la fecha-hora en la que enviamos el mensaje
    //String mensaje = miMensaje;
    client.publish(mqtt_topic_pub, miMensaje.c_str());
    Serial.println("Mensaje enviado: " + miMensaje);
  }

}

//// FUNCIONES ////

// Función callback
void callback(char* topic, byte* payload, unsigned int length){  // topic, mensaje, longitud del mensaje
  Serial.print("Mensaje recibido en: [");
  Serial.print(topic);
  Serial.print("]: ");
  for(int i=0; i<length; i++){
    Serial.print((char)payload[i]);
  }
  Serial.println();
}

// Función reconnect
void reconnect(){
  while(!client.connected()){
    Serial.println("Reconectando ...");
    if(client.connect(mqtt_client_id)){
      Serial.println("Conectado a MQTT");
      client.subscribe(mqtt_topic_sub);  // si conecto, me suscribo al topic previamente indicado
    }
    else{
      Serial.println("Fallo en la conexión");
      Serial.println("Error: " + client.state());
      delay(500);
    }
  }
}
