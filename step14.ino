//소음센서 0.1초, 주요센서는 2초주기로 측정하도록 설정
//라이브러리 삽입
#include <Wire.h>
#include <BH1750.h>
#include <MQ135.h>
#include <DHT.h>
#include <DHT_U.h>

//센서 핀 정의
#define DHT11_PIN 14
#define DHT11_TYPE DHT11
#define MQ135_PIN A12
#define DFR0034_PIN A5

MQ135 mq135(MQ135_PIN);
DHT dht11(DHT11_PIN, DHT11_TYPE);
BH1750 bh1750;

unsigned long t = 0;
unsigned long t_prev = 0;
unsigned long t_prev_DFR0034 = 0;

int paroid_ms = 2000;
int paroid_ms_DFR0034 = 100;
int adc_max = 0;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  bh1750.begin();
  dht11.begin();
  t_prev = millis();
}
void loop() {
  t = millis();
  if(t - t_prev_DFR0034 >= paroid_ms_DFR0034){
     int adc = analogRead(DFR0034_PIN);
     if (adc > adc_max){
      adc_max = adc;
     }
     t_prev_DFR0034 = t;
     if(t - t_prev >= paroid_ms) {
      int LUX = bh1750.readLightLevel(); //조도 측정
      int TEMP = dht11.readTemperature(); //온도 측정
      int RH = dht11.readHumidity(); //습도 측정
      int GAS = mq135.getCorrectedPPM(TEMP, RH);  //공기질 측정
      float SIP = (adc_max / 1023.0)*100; //소음값을 백분율로 변환
      //모든 센서 데이터를 쉼표로 구분하여 시리얼로 전송송
      String data = String(TEMP) + "," + String(RH) + "," + String(LUX) + "," + String(GAS) + "," + String(adc) + "," + float(SIP);
      Serial.println(data);
      adc_max = 0; //최대 소음값 초기화
      t_prev = t;
     }
  }
}