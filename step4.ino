// 3-4
int led_2 = 2;               
int led_3 = 3;               
int btn_9 = 9;                // 풀업 저항 사용 버튼
int btn_10 = 10;             // 풀다운 저항 사용 버튼

int btn_9_prev_state = 0;  // 버튼 이전 상태값
int btn_10_prev_state = 0;    
int btn_9_cnt = 0;          // 버튼 누른 횟수 저장
int btn_10_cnt = 0;          

void setup() {
  Serial.begin(9600);      // 시리얼 통신 초기화
  pinMode(btn_9, INPUT);   // 버튼 연결 핀을 입력으로 설정
  pinMode(btn_10, INPUT);  
  pinMode(led_2, OUTPUT);  // LED 연결 핀을 출력으로 설정
  pinMode(led_3, OUTPUT);   
  digitalWrite(led_2,0);   // 초기 설정 시 LED off
  digitalWrite(led_3,0); 
}

void loop() {    
  int btn_9_state = !digitalRead(btn_9);    // 풀업 저항 사용 버튼 상태값 (핀 입력값 반전 후 저장)
  int btn_10_state = digitalRead(btn_10);   // 풀다운 저항 사용 버튼 상태값 (핀 입력값 저장)

  digitalWrite(led_2, btn_9_state);         // btn_9_state에 따라 2번 핀 LED 제어
  digitalWrite(led_3, btn_10_state);        // btn_10_state에 따라 3번 핀 LED 제어 

  if (btn_9_state) {                        // 풀업 버튼 눌리면 실행
    if(btn_9_state != btn_9_prev_state) {   // 풀업 버튼 상태가 변할 경우 실행
      btn_9_cnt++;                          // 풀업 버튼 카운트, btn_pu_cnt += 1;
      btn_9_prev_state = 1;                 // 풀업 버튼 이전 상태값 1 입력

      Serial.print("PIN 9 : ");             // 버튼 누른 횟수 출력
      Serial.print(btn_9_cnt);            
      Serial.print(", PIN 10 : ");         
      Serial.println(btn_10_cnt);          
    }
  	delay(50);                              // 디바운싱을 위한 딜레이
  }
  else{                             
     btn_9_prev_state = 0;                  // 풀업 버튼 눌리지 않은 상태면 이전 상태값 0 입력 
  }     

  if (btn_10_state) {                       // 풀다운 버튼 눌리면 실행
    if(btn_10_state != btn_10_prev_state) { // 풀다운 버튼 상태가 변할 경우 실행
      btn_10_cnt++;                         // 풀다운 버튼 카운트, btn_pu_cnt += 1;
      btn_10_prev_state = 1;                // 풀다운 버튼 이전 상태값 1 입력

      Serial.print("PIN 9 : ");             // 버튼 누른 횟수 출력
      Serial.print(btn_9_cnt);            
      Serial.print(", PIN 10 : ");         
      Serial.println(btn_10_cnt);          
    }
  	delay(50);                              // 디바운싱을 위한 딜레이
  }
  else{                             
     btn_10_prev_state = 0;                 // 풀다운 버튼 눌리지 않은 상태면 이전 상태값 0 입력 
  }     
}
//3-3의 기능을 모두수행되게하며,추가로 각각의 버튼을 누른 횟수를 카운트하여 버튼을 누를경우 시리얼모니터에 출력(PIN9:2, PIN 10 : 5등)되도록 아두이노를 프로그래밍 해보았다.