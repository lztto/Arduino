// 3-3
int led_2 = 2;               
int led_3 = 3;               
int btn_9 = 9;            // 풀업 저항 사용 버튼
int btn_10 = 10;          // 풀다운 저항 사용 버튼

void setup() {
  Serial.begin(9600);     // 시리얼 통신 초기화
  pinMode(btn_9, INPUT);  // 버튼 연결 핀을 입력으로 설정
  pinMode(btn_10, INPUT);  
  pinMode(led_2, OUTPUT); // LED 연결 핀을 출력으로 설정
  pinMode(led_3, OUTPUT);   
  digitalWrite(led_2,0);  // 초기 설정 시 LED off
  digitalWrite(led_3,0); 
}

void loop() {    
  int btn_9_state = !digitalRead(btn_9);  // 풀업 저항 사용 버튼 상태값 (핀 입력값 반전 후 저장)
  int btn_10_state = digitalRead(btn_10); // 풀다운 저항 사용 버튼 상태값 (핀 입력값 저장)

  digitalWrite(led_2, btn_9_state);       // btn_9_state에 따라 2번 핀 LED 제어
  digitalWrite(led_3, btn_10_state);      // btn_10_state에 따라 3번 핀 LED 제어 
}
//9번 핀에 연결된 버튼을 누르면 2번핀에 연결된LED가 on되고, 10번핀에 연결된 버튼을 누르면 3번핀에 연결된LED가 on되도록 프로그래밍을 해보았다.
//풀업저항을 not(!)을 이용해 off를 해주어 핀 입력값을 반전 후 실행되게 하며 실행하였다.