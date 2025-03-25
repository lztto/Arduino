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
  int adc_value = analogRead(vr_A0);       // ADC로 아날로그 값에서 디지털 값으로 변환된 전압값(정수값, 0~1023)
  float volt_value = (adc_value/1023.0)*5; // 0~1023의 정수형 입력값을 0~5 V의 실수형 전압값으로 변환(1023.0 주의!)
      
  if (volt_value >= 3) {                     
    digitalWrite(led_r, 1);                // LED on   
    digitalWrite(led_g, 1);        
    digitalWrite(led_b, 1);
  }
  else{
    digitalWrite(led_r, 0);                // LED off   
    digitalWrite(led_g, 0);        
    digitalWrite(led_b, 0);
  }
}