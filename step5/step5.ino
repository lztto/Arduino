int vr_A0 = A0;    //핀번호 지정 
void setup() { 
Serial.begin(9600);  //시리얼 통신 설정  
pinMode(vr_A0, INPUT); //input output 설정
}
 void loop() { //반복(라인별로 차례대로)
 int adc_value = analogRead(vr_A0); // 아날로그 값을 가져옴(앞에 번호)
 float volt_value = (adc_value/1023.0)*5; //0~1023의 정수형 입력값을 0~5 V의 실수형 전압값으로 변환(1023.0 주의!)
 Serial.println(volt_value);   //시리얼 모니터 출력하는것 
delay(1000); //1초 딜레이
}