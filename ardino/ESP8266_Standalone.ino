#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPL6WvoJ7DNH"
#define BLYNK_TEMPLATE_NAME "ClassRoom"
#define BLYNK_AUTH_TOKEN "A87BslBaZjfM7PkjwTHyP7tOU-gTCAL6"


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char ssid[] = "iPhone XR";
char pass[] = "Net~1234";

  BLYNK_WRITE(V0)
{   
  int value = param.asInt();
  Serial.println(value);
    if(value == 1){
     digitalWrite(D0,HIGH);
    }else{
      digitalWrite(D0,LOW);
      }
}
  BLYNK_WRITE(V1)
{   
  int value = param.asInt();
  Serial.println(value);
    if(value == 1){
     digitalWrite(D1,HIGH);
    }else{
      digitalWrite(D1,LOW);
      }
}
  BLYNK_WRITE(V2)
{   
  int value = param.asInt();
  Serial.println(value);
    if(value == 1){
     digitalWrite(D2,HIGH);
    }else{
      digitalWrite(D2,LOW);
      }
}

void setup()
{
  
  Serial.begin(9600);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
   pinMode(D0,OUTPUT);
  pinMode(D1,OUTPUT);
  pinMode(D2,OUTPUT);
}

void loop()
{
  Blynk.run();
}
