//Arduino를 활용한 first step
3-1
int led_2 = 2;            // 정수형 변수 led_2 선언 후 2 입력 
int led_3 = 3;            // 정수형 변수 led_3 선언 후 3 입력

void setup() {
  pinMode(led_2, OUTPUT); // 디지털 입출력 핀(2번) 출력 설정 
  pinMode(led_3, OUTPUT); // 디지털 입출력 핀(3번) 출력 설정 
}

void loop() {
  digitalWrite(led_2, 1); // 2번 핀에서 HIGH 값(5V) 출력
  digitalWrite(led_3, 1); // 3번 핀에서 HIGH 값(5V) 출력
  delay(2000);
  digitalWrite(led_2, 0); // 2번 핀에서 LOW 값(0V) 출력
  digitalWrite(led_3, 0); // 3번 핀에서 LOW 값(0V) 출력
  delay(2000);
}
//2,3번 핀에 연걸된 LED가 2초 간격으로 on/off를 반복하도록 프로그래밍을 해보았다