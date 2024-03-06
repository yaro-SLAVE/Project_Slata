#include <SD.h>
#include <ArduinoJson.h>

#include <ESP8266WiFi.h>
const int chipSelect = D4;
WiFiServer wifiServer (80);


#include <RF24Network.h>


#include <RF24.h>
#include <SPI.h>


RF24 radio(4, 15);                    

RF24Network network(radio);         

const uint16_t this_node = 00;
uint16_t node; 
#include <string.h>

File dataFile;
String buffer;//тут хранится прочитанный из карты текст
boolean SDfound;


String j;
uint16_t x;
String y;
char* z;


uint32_t Timer1;
uint32_t Timer2;

void setup()
{
  WiFi.begin("AndroidAPBC12", "acrm1112");
  delay (5000);
  wifiServer.begin();
  
  delay(1000);
  Serial.begin(115200);
  Serial.println(F("RF24Network/examples/Network_Separation_TX/"));
   //Used to enable printf on AVR devices

  if (!radio.begin()) {
    Serial.println(F("Radio hardware not responding!"));
    while (1) {
      // hold in infinite loop
    }
  }


  network.begin(90, this_node);  //(channel, node address)

  SPI.begin();
   Serial.begin(115200); // Инициализируем UART.
   while (!Serial);
   
  
  
  
}

void loop()
{

  char S[] = " ";
  

  Serial.println("Initializing SD card..."); 
  pinMode(chipSelect, OUTPUT);
                   
  if (SDfound == 0)
  {
    if (!SD.begin(chipSelect))
    {
      Serial.print("The SD card cannot be found");
      while(1);
    }
  }
  SDfound = 1;

  dataFile = SD.open("test.txt");//Откроем файл
  Serial.println("SD card ok.");

  if (!dataFile)
  {
    Serial.print("text fail eror"); // Текстовый файл не открывается
    while(1);
  }

Serial.println("Test-1");
while (dataFile.available()) //Читаем содержимое файла
{
    buffer = dataFile.readStringUntil('\n');
    Serial.println(buffer); 
   
    char charBuf[buffer.length()+1];
    buffer.toCharArray(charBuf, buffer.length());

    char *pch;
    pch = strtok (charBuf,";");
    
    
    
    
    while (pch != NULL)
    {
      if (strlen(pch)==1){
        j=pch;
      }
      if ((strlen(pch)>1)and(strlen(pch)<6)){
        y = pch;
        x = y.toInt();
      }
      if (strlen(pch)>6){
        z=pch;
      }
      
      Serial.println (pch);
      pch = strtok (NULL, ";");
      
    
    }
    
    Serial.println ("111");
    Serial.println (z);
    Serial.println (x);
    Serial.println ("//////");
    Serial.println (j);

    WiFiClient client;
  client.setTimeout(10000);

  if (!client.connect("moyaslata-api-test.azurewebsites.net", 80)) {
   
    return;
  }
  client.print("GET /api/Products/PriceCheck?storeId=1159&barCode=");
  client.print(z);
  client.println(" HTTP/1.0");
  client.println(F("Host: moyaslata-api-test.azurewebsites.net"));
  client.println(F("Connection: close"));
  if (client.println() == 0) {
    Serial.println(F("Failed to send request"));
    client.stop();
    return;
  }

  // Check HTTP status
  char status[32] = {0};
  client.readBytesUntil('\r', status, sizeof(status));
  // It should be "HTTP/1.0 200 OK" or "HTTP/1.1 200 OK"
  if (strcmp(status + 9, "200 OK") != 0) {
    
    client.stop();
    return;
  }

  // Skip HTTP headers
  char endOfHeaders[] = "\r\n\r\n";
  if (!client.find(endOfHeaders)) {
   
    client.stop();
    return;
  }

  const size_t capacity = JSON_OBJECT_SIZE(3) + JSON_ARRAY_SIZE(2) + 60;
  DynamicJsonDocument doc(capacity);

  // Parse JSON object
  DeserializationError error = deserializeJson(doc, client);
  if (error) {
    
    client.stop();
    return;
  }
    

if (j=="1"){





  

  network.update(); // Check the network regularly


int i=0;
    Serial.println(F("Sending data..."));
    while (i<5){
       
    double p = doc["price"];
    long price = p*100;
    const char* name = doc["name"];

    
    if (millis() - Timer1 >= 1000) {
    Timer1 = millis();
    RF24NetworkHeader header (x, 32);
    
    bool ok = network.write(header,name,strlen(name));
    Serial.println(ok ? F("OK 1") : F("Fail 1"));
    
    RF24NetworkHeader header2 (x, 33);
    
    bool ok2 = network.write(header2, &price, sizeof(price));
    Serial.println(price);
    Serial.println(ok2 ? F("OK 2") : F("Fail 2"));
     i++;
    }



    
 
    
    
    }
    
}

  if (j=="2"){

   


  network.update(); // Check the network regularly


int i1=0;
    Serial.println(F("Sending data..."));
    while (i1<5){
    
    double p1 = doc["price"];
    long price1 = p1*100;
    const char* name1 = doc["name"];

    
    if (millis() - Timer1 >= 1000) {
    Timer1 = millis();
    RF24NetworkHeader header1 (x, 34);
    
    bool ok3 = network.write(header1,name1,strlen(name1));
    Serial.println(ok3 ? F("OK 1") : F("Fail 1"));
    
    
    
    RF24NetworkHeader header3 (x, 35);
    
    bool ok4 = network.write(header3, &price1, sizeof(price1));
    Serial.println(price1);
    Serial.println(ok4 ? F("OK 2") : F("Fail 2"));
    i1++;
   
    }


    
  
    
    
    }
   
    
  }
   
  
}
}
