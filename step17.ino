// 시리얼 통신을 통한 LED 제어 프로그램
void setup() {
  Serial.begin(9600);
}

void loop() {
  // 시리얼로 데이터가 들어왔는지 확인
  if (Serial.available() > 0) {
    // 줄바꿈까지지 데이터 읽기
    String data = Serial.readStringUntil('\n');
    // 쉼표 위치 찾기
    int idx = data.index(',');

    if(idx != -1) {
      // 쉼표 앞부분은 LED 색상
      String LED_CLR = data.substring(0, idx);
      // 쉼표 뒷부분은 듀티 사이클 값
      String duty_str = data.substring(idx + 1);
      int LED_DUTY = duty_str.toInt();

      Serial.print("Color:");
      Serial.print(LED_CLR);
      Serial.print(", Duty cycle(%): ");
      Serial.println(LED_DUTY);
    }
  }
}