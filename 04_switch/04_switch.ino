int dia = 7;
String nombreDia = "";

void setup() {
  Serial.begin(115200);

  switch (dia) {
  case 1:
    nombreDia = "lunes";
    break;
  case 2:
   nombreDia = "martes";
   break;
  case 3:
    nombreDia = "miércoles";
    break;
  case 4:
    nombreDia = "jueves";
    break;
  case 5:
    nombreDia = "viernes";
    break;
  case 6:
    nombreDia = "sábado";
    break; 
  case 7:
    nombreDia = "domingo";
    break; 
  }

Serial.println("El día es "+ nombreDia);

// ---------------------------------------------------------------

int nota = 3;
String calif = "";

switch (nota) {
case 0:
case 1:
case 2:
case 3:
case 4:
  calif = "SUSPENSO";
  break;
case 5 ... 6:
  calif = "APROBADO";
  break;
case 7 ... 8:
  calif = "NOTABLE";
  break;
default:
  calif = "SOBRESALIENTE";
}

if (nota >= 0 && nota <= 10){}
Serial.println("La calificación es: " + calif);
}
else{
  Serial.println("Error en la calificación")
}

}

void loop() {
  // put your main code here, to run repeatedly:

}
