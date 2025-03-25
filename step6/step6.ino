int led_a = 11;
int Green_b =10;
int yellow_c = 9;
 void setup() { 
  pinMode(led_a, OUTPUT);  // LED 연결 핀 OUTPUT 모드 설정
  pinMode(Green_b, OUTPUT);
  pinMode(yellow_c, OUTPUT);
  digitalWrite(led_a, 0);       
  digitalWrite(Green_b, 0);        
  digitalWrite(yellow_c, 0);
}
 void loop() {
   analogWrite(led_a, 0);  // LED에 PWM 제어값(0~255) 출력   
   analogWrite(Green_b, 20);
   analogWrite(yellow_c, 255);
}
//PWM 제어값을 조절해서 LED의 밝기를 조절했다