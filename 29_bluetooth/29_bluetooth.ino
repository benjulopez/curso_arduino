#include <BluetoothSerial.h>

BluetoothSerial serialBT;  // variable que llamamos serialBT, de tipo BluetoothSerial

void setup() {
  Serial.begin(115200);
  serialBT.begin("BT_Miguel_Angel"); // iniciamos disp. bluetooth y dedamos un nombre
  Serial.println("Dispositivo listo para emparejarse");

}

void loop() {
  if(Serial.available()){
    serialBT.write(Serial.read());
  }
  if(serialBT.available()){
    Serial.write(serialBT.read());
  }
  

}
