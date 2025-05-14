#include <Wire.h>
#include <BH1750.h>
#include <DHT.h>
#include <DHT_U.h>

#define DHT11_PIN 14
#define DHT11_TYPE DHT11
DHT dht11(DHT11_PIN, DHT11_TYPE);
BH1750 bh1750;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  bh1750.begin();
  dht11.begin();
}
void loop() {
  int LUX = bh1750.readLightLevel();
  int TEMP = dht11.readTemperature();
  int RH = dht11.readHumidity();
  String data = String(TEMP) + "," + String(RH) + "," + String(LUX);
  Serial.println(data);
  delay(2000);
}