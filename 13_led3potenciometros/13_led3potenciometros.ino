#define LED_R 12
#define LED_V 14
#define LED_A 27

#define POT_R 4
#define POT_V 2
#define POT_A 15

int led_r, led_v, led_a;
int pot_r, pot_v, pot_a;


void setup() {
  pinMode(LED_R, OUTPUT);
  pinMode(LED_V, OUTPUT);
  pinMode(LED_A, OUTPUT);

  pinMode(POT_R, INPUT);
  pinMode(POT_V, INPUT);
  pinMode(POT_A, INPUT);

}

void loop() {
  pot_r = analogRead(POT_R);
  led_r = map(pot_r, 0, 4096, 255, 0);  // convertimos el valor del potenciómetro al valor del led
  analogWrite(LED_R, led_r);

  pot_v = analogRead(POT_V);
  led_v = map(pot_v, 0, 4096, 255, 0);  // convertimos el valor del potenciómetro al valor del led
  analogWrite(LED_V, led_v);

  pot_a = analogRead(POT_A);
  led_a = map(pot_a, 0, 4096, 255, 0);  // convertimos el valor del potenciómetro al valor del led
  analogWrite(LED_A, led_a);


}
