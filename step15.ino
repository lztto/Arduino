//블루투스랑 사용해 휴대폰으로도 값을 볼 수 있게 함
#include <Wire.h>
#include <BH1750.h>
#include <MQ135.h>
#include <DHT.h>
#include <DHT_U.h>


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
  Serial1.begin(9600);
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
      int LUX = bh1750.readLightLevel();
      int TEMP = dht11.readTemperature();
      int RH = dht11.readHumidity();
      int GAS = mq135.getCorrectedPPM(TEMP, RH);
      float SIP = (adc_max / 1023.0)*100;
      String data = String(TEMP) + "," + String(RH) + "," + String(LUX) + "," + String(GAS) + "," + String(adc) + "," + float(SIP);
      Serial.println(data);
      Serial1.println(data);
      adc_max = 0;
      t_prev = t;
     }
  }
}