// Projeto 10 - Sensor de luz ambiente
 
int pinoLed =  LED_BUILTIN; 
int pinoSensorLuz = A0;               
int valorLuz = 0;                      
 
void setup()
{
     pinMode(pinoLed,OUTPUT);        
}
 
void loop()
{
  valorLuz = analogRead(pinoSensorLuz);        
  if(valorLuz<300)
  {                
    digitalWrite(pinoLed,HIGH);
  }
  else
  {                    
    digitalWrite(pinoLed,LOW);
  }
  delay(10);                   
}
