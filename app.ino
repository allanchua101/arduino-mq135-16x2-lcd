#define RZERO 102.9
#include <LiquidCrystal.h>
#include "MQ135.h"

int LCD_RS = 12;
int LCD_EN = 11;
int LCD_D4 = 5;
int LCD_D5 = 4;
int LCD_D6 = 3;
int LCD_D7 = 2;
int LCD_V0 = 6;

LiquidCrystal lcd(LCD_RS, LCD_EN, LCD_D4, LCD_D5, LCD_D6, LCD_D7);
int width = 16;
int height = 2;
int contrast = 60;

// Gas Sensor Configuration
MQ135 gasSensor = MQ135(A1);
int sensorPin = A0;
int STABILIZER_COUNT = 30;
float last30Ppms[30];

// float temperature = 24.0; // Morning temperature with AC (DHT11)
float temperature = 22.0; // Evening temperature with AC (DHT11)
// float temperature = 26.0; // Evening temperature without AC (DHT11)

// float humidity = 80.0 // Singapore Morning DHT11
// float humidity = 61.0; // Evening temperature without AC
float humidity = 68.0; // Evening temperature with AC


float getAvg() {
  float sum = 0;
  
  // Find sum of all array elements
  for(int i = 0; i < STABILIZER_COUNT; i++) {
    sum += last30Ppms[i];
  }
 
  return sum / STABILIZER_COUNT;
}

void setup() {
 Serial.begin(9600);
 
 analogWrite(LCD_V0, contrast);
  
 lcd.begin(width, height);
 pinMode(sensorPin,INPUT);

 delay(500);
 
 for(int i = 0; i < STABILIZER_COUNT; i++) {
   last30Ppms[i] = 0;
 }

 Serial.println("Setup done");
}

void loop() {
  float correctedPPM = gasSensor.getCorrectedPPM(temperature, humidity);
  int timeInS = int(millis() / 1000);
  int i = timeInS % 30;
  last30Ppms[i] = correctedPPM;

  if (timeInS < 30) {
    lcd.setCursor(0, 0);
    lcd.print("Air Quality");
    lcd.setCursor(0, 1);

    String msg = "Loading in " +  String(30 - timeInS) + "s";
    
    lcd.print(msg);
    Serial.println(msg);
    
    delay(1000);
    lcd.clear();
    
    return;
  }

  float ppm = gasSensor.getPPM();
  float raw = analogRead(sensorPin); // Read raw from sensor
  float rZero = gasSensor.getRZero();
  float correctedRZero = gasSensor.getCorrectedRZero(temperature, humidity);

  Serial.print(raw);
  Serial.print("\t");
  Serial.print(rZero);
  Serial.print("\t");
  Serial.print(correctedRZero);
  Serial.print("\t");
  Serial.print(ppm);
  Serial.print("\t");
  Serial.print(correctedPPM);
  Serial.print("\t");
  Serial.print(String(getAvg(), 2));
  Serial.println();
    
  String strCrtPpm = String(getAvg(), 2);
  
  lcd.setCursor(0, 0);
  lcd.print("Air Quality");
  lcd.setCursor(0, 1);
  lcd.print("PPM: " + strCrtPpm);
  delay(1000);
  lcd.clear();
}