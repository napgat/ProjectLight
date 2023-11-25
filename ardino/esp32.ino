/*************************************************************
  Blynk is a platform with iOS and Android apps to control
  ESP32, Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build mobile and web interfaces for any
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: https://www.blynk.io
    Sketch generator:           https://examples.blynk.cc
    Blynk community:            https://community.blynk.cc
    Follow us:                  https://www.fb.com/blynkapp
                                https://twitter.com/blynk_app

  Blynk library is licensed under MIT license
  This example code is in public domain.

 *************************************************************
  This example runs directly on ESP32 chip.

  NOTE: This requires ESP32 support package:
    https://github.com/espressif/arduino-esp32

  Please be sure to select the right ESP32 module
  in the Tools -> Board menu!

  Change WiFi ssid, pass, and Blynk auth token to run :)
  Feel free to apply it to any other example. It's simple!
 *************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

#define BLYNK_TEMPLATE_ID "TMPL6qUCRcTwz"
#define BLYNK_TEMPLATE_NAME "Quickstart Template"
#define BLYNK_AUTH_TOKEN "eO7VCcWb3RzVpxsOjZbuBk4qvm0nr7nP"
#define LINE_TOKEN "kUch5lpPe6WgPsE3E3Duqg194gLitIzMnRrJZSIDuoq"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include "DHT.h"
#include <TridentTD_LineNotify.h>

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "articubot_one";
char pass[] = "";

// Uncomment whatever type you're using!
#define DHTTYPE DHT11   // DHT 11
#define DHTPIN 4     // Digital pin connected to the DHT sensor
DHT dht(DHTPIN, DHTTYPE);

BlynkTimer timer;

const int relay = 13;

void setup()
{
  // Debug console
  Serial.begin(115200);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  pinMode(relay,OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.println(F("DHTxx test!"));
  dht.begin();
  LINE.setToken(LINE_TOKEN);
  timer.setInterval(1000000, Sensor);

}

BLYNK_WRITE(V0) {   
  int value = param.asInt();
  Serial.println(value);
    if(value == 1){
     digitalWrite(relay,0);
     digitalWrite(LED_BUILTIN,HIGH);
    }else{
      digitalWrite(relay,1);
      digitalWrite(LED_BUILTIN,LOW);
    }
  }
void loop()
{
  Blynk.run();
  timer.run(); 
}

void Sensor()
{
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    delay(5000);
    return;
  }
  Serial.print("Humidity is: "); 
  Serial.println(h, 1);
  Serial.print("Temperature is: "); 
  Serial.println(t, 1);
  
  Blynk.virtualWrite(V2, h);
  Blynk.virtualWrite(V3, t);
  LINE.notify("Humidity is: "+String(h)+" %"); 
  LINE.notify("Temperature is: "+String(t)+" C"); 
}
