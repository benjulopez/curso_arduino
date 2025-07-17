int numeros[5];
int otro[] = {1,2,3,4,5};

void setup() {
  Serial.begin(115200);

  for (int i = 0; i < 5; i++) {
    numeros[i] = otro[i];
  }

  for (int j = 0; j < 5; j++) {
  Serial.print("Número: ");
  Serial.println(numeros[j]);
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}