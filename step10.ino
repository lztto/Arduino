int vr_A0 = A0;           // 아날로그 입력 핀 A0, 가변저항 연결
int led_r = 9;            // PWM 제어 핀 9 (적색 LED)
int led_g = 10;           // PWM 제어 핀 10 (녹색 LED)
int led_b = 11;           // PWM 제어 핀 11 (청색 LED)
int led_mode = 0;         // LED 제어 모드    

void setup() { 
  Serial.begin(9600);     // 시리얼 통신 초기화
  pinMode(vr_A0, INPUT);  // A0 입력 모드 설정 
  pinMode(led_r, OUTPUT); // LED 연결 핀 OUTPUT 모드 설정
  pinMode(led_g, OUTPUT);       
  pinMode(led_b, OUTPUT);       
  digitalWrite(led_r, 0); // LED off   
  digitalWrite(led_g, 0);        
  digitalWrite(led_b, 0);      
}

void loop() {
  if (Serial.available()) {                         // 시리얼 버퍼에 수신된 데이터가 있을 경우 실행
    led_mode = Serial.parseInt();                   // 시리얼 모니터에 입력된 정수값을 읽어옴    
  }  
  
  int adc_value = analogRead(vr_A0);                // A0 핀에서 아날로그 값 읽기 (0~1023)
  int pwm_value = map(adc_value , 0, 1023, 0, 255); // 아날로그 값을 PWM 제어값(0-255)으로 변환
  int duty_cycle = map(adc_value, 0, 1023, 0, 100); // 아날로그 값을 듀티 사이클(0-100%)로 변환
  
  if (led_mode == 1) {             // 적색 LED
    analogWrite(led_r, pwm_value); // LED에 PWM 제어값 출력
    analogWrite(led_g, 0);         // 녹색 LED 끄기
    analogWrite(led_b, 0);         // 청색 LED 끄기
    Serial.print("Red LED ");
  } 
  else if (led_mode == 2) {        // 녹색 LED
    analogWrite(led_r, 0);         // 적색 LED 끄기
    analogWrite(led_g, pwm_value); // LED에 PWM 제어값 출력
    analogWrite(led_b, 0);         // 청색 LED 끄기
    Serial.print("Green LED ");
  }
  else if (led_mode == 3) {        // 청색 LED
    analogWrite(led_r, 0);         // 적색 LED 끄기
    analogWrite(led_g, 0);         // 녹색 LED 끄기
    analogWrite(led_b, pwm_value); // LED에 PWM 제어값 출력
    Serial.print("Blue LED ");
  }
  else if (led_mode == 4) {        // 모든 LED 켜기
    analogWrite(led_r, pwm_value); // 적색 LED
    analogWrite(led_g, pwm_value); // 녹색 LED
    analogWrite(led_b, pwm_value); // 청색 LED
    Serial.print("All LEDs ");
  }
  if (led_mode) {                  // LED 제어상태 출력
    Serial.print(duty_cycle);
    Serial.println('%');
  }
  else{
  	Serial.println("All LEDs off");
  }
  delay(1000);
}
