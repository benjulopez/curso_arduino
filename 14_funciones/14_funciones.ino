
void setup() {
  Serial.begin(115200);
  delay(1000);

  /*
  int numero = sumar(3, 2);
  Serial.println(numero);
  */

  /*
  int acumulador = 0;
  int valores[] = {5,15,7,9,22,9,3};
  for (int i = 0; i < 7; i++) {
  acumulador = sumar(acumulador, valores[i]);
  }
  Serial.print("Total: ");
  Serial.println(acumulador);
  */

  char cadena[] = "Hola mundo";
  int largo = longitudCadena(cadena);
  Serial.print("Longitud de la cadena: ");
  Serial.println(largo);

  /*
  int largo2 = longitudCadena("Esta cadena la escribo directamente en la llamada a la función");
  Serial.print("Longitud de la cadena 2: ");
  Serial.println(largo2);
  */

  char *resultado = invertirCadena(cadena);
  Serial.print("La cadena inversa es: ");
  Serial.println(resultado);

}

void loop() {
  // put your main code here, to run repeatedly:

}


// FUNCIONES
// formas de escribir los nombre de las funciones en lenguajes de programación
//camelCase (el que usaremos aquí)
//PascalCase
//snake_case

//Función que suma dos números
  int sumar(int num1, int num2){
  int temp = num1 + num2;
  return temp;
}

//Función que calcula la longitud de una cadena de texto
  int longitudCadena(char cadena[]){
    int i = 0;
    while(cadena[i] != '\0'){   // '\0' es el final de cadena
      i ++;
    }
    return i;
  }

//Función para dar la vuelta a una cadena de texto
  char *invertirCadena(char cadena[]){
    int longitud = longitudCadena(cadena);
    char temp[longitud];
    int j = 0;
    for(int i = longitud-1; i>=0; i--){
      temp[j] = cadena[i];
      j++;
    }
    temp[j] = '\0';
    return temp;
  }

