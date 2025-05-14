//센서값들을 millis를 사용해 2초마다 값을 받아옴
#include <Wire.h>
#include <BH1750.h>
#include <MQ135.h>
#include <DHT.h>
#include <DHT_U.h>


#define DHT11_PIN 14
#define DHT11_TYPE DHT11
#define MQ135_PIN A12

MQ135 mq135(MQ135_PIN);
DHT dht11(DHT11_PIN, DHT11_TYPE);
BH1750 bh1750;

unsigned long t = 0;
unsigned long t_prev = 0;
int paroid_ms = 2000;
void setup() {
  Serial.begin(9600);
  Wire.begin();
  bh1750.begin();
  dht11.begin();
  t_prev = millis();
}
void loop() {
  t = millis();
  if(t - t_prev >= paroid_ms){
     int LUX = bh1750.readLightLevel();
     int TEMP = dht11.readTemperature();
     int RH = dht11.readHumidity();
     int GAS = mq135.getCorrectedPPM(TEMP, RH);
     String data = String(TEMP) + "," + String(RH) + "," + String(LUX) + "," + String(GAS);
     Serial.println(data);
     t_prev = t;
  }
}