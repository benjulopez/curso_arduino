// incluimos librerias necesarias
#include <LiquidCrystal_I2C.h>  // controlador LCD
#include <Wire.h>  // protocolo de comunicaciones I2C

// pines donde conectamos
#define SDA 13  // datos
#define SCL 14  // reloj
#define ADDR 0x27 // establecemos la dirección de memoria donde est-a conectado el display LCD.Otra es 0x3F (ver instrucciones del aparato)

// definimos variable (constructor) lcd, del tipo LiquidCrystal_I2C
LiquidCrystal_I2C lcd(ADDR, 16, 2); // variable_dir_memoria, columnas, filas

void setup() {

  Wire.begin(SDA, SCL);  // iindicamos a I2C los pines de datos y de reloj
  lcd.init();

}

void loop() {
  
  lcd.backlight();
    
  for(int i=0; i<15; i++){
    lcd.clear();
    lcd.setCursor(i, 0); // columna, fila
    lcd.print("Hola");
    delay(500);
    }
  
}
