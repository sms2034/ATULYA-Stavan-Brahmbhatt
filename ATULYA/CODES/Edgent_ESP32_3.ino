

#define BLYNK_TEMPLATE_ID "TMPLYhBsUoTd"
#define BLYNK_DEVICE_NAME "watering plants "


#define BLYNK_FIRMWARE_VERSION        "0.1.0"

#define BLYNK_PRINT Serial
//#define BLYNK_DEBUG

#include "BlynkEdgent.h"
#include <DHT.h>

#define APP_DEBUG



#define DHTPIN 21        
#define DHTTYPE DHT11     
DHT dht(DHTPIN, DHTTYPE);



void sendSensor()
{
  float h = dht.readHumidity();
  float t = dht.readTemperature(); 

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  
  Blynk.virtualWrite(V1, t);
  Blynk.virtualWrite(V2, h);
}

void potValue()
{
  int result = analogRead(34);
  Blynk.virtualWrite(V3,result);
}

BLYNK_WRITE(V0) 
{
  if(param.asInt() == 1)
  {
   
    digitalWrite(23,HIGH);  
  }
  else
  {
   
    digitalWrite(23,LOW);    
  }
}


BLYNK_CONNECTED()
{
  Blynk.syncVirtual(V0); 
}


void setup()
{
  Serial.begin(115200);
  delay(100);
  pinMode(23, OUTPUT);
  BlynkEdgent.begin();
   dht.begin();
 
  timer.setInterval(2000L, sendSensor);
  timer.setInterval(500L,potValue);
}

void loop() {
  BlynkEdgent.run();
  timer.run();
}
