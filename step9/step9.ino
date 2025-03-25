int vr_A0 = A0;           // 아날로그 입력 핀 A0, 가변저항 연결
int led_r = 9;            // PWM 제어 핀 9
int led_g = 10;           // PWM 제어 핀 10
int led_b = 11;           // PWM 제어 핀 11

void setup() { 
  pinMode(vr_A0, INPUT);  // A0 INPUT 모드 설정 
  pinMode(led_r, OUTPUT); // LED 연결 핀 OUTPUT 모드 설정
  pinMode(led_g, OUTPUT);       
  pinMode(led_b, OUTPUT);       
  digitalWrite(led_r, 0); // LED off   
  digitalWrite(led_g, 0);        
  digitalWrite(led_b, 0);       
}

void loop() {
  int adc_value = analogRead(vr_A0);                // ADC 값(0~1023)
  int pwm_value = map(adc_value , 0, 1023, 0, 255); // ADC 값(0~1023)을 PWM 제어값(0-255)으로 변환
  
  analogWrite(led_r, pwm_value);                    // PWM 제어값을 사용한 LED 디밍 제어   
  analogWrite(led_g, pwm_value);        
  analogWrite(led_b, pwm_value);
}