#define BLYNK_TEMPLATE_ID "************"
#define BLYNK_DEVICE_NAME "************"
#define BLYNK_AUTH_TOKEN "*************************"

#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = BLYNK_AUTH_TOKEN;

char ssid[] = "***********"; // type your wifi name
char pass[] = "***********";  // type your wifi password

BLYNK_WRITE(V0)
{
  int value = param.asInt();
  Serial.println(value);
  if(value == 1)
  {
    digitalWrite(0, LOW);
    Serial.println("LED ON");
  }
  if(value == 0)
  {
     digitalWrite(0, HIGH);
     Serial.println("LED OFF");
  }
}

BLYNK_WRITE(V1)
{
  int value = param.asInt();
  Serial.println(value);
  if(value == 1)
  {
    digitalWrite(2, LOW);
    Serial.println("LED ON");
  }
  if(value == 0)
  {
     digitalWrite(2, HIGH);
     Serial.println("LED OFF");
  }
}

void setup()
{
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  pinMode(0,OUTPUT);
  pinMode(2,OUTPUT);
}

void loop()
{
  Blynk.run();
}
