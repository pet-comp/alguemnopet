#include <ArduinoJson.h>
#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <TelegramBot.h>
#define BOTtoken "1305351200:AAHnlql7YK3TVRGZCLbgkyeh_lEY4ERfP6o"//Define o Token do *seu* BOT

WiFiClientSecure client;
TelegramBot bot(BOTtoken, client);

String id, text;//Váriaveis para armazenamento do ID e TEXTO gerado pelo Usuario
unsigned long tempo;

void setup()
{
   Serial.begin(115200);

   Serial.print("Connecting...");
 
   pinMode(LED_BUILTIN, OUTPUT);//LED da placa mesmo
   WiFi.mode(WIFI_STA);//Define o WiFi como Estaçao
   connect();//Funçao para Conectar ao WiFi
}

void loop()
{
   if (millis() - tempo > 2000)//Faz a verificaçao das funçoes a cada 2 Segundos
   {
      connect();//Funçao para verificar se ainda há conexao
      readTel();//Funçao para ler o telegram
      tempo = millis();//Reseta o tempo
   }
}

void connect()//Funçao para Conectar ao wifi e verificar à conexao.
{
   if (WiFi.status() != WL_CONNECTED)//Caso nao esteja conectado ao WiFi, Ira conectarse
   {
      WiFi.begin("Molotov", "741852963");//Insira suas informaçoes da rede
      delay(2000);
   }
}

void readTel()//Funçao que faz a leitura do Telegram.
{
   //int newmsg = bot.getUpdates(bot.last_message_received + 1);
   message m = bot.getUpdates();
   

   /*for (int i = 0; i < newmsg; i++)//Caso haja X mensagens novas, fara este loop X Vezes.
   {
      id = bot.messages[i].chat_id;//Armazenara o ID do Usuario à Váriavel.
      text = bot.messages[i].text;//Armazenara o TEXTO do Usuario à Váriavel.
      Serial.println(text);
      text.toUpperCase();//Converte a STRING_TEXT inteiramente em Maiuscúla.

      if (text.indexOf("ON") > -1)//Caso o texto recebido contenha "ON"
      {
         digitalWrite(LED_BUILTIN, HIGH);//Liga o LED
         bot.sendMessage(id, "LED ON", "");//Envia uma Mensagem para a pessoa que enviou o Comando.
      }

      else if (text.indexOf("OFF") > -1)//Caso o texto recebido contenha "OFF"
      {
         digitalWrite(LED_BUILTIN, LOW);//Desliga o LED
         bot.sendMessage(id, "LED OFF", "");//Envia uma Mensagem para a pessoa que enviou o Comando.
      }

      else if (text.indexOf("START") > -1)//Caso o texto recebido contenha "START"
      {
         bot.sendSimpleMessage(id, id, "");//Envia uma mensagem com seu ID.
      }

      else//Caso o texto recebido nao for nenhum dos acima, Envia uma mensagem de erro.
      {
         bot.sendSimpleMessage(id, "Comando Invalido", "");
      }
   }*/

}
