#include <RF24Network.h>


#include <RF24.h>
#include <SPI.h>


#include <LCD_1602_RUS.h> 
#include <Wire.h>

LCD_1602_RUS lcd(0x22, 16, 2);
LCD_1602_RUS lcd2(0x23, 16, 2);

static char payload[128];
unsigned long price=0;
static char payload1[128];
unsigned long price1=0;

double p;
double p1;
float f;
float f1;

char a[32];
char b[32];
char c[32];
char d[32];

byte i=0;
byte n1=0;

byte j=0;
byte g=0;
byte n2=0;

byte h=0;
byte k=0;
byte y=0;
byte n3=0;

byte s=0; 
byte t=0;
byte n4=0;

char a1[32];
char b1[32];
char c1[32];
char d1[32];

byte i1=0;
byte n11=0;

byte j1=0;
byte g1=0;
byte n21=0;

byte h1=0;
byte k1=0;
byte y1=0;
byte n31=0;

byte s1=0; 
byte t1=0;
byte n41=0;

RF24 radio(9, 10);               

RF24Network network(radio);     
const uint16_t this_node = 01;  
const uint16_t other_node = 00; 



void setup() {

  lcd.init();
  lcd.backlight();
  lcd2.init();
  lcd2.backlight();
  
  
  Serial.begin(115200);
  if (!Serial) {
    // some boards need this because of native USB capability
  }
  Serial.println(F("RF24Network/examples/helloworld_rx/"));

 
  if (!radio.begin()) {
    Serial.println(F("Radio hardware not responding!"));
    while (1) {
      // hold in infinite loop
    }
  }
  network.begin(/*channel*/ 90, /*node address*/ this_node);
SPI.begin();



}

void loop() {

 
    while ((price1==0)+(strlen(payload1)<10)+(price==0)+(strlen(payload)<10)){
  network.update();                 

  while (network.available()) {

    RF24NetworkHeader header;
    network.peek(header);
    
  
    
    if (header.type == 32) {
        
        network.read(header, payload, sizeof(payload));
        
    
      } 
    if (header.type == 33) {
        
        network.read(header, &price, sizeof(price)); 
        
        // some other header type is received
      }

      if (header.type == 34) {
        
        network.read(header, payload1, sizeof(payload1));
        
        
      } 
    if (header.type == 35) {
        
        network.read(header, &price1, sizeof(price1)); 
        
        // some other header type is received
      }
  }
    }
     
     while (i<=30)
    {
      
      if (payload[i]==' '){
        
        n1=i;
      }
      
      i++;
    }
    
    i=0;
    while (i<=n1)
    {
      a[i]=payload[i];
      i++;
    }
  
    j=i;
    while (g<=30)
    {
      if (payload[j]==' '){
   
        n2=g;
      }
      g++;
      j++; 
    }
    
    j=i;
    g=0;
    while(g<=n2)
    {
      b[g]=payload[j];    
      g++;
      j++; 
    }
    
    h=j;
    while (k<=30)
    {
      if (payload[h]==' '){
        y++;
        n3=k;
      }
      if (y==0)
      {
        n3=k;     
      }     
      k++;
      h++; 
    }

    h=j;
    k=0;
    while(k<=n3)
    {
      c[k]=payload[h];
      k++;
      h++; 
    }

    s=h; 
    while (t<=30)
    {
      if (payload[s]==' '){
        n4=t;
      }
      else
      {
        n4=t;     
      }
      t++;
      s++; 
    }

    s=h;
    t=0;
    while(t<=n4)
    {
      d[t]=payload[s];
      t++;
      s++; 
    }



    while (i1<=30)
    {
      
      if (payload1[i1]==' '){
        
        n11=i1;
      }
      
      i1++;
    }
    
    i1=0;
    while (i1<=n11)
    {
      a1[i1]=payload1[i1];
      i1++;
    }
  
    j1=i1;
    while (g1<=30)
    {
      if (payload1[j1]==' '){
   
        n21=g1;
      }
      g1++;
      j1++; 
    }
    
    j1=i1;
    g1=0;
    while(g1<=n21)
    {
      b1[g1]=payload1[j1];    
      g1++;
      j1++; 
    }
    
    h1=j1;
    while (k1<=30)
    {
      if (payload1[h1]==' '){
        y1++;
        n31=k1;
      }
      if (y1==0)
      {
        n31=k1;     
      }     
      k1++;
      h1++; 
    }

    h1=j1;
    k1=0;
    while(k1<=n31)
    {
      c1[k1]=payload1[h1];
      k1++;
      h1++; 
    }

    s1=h1; 
    while (t1<=30)
    {
      if (payload1[s1]==' '){
        n41=t1;
      }
      else
      {
        n41=t1;     
      }
      t1++;
      s1++; 
    }

    s1=h1;
    t1=0;
    while(t1<=n41)
    {
      d1[t1]=payload1[s1];
      t1++;
      s1++; 
    }

  
       
    
  

    if (price%10 != 0){
    f=price -(price/100*100)+1;
    p = price/100+f/100;
    
    }

    if (price%10 == 0){
    f=price -(price/100*100);
    p = price/100+f/100;
    
    }

    if (price1%10 != 0){
    
    f1=price1 -(price1/100*100)+1;
    p1 = price1/100+f1/100;
    }

    if (price1%10 == 0){
    
    f1=price1 -(price1/100*100);
    p1 = price1/100+f1/100;
    }
    
    
    
     
       
       
    
    
    
    lcd.setCursor(0,0);
    lcd.print(a);
    lcd.setCursor(0,1);
    lcd.print("                ");
    
    lcd.setCursor(3,1);
    lcd.print(p);
    lcd.print(" р");
    
    

    lcd2.setCursor(0,0);
    lcd2.print(a1);
    lcd2.setCursor(0,1);
    lcd2.print("                ");
    
    lcd2.setCursor(3,1);
    lcd2.print(p1);
    lcd2.print(" р");
    
    

    
    
    delay(2000);
    
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(b);
    lcd.setCursor(0,1);
    lcd.print("                ");
    lcd.setCursor(3,1);
    lcd.print(p);
    lcd.print(" р");
    
    

    lcd2.clear();
    lcd2.setCursor(0,0);
    lcd2.print(b1);
    lcd2.setCursor(0,1);
    lcd2.print("                ");
    lcd2.setCursor(3,1);
    lcd2.print(p1);
    lcd2.print(" р");
    
    
    delay(2000);

    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(c);
    lcd.setCursor(0,1);
    lcd.print("                ");
    lcd.setCursor(3,1);
    lcd.print(p);
    lcd.print(" р");
    

    lcd2.clear();
    lcd2.setCursor(0,0);
    lcd2.print(c1);
    lcd2.setCursor(0,1);
    lcd2.print("                ");
    lcd2.setCursor(3,1);
    lcd2.print(p1);
    lcd2.print(" р");
    
    
    delay(2000);

    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(d);
    lcd.setCursor(0,1);
    lcd.print("                ");
    lcd.setCursor(3,1);
    lcd.print(p);
    lcd.print(" р");
    

    lcd2.clear();
    lcd2.setCursor(0,0);
    lcd2.print(d1);
    lcd2.setCursor(0,1);
    lcd2.print("                ");
    lcd2.setCursor(3,1);
    lcd2.print(p1);
    lcd2.print(" р");
    
    
    delay(2000);
    
    lcd.clear();
    lcd2.clear();
    
}
