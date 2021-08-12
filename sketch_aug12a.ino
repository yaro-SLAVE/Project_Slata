#include <ArduinoJson.h>
#include <SPI.h>
#include <ESP8266WiFi.h>
const int chipSelect = D8;
WiFiServer wifiServer (80);

void setup() {
  // Initialize Serial port
  Serial.begin(115200);


  // Initialize Ethernet library
   WiFi.begin("fsociety00.dat", "1uqZKHK37");
  delay (5000);
  wifiServer.begin();
  
  delay(1000);

 

  // Connect to HTTP server
   WiFiClient client;
  client.setTimeout(10000);
  if (!client.connect("moyaslata-api-test.azurewebsites.net", 80)) {
   
    return;
  }

  

  // Send HTTP request
  client.println(F("GET /api/Products/PriceCheck?storeId=1159&barCode=4607161624661 HTTP/1.0"));
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

  // Extract values
 
  
  
  Serial.print(doc["price"].as<float>(), 2);


  // Disconnect
  client.stop();
}

void loop() {
   WiFiClient client;
  client.setTimeout(10000);
  if (!client.connect("moyaslata-api-test.azurewebsites.net", 80)) {
   
    return;
  }
  client.println(F("GET /api/Products/PriceCheck?storeId=1159&barCode=4607161624661 HTTP/1.0"));
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
    Serial.print(doc["price"].as<float>(), 2);
  client.stop();
  delay(5000);
}


