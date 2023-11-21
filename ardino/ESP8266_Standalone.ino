#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPL6WvoJ7DNH"
#define BLYNK_TEMPLATE_NAME "ClassRoom"
#define BLYNK_AUTH_TOKEN "A87BslBaZjfM7PkjwTHyP7tOU-gTCAL6"


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char ssid[] = "iPhone XR";
char pass[] = "Net~1234";

const int relay = 5;

void setup()
{
  Serial.begin(115200);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  pinMode(relay,OUTPUT);
}

  BLYNK_WRITE(V0) {   
  int value = param.asInt();
  Serial.println(value);
    if(value == 1){
     digitalWrite(relay,LOW);
    }else{
      digitalWrite(relay,HIGH);
    }
  }


void loop()
{
  Blynk.run();
}