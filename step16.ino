//PWM을 활용하여 lED 온/오프 동작
#define LED_R_PIN 9
#define LED_G_PIN 10
#define LED_B_PIN 11

void setup() {
  pinMode(LED_R_PIN, OUTPUT); //LED 핀 설정
  pinMode(LED_G_PIN, OUTPUT);
  pinMode(LED_B_PIN, OUTPUT);
}

void loop() {
  int pwm = 255;
  analogWrite(LED_R_PIN, 255 -pwm);
  analogWrite(LED_G_PIN, 255 );
  analogWrite(LED_B_PIN, 255 );
  delay(2000);

  analogWrite(LED_R_PIN, 255 );
  analogWrite(LED_G_PIN, 255 -pwm);
  analogWrite(LED_B_PIN, 255 );
  delay(2000);

  analogWrite(LED_R_PIN, 255);
  analogWrite(LED_G_PIN, 255);
  analogWrite(LED_B_PIN, 255 -pwm);
  delay(2000);

  analogWrite(LED_R_PIN, 255 -pwm);
  analogWrite(LED_G_PIN, 255 -pwm);
  analogWrite(LED_B_PIN, 255 -pwm);
  delay(2000);
}