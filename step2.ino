// 3-2
int btn_9 = 9;            // 풀업 저항 사용 버튼
int btn_10 = 10;          // 풀다운 저항 사용 버튼

void setup() {
  Serial.begin(9600);     // 시리얼 통신 초기화
  pinMode(btn_9, INPUT);  // 버튼 연결 핀을 입력으로 설정
  pinMode(btn_10, INPUT);  
}

void loop() {    
  Serial.print("PIN 9 : ");            
  Serial.print(digitalRead(btn_9));    // 풀업 버튼 핀 상태값 출력
  Serial.print(", PIN 10 : ");         
  Serial.println(digitalRead(btn_10)); // 풀다운 버튼 핀 상태값 출력
  delay(1000);                           // 딜레이 1초
}
//아두이노 9, 10번 핀에입력되는 값을1초간격으로 시리얼 모니터에 출력하게 만들었다. (PIN 9 : 0, PIN 10 : 1 등) 버튼을 다시 눌렀을때 시리얼 모니터의 번호가 바뀌는거까지 확인하였음.