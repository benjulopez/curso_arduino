// incluimos librerias necesarias
#include <LiquidCrystal_I2C.h>  // controlador LCD
#include <Wire.h>  // protocolo de comunicaciones I2C
#include <DHT.h>  // sensor temperatura y humedad

// pines donde conectamos
#define SDA 13  // datos
#define SCL 14  // reloj
#define ADDR 0x27 // establecemos la dirección de memoria donde est-a conectado el display LCD.Otra es 0x3F (ver instrucciones del aparato)

#define DHTPIN 15  // sensor temp hum
#define DHTTYPE DHT11

// definimos variable (constructor) lcd, del tipo LiquidCrystal_I2C
LiquidCrystal_I2C lcd(ADDR, 16, 2); // variable_dir_memoria, columnas, filas

DHT dht(DHTPIN, DHTTYPE);

float temp = 0.0;
float hume = 0.0;

// --------------------------------------------------

void setup() {
  Wire.begin(SDA, SCL);  // iindicamos a I2C los pines de datos y de reloj
  lcd.init();
  lcd.backlight();
  lcd.clear();
  dht.begin();

}

//---------------------------------------------------

void loop() {
  temp = dht.readTemperature();
  hume = dht.readHumidity();

  lcd.setCursor(0, 0); // columna, fila
  lcd.print("temp: ");
  lcd.print(temp);
  lcd.print(char(223));
  lcd.print("C");
  lcd.setCursor(0, 1); // columna, fila
  lcd.print("hum: "); // también podría ser lcd.print("hum: " + string(hum));
  lcd.print(hume);
  lcd.print("%");
  delay(500);

}
