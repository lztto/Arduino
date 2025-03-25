int led_a = 11;
int Green_b =10;
int yellow_c = 9;

void setup() {
  Serial.begin(9600);
  pinMode(led_a, OUTPUT); 
  pinMode(Green_b, OUTPUT);
  pinMode(yellow_c, OUTPUT); 
  digitalWrite(led_a, 0);       
  digitalWrite(Green_b, 0);        
  digitalWrite(yellow_c, 0);
}
 void loop() {
   if(Serial.available()){ // 시리얼 버퍼에 수신된 데이터가 있을 경우 실행
       int value = Serial.parseInt();// 시리얼 모니터에 입력된 정수값을 읽어옴
     int pwmValue = map(value, 0, 100, 0, 255);//map이라는 함수에서 0 ,100은 듀티사이클 0,255은 LED값의 최소값 최대값을 설정해주는것이다,// 듀티 사이클(0-100%) PWM 제어값(0-255)으로 변환
     analogWrite(led_a, pwmValue); // LED에 PWM 제어값(0~255) 출력
     analogWrite(Green_b, pwmValue);
     analogWrite(yellow_c, pwmValue);
 }   
}
//듀디사이클 값에 따라 pwm값이 변환되어 LED의 밝기를 제어하는 코드였다
//듀디사이클100일때 pwm값은 255가 되면 high 100으로 나온다
