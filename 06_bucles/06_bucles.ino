void setup() {
  Serial.begin(115200);
  delay(500);

  // BUCLES controlados por un contador:

  // for (inicio; fin; paso){}
  /*for (int i=0; i<10; i++) {
  Serial.print("Número: ");
  Serial.println(i);
  }*/
  
  /*for(int i=0; i<=100; i=i+2){  //también podría ponerse como i+=2
    Serial.print("Número: ");
    Serial.println(i);
  }*/

  /*for(int i=100; i>00; i--){
    Serial.println("Número: " + String(i));
  }*/

//--------------------------------------------------------------------

//BUCLES en 2 dimensiones (anidados) (tablas)

String salida = "";
for(int fila=0; fila<10; fila++){
  for(int col=0; col<10; col++){
    //Serial.print(String(fila) + " : " + String(col) + "\t");
    salida += String(fila) + " : " + String(col) + "\t";
  }
  //Serial.print("\n");
  salida += "\n";
}
  Serial.print(salida);

}

void loop() {
  // put your main code here, to run repeatedly:

}
