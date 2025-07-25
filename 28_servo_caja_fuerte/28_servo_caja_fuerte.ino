#include <ESP32Servo.h>

#define pinServo 15  // pin donde he colocado el servomotor

// creo variable (manejador) del tipo Servo (definido en la libreria instalada arriba) para control del giro
Servo miServo;

String entrada="";  //creo variable para guardar entrada del monitor serie
String secreto="1234";  //creo variable para guardar la clave

bool primeraVez=true;  // variable centinela


void setup() {

  Serial.begin(115200);

  miServo.setPeriodHertz(50);  // servo estándar de 50 hz
  miServo.attach(pinServo, 500, 2500);  // pin de conexion y amplitud (min, max) de rango de giro, en milisegundos (ver tabla en manual)

  miServo.write(0);  // establezco posición de partida

}

void loop() {
  //limpiarPantalla();
  // esto es para que muestre el mensaje al principio
  if (primeraVez){  // equivale a poner "if primeraVez==true"
    Serial.println("Introduzca la clave:");
    primeraVez=false;
  }

  if(Serial.available()>0){
    entrada=Serial.readStringUntil('\n');  // leer hasta que se le dé a intro
    entrada.trim();  //elimina los espacios por delante y por detrás (ojo, incluido el \n del final)
    if(entrada==secreto){
      Serial.println("Clave correcta");
      Serial.println("Puerta abriéndose");
      // miServo.write(180);
      for(int i=0; i<=180; i++){
        miServo.write(i);
        delay(20);
      }
      Serial.println("Puerta abierta");
      delay(5000);
      Serial.println("Puerta cerrándose");
      // miServo.write(0);
      for(int i=180; i>=0; i--){
        miServo.write(i);
        delay(20);
      }
      Serial.println("Puerta cerrada");
    }
    else{
      Serial.println("Clave incorrecta. Pruebe otra vez");
    }
    //limpiarPantalla();
    Serial.println("Introduzca la clave:");
  }

}

//// ESTA FUNCION NO VA BIEN, PENDIENTE DE REVISAR ////
/*void limpiarPantalla(){  
  Serial.write(char(27)); // comando ESC
  Serial.print("[2J");  // comando para borrar la pantalla
  Serial.write(char(27));  // comando ESC
  Serial.print("[H");  // comando para mover el cursor a la posición inicial
}*/
