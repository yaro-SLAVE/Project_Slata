#include <SPI.h>

#include "nRF24L01.h"

#include "RF24.h"


#include <LCD_1602_RUS.h> 
#include <Wire.h>

LCD_1602_RUS lcd(0x22, 16, 2);


//create an RF24 object
RF24 radio(9, 10);  // CE, CSN
//address through which two modules communicate.
const byte address[6] = "00001";
void setup()
{
  while (!Serial);
    Serial.begin(9600);
  
  radio.begin();
  lcd.init();
  lcd.backlight();
  
  //set the address
  radio.openReadingPipe(0, address);
  
  //Set module as receiver
  radio.startListening();
}
void loop()
{
  //Read the data if available in buffer
  if (radio.available())
  {
    lcd.clear();
    delay(1000);
    lcd.setCursor(0,0);
    char text[32] = {0};
    radio.read(&text, sizeof(text));
    Serial.println(text);
    lcd.print(text);
    delay(5000);
    lcd.clear();
  }
  lcd.clear();
}
