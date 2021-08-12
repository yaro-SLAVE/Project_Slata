#include <LCD_1602_RUS.h> 
#include <Wire.h>

LCD_1602_RUS lcd(0x22, 16, 2);
//Include Libraries
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
//create an RF24 object
RF24 radio(9, 10);  // CE, CSN
//address through which two modules communicate.
const byte address[6] = "00001";
void setup()
{
   Serial.begin(115200);
lcd.init();
  lcd.backlight();
  radio.begin();
  
  //set the address
  radio.openWritingPipe(address);
  
  //Set module as transmitter
  radio.stopListening();

}
void loop()
{
  //Send message to receiver

    if(Serial.available()>0){ 
       char text = Serial.read();// если в последовательном порту есть данные для чтения, то ...
                       // устанавливаем курсор в позицию: столбец 15, строка 1
  radio.write(&text, sizeof(text));
 
  lcd.print(text) ;
    }
    delay(2000);
    

}
