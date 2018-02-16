#include <SD.h>
#include <SPI.h>
#include <TimeLib.h>

const int chipSelect = 2;  // MicroSD CS lába
const int errorPin = 3;    // Hibajelző LED
const int progressPin = 4; // Mérés folyamatát jelző LED
const int donePin = 5;     // Mérés befejezését jelző LED
const int analogin = 0;    // Innen olvassa a feszültséget feles leosztással

void setup()
{
  setTime(0);
  
  pinMode(errorPin, OUTPUT);
  pinMode(progressPin, OUTPUT);
  pinMode(donePin, OUTPUT);
  
  digitalWrite(errorPin, LOW);
  digitalWrite(progressPin, LOW);
  digitalWrite(donePin, LOW);
  
  Serial.begin(9600);
  if (!SD.begin(chipSelect))
  {
    Serial.println("SD: error");
    digitalWrite(errorPin, HIGH);
    while(1);
  }
  else
  {
    Serial.println("SD: OK");
  }
}

void loop()
{
  digitalWrite(progressPin, HIGH);
  float voltage = 2.0 * analogRead(analogin) * (5.0 / 1023.0);
  time_t t = now();
  
  if (voltage < 1)
  {
    digitalWrite(progressPin, LOW);
    digitalWrite(donePin, HIGH);
    while(1);
  }
  else
  {
    File dataFile = SD.open("datalog.txt", FILE_WRITE);
    if (dataFile)
    {
      dataFile.print(hour(t));
      dataFile.print(":");
      dataFile.print(minute(t));
      dataFile.print(":");
      dataFile.print(second(t));
      dataFile.print("\t");
      dataFile.println(voltage);
      dataFile.close();
    }
    else
    {
      Serial.println("File: error");
      digitalWrite(progressPin, LOW);
      digitalWrite(errorPin, HIGH);
      while(1);
    }
  }
  delay(300000);
}
