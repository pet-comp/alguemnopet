#include <ArduinoJson.h>
#include <ESP8266WiFi.h>
#include  <WiFiClientSecure.h>
#include <TelegramBot.h>
#define LED LED_BUILTIN //led pin number
// Initialize Wifi connection to the router 
const char* ssid     = "Molotov"; 
const char* password = "741852963"; 
// Initialize Telegram BOT 
const char BotToken[] = "1305351200:AAHnlql7YK3TVRGZCLbgkyeh_lEY4ERfP6o"; 
WiFiClientSecure net_ssl; 
TelegramBot bot (BotToken, net_ssl); 
// the number of the LED pin   
void setup()  
{   
  Serial.begin(115200);   
  while (!Serial) {}  //Start running when the serial is open  
  delay(3000);   
  // attempt to connect to Wifi network:   
  Serial.print("Connecting Wifi: ");   
  Serial.println(ssid);   
  while (WiFi.status() != WL_CONNECTED)  
  {   
    WiFi.begin(ssid, password);
    Serial.print(".");   
    delay(1000);   
  }   
  Serial.println("");   
  Serial.println("WiFi connected");   
  bot.begin();   
  pinMode(LED, OUTPUT);   
}   
void loop()  
{   
message m = bot.getUpdates(); // Read new messages   
if (m.text.equals("on"))  
      {   
  digitalWrite(LED, HIGH);    
  bot.sendMessage(m.chat_id, "The Led is now ON");   
}   
else if (m.text.equals("off"))  
      {   
  digitalWrite(LED, LOW);    
  bot.sendMessage(m.chat_id, "The Led is now OFF");   
}   
}   
