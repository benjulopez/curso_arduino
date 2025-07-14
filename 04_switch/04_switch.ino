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

Serial.print("El día es "+ nombreDia);

}

void loop() {
  // put your main code here, to run repeatedly:

}
