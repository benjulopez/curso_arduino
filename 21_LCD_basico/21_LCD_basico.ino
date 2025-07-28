// incluimos librerias necesarias
#include <LiquidCrystal_I2C.h>  // controlador LCD
#include <Wire.h>  // protocolo de comunicaciones I2C

// pines donde conectamos
#define SDA 22  // datos
#define SCL 23  // reloj
#define ADDR 0x27 // establecemos la dirección de memoria donde est-a conectado el display LCD.Otra es 0x3F (ver instrucciones del aparato)

// definimos variable (constructor) lcd, del tipo LiquidCrystal_I2C
LiquidCrystal_I2C lcd(ADDR, 16, 2); // variable_dir_memoria, columnas, filas

void setup() {

  Serial.begin(115200);
  delay(1000);

  Wire.begin(SDA, SCL);  // iindicamos a I2C los pines de datos y de reloj

  for(byte i=0; i<120; i++){
    Wire.beginTransmission(i);
    if(Wire.endTransmission()==0){
      Serial.print("Dirección encontrada");
      Serial.print(" 0x");
      Serial.print(i, HEX);
      delay(10);
    }
  }

  lcd.init();

  /*lcd.noBacklight();
  delay(500);
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);  // columna, fila
  lcd.print("Hola mundo");
  lcd.setCursor(0, 1);
  lcd.print("Saludos..."); */

}

void loop() {
    /*
  cd.display(); // muestra datos
  delay(500);
  lcd.noDisplay(); // borra datos
  delay(500);
  */
  
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0); // columna, fila
  lcd.print("Temp: 12.34");
  lcd.print(char(223)); // para imprimir el caracter de grado centrígrado
  lcd.print("C");
  lcd.setCursor(0, 1); // columna, fila
  lcd.print("Hum: 24%");
  delay(5000);


}
