#include <ESP32Servo.h>
#include <BluetoothSerial.h>

BluetoothSerial serialBT;  // variable que llamamos serialBT, de tipo BluetoothSerial

#define pinServo 15  // pin donde he colocado el servomotor
#define ROJO 13
#define VERDE 14

// creo variable (manejador) del tipo Servo (definido en la libreria instalada arriba) para control del giro
Servo miServo;

String entrada="";  //creo variable para guardar entrada del monitor serie
String secreto="1234";  //creo variable para guardar la clave

bool primeraVez=true;  // variable centinela


void setup() {

  pinMode(ROJO, OUTPUT);
  pinMode(VERDE, OUTPUT);

  Serial.begin(115200);
  serialBT.begin("BT_Caja_MAngel"); // iniciamos disp. bluetooth y dedamos un nombre
  Serial.println("Dispositivo listo para emparejarse");

  miServo.setPeriodHertz(50);  // servo estándar de 50 hz
  miServo.attach(pinServo, 500, 2500);  // pin de conexion y amplitud (min, max) de rango de giro, en milisegundos (ver tabla en manual)

  miServo.write(0);  // establezco posición de partida

}

void loop() {
  digitalWrite(ROJO, LOW);
  digitalWrite(VERDE, LOW);
  // esto es para que muestre el mensaje al principio
  if (primeraVez){  // equivale a poner "if primeraVez==true"
    serialBT.println("Introduzca la clave:");
    primeraVez=false;
  }

  if(serialBT.available()>0){
    entrada=serialBT.readStringUntil('\n');  // leer hasta que se le dé a intro
    entrada.trim();  //elimina los espacios por delante y por detrás (ojo, incluido el \n del final)
    if(entrada==secreto){
      serialBT.println("Clave correcta");
      serialBT.println("Puerta abriéndose");
      digitalWrite(ROJO, HIGH);
      for(int i=0; i<=180; i++){
        miServo.write(i);
        delay(20);
      }
      serialBT.println("Puerta abierta");
      digitalWrite(ROJO, LOW);
      digitalWrite(VERDE, HIGH);
      delay(5000);
      serialBT.println("Puerta cerrándose");
      digitalWrite(ROJO, HIGH);
      digitalWrite(VERDE, LOW);
      for(int i=180; i>=0; i--){
        miServo.write(i);
        delay(20);
      }
      serialBT.println("Puerta cerrada");
    }
    else{
      serialBT.println("Clave incorrecta. Pruebe otra vez");
    }
    serialBT.println("Introduzca la clave:");
  }

}

