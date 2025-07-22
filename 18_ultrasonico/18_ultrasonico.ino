#define TRIG 13  // definimos pin donde conectamos la patilla triger
#define ECHO 14  // definimos pin donde conectamos la patilla echo
#define MAX_DIST 700  // definimos distancia maxima en cm
#define LED 15
#define BUZZER 4

float distancia = 0.0;
float timeOut = MAX_DIST * 60; // tiempo maximo de espera a recibir el eco
int velSonido = 343;  //velocidad del sonido en m/s
int  valorLed = 0;
int intervalos[] = {10,20,30,40,50,60,70,80,90,100}; // definimos un array de intervalos para establecer luego la frecuencia de pitidos del zumbador


void setup() {
  Serial.begin(115200);
  pinMode(TRIG, OUTPUT);  // establecemos TRIG como salida
  pinMode(ECHO, INPUT);  // establecemos ECHO como entrada
  pinMode(LED, OUTPUT);  //establecemos LED como salida
  pinMode(BUZZER, OUTPUT);  //establecemos BUZZER como salida

}

void loop() {
  int umbral;
  distancia = getSonar();
  umbral = getIntervalo(distancia);
  if(umbral <= 100){
    pitar(umbral);
  }
  valorLed = map(distancia,0,300,255,0);  //mapeamos para convertir los rangos
  analogWrite(LED, valorLed);
  Serial.println("Distancia: " + String(distancia) + " cm");
  delay(500);

}


////// FUNCIONES //////

// funcion para calcular la distancia medida por el sensor de ultrasonidos
float getSonar (){
  unsigned long int pingTime = 0; //en esta variable guardamos los datos recibidos desde el sensor de ultrasonidos
  float dist = 0.0; // esta variable la usamos para calcular y devolver la distancia

  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);

  pingTime = pulseIn(ECHO, HIGH, timeOut);
  Serial.println("pingTime: " + String(pingTime));  // provisional, para pruebas

  // Calcular la distancia en centímetros usando la fórmula: distancia = velocidad * tiempo / 2
  // La velocidad del sonido es aproximadamente 343 metros por segundo o 0.0343 (343/10000) centímetros por microsegundo
  dist = (float) pingTime * velSonido / 10000 / 2;  // con (float) nos aseguramos que el resultado de la operación será del tipo float
  return dist;  // en cm
}


// funcion para que el zumbador pite mas lento cuanto mayor es la distancia
int getIntervalo (float lejos){
  int salida = 1000;  // le asignamos un avalor inicial alto para que comience sin pitar
  for(int i = 0; i < 10; i++){  // con este bucle recorremos el array intervalos
    if(lejos < intervalos[i]){  // vemos en qué rango se encuentra
      salida = intervalos[i];  //asignamos el valor de ese rango a la variable de salida
      break;  // salimos del bucle
    }
  }
  return salida;
}


// funcion para controlar la frecuencia de pitidos del zumbrador
void pitar(int umbral){
  for(int i = 0; i < 5; i++){
    digitalWrite(BUZZER, HIGH);
    delay(50);
    digitalWrite(BUZZER, LOW);
    delay(10*umbral);
  }
}

