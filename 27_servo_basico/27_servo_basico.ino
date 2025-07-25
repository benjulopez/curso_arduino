#include <ESP32Servo.h>

#define pinServo 15  // pin donde hemos colocado el servomotor


// creo variable (manejador) del tipo Servo (definido en la libreria instalada arriba) para control del giro
Servo miServo;

void setup() {
  miServo.setPeriodHertz(50);  // servo estándar de 50 hz
  miServo.attach(pinServo, 500, 2500);  // pin de conexion y amplitud (min, max) de rango de giro, en milisegundos (ver tabla en manual)

}

void loop() {
  /*for(int i=0; i<=180; i++){  //giramos de 0 a 180 grados
    miServo.write(i);
    delay(20);
  }
  delay(3000);  //para antes de girar hacia atrás
  for(int i=180; i>=0; i--){  //giramos de 180 a 0 grados
    miServo.write(i);
    delay(20);  //para un poco entre cada giro
  }
  delay(3000);*/


  miServo.write(0);
  delay(2000);

  for(int i=0; i<=180; i+=45){  //giramos de 0 a 180 grados en tramos de 45 grados
    miServo.write(i);
    delay(1000);  //para un poco entre cada giro
  }
  delay(2000);  //para antes de girar hacia atrás
  for(int i=180; i>=0; i-=45){  //giramos de 180 a 0 grados en tramos de 45 grados
    miServo.write(i);
    delay(1000);  //para un poco entre cada giro
  }
  delay(3000);

}
