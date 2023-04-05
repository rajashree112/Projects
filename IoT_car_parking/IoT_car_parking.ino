#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
//#include <DHT.h>
// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// set the LCD number of columns and rows
int lcdColumns = 16;
int lcdRows = 2;

// set LCD address, number of columns and rows
// if you don't know your display address, run an I2C scanner sketch
LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);  
char auth[ ] = "Your Auth Token";

// Your WiFi credentials.
// Set password to "" for open networks.

char ssid[] = "YourNetworkName";
char pass[] = "YourPassword";

//WidgetLCD lcd(V9);
//#define DHTPIN 0  
//#define DHTTYPE DHT11 
//DHT dht(DHTPIN, DHTTYPE);

WidgetLED led1(V1);
WidgetLED led2(V2);
WidgetLED led3(V3);
WidgetLED led4(V4);
WidgetLED led5(V5);
WidgetLED led6(V6);
BlynkTimer timer;

// V1 LED Widget is blinking

void setup()
{
   
      Wire.begin(D2, D1); //(SDA, SCL) 
 lcd.init();      
// lcd.init();
   lcd.backlight();
    pinMode(D0,INPUT);
    pinMode(D4,INPUT);
    
   


  pinMode(D5,INPUT);
    pinMode(D6,INPUT);
    pinMode(D7,INPUT);
    pinMode(D8,INPUT);
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
   //dht.begin();
 
  // Setup a function to be called every second
  //timer.setInterval(1000L, sendSensor);
 // timer.setInterval(1000L, blinkLedWidget);

 
}

//In the loop function include Blynk.run() command.
void loop()
{
  Blynk.run();
  timer.run();
 

 lcd.setCursor(0, 0);
 
  lcd.print("****SMART CAR***");
  delay(1000);
 
  lcd.setCursor(0,1);
  lcd.print("***PARKING S/M****");
  delay(1000);
  lcd.clear(); 
slot1();
slot2();
slot3();
slot4();
slot5();
slot6();

}


void slot1()
{

if (digitalRead(D0)==LOW)
{
 led1.on();
  lcd.setCursor(0,0);
  lcd.print("slot 1 : FILL     ");
  delay(2000);
  lcd.clear(); 
  
}
else
{
   led1.off();
    lcd.setCursor(0,0);
  lcd.print("slot 1 : EMPTY     ");
  delay(2000);
  lcd.clear(); 
}



}



void slot2()
{

if (digitalRead(D4)==LOW)
{
  led2.on();
  lcd.setCursor(0,0);
  lcd.print("slot 2 : FILL     ");
  delay(2000);
  lcd.clear(); 
  
}
else
{
    lcd.setCursor(0,0);
  lcd.print("slot 2 : EMPTY     ");
  delay(2000);
  lcd.clear(); 
      led2.off();
}
}


void slot3()
{

if (digitalRead(D5)==LOW)
{
  led3.on();
  lcd.setCursor(0,0);
  lcd.print("slot 3 : FILL     ");
  delay(2000);
  lcd.clear(); 
  
}
else
{  led3.off();
    lcd.setCursor(0,0);
  lcd.print("slot 3 : EMPTY     ");
  delay(2000);
  lcd.clear(); 
}
}


void slot4()
{

if (digitalRead(D6)==LOW)
{
  led4.on();
  lcd.setCursor(0,0);
  lcd.print("slot 4 : FILL     ");
  delay(2000);
  lcd.clear(); 
  
}
else
{
  led4.off();
    lcd.setCursor(0,0);
  lcd.print("slot 4 : EMPTY     ");
  delay(2000);
  lcd.clear(); 
}
}


void slot5()
{

if (digitalRead(D7)==LOW)
{
 led5.on();
  lcd.setCursor(0,0);
  lcd.print("slot 5 : FILL     ");
  delay(2000);
  lcd.clear(); 
  
}
else
{
   led5.off();
    lcd.setCursor(0,0);
  lcd.print("slot 5 : EMPTY     ");
  delay(2000);
  lcd.clear(); 
}
}


void slot6()
{

if (digitalRead(D8)==LOW)
{
  virtualWrite(V1,HIGH);
  lcd.setCursor(0,0);
  lcd.print("slot 6 : FILL     ");
  delay(2000);
  lcd.clear(); 
  
}
else
{
  virtualWrite(V1,LOW);
    lcd.setCursor(0,0);
  lcd.print("slot 6 : EMPTY     ");
  delay(2000);
  lcd.clear(); 
}
}
