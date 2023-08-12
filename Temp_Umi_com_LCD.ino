//PROJETO DE LEITURA DE TEMPERATURA E UMIDADE (SENSOR DHT11) E APRESENTAÇÃO NO DISPLAY DE LCD

#include <LiquidCrystal.h> //Inclusão da biblioteca do LCD

#include <dht.h> //Inclusão da biblioteca do sensor de Temp. e Umidade (DHT11)

//Definição dos pinos dos periféricos
#define DHTVAR A10
#define led_vm 22
#define K1 30

LiquidCrystal lcd (8 , 9 , 4 , 5 , 6, 7);//Mapeamento/pinagem do LCD
dht DHT;//Variável do tipo DHT

void Temp_Um();//Loading/priorizando a leitura  da função principal 

//Função de inicialização do sistema
void setup()
{
  pinMode(led_vm, OUTPUT);
  pinMode(K1, OUTPUT);

  digitalWrite(led_vm, 0);
  digitalWrite(K1, 1);

  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.setCursor(5, 0);
  lcd.print("SENAI");
  delay(2000);  
}

//Função de leitura do sensor e apresentação dos dados no LCD 
void Temp_Um()

{
  DHT.read11(DHTVAR);
  Serial.print("Umi:");
  Serial.print(DHT.humidity);
  Serial.print("% ");
  Serial.println(" ");

  Serial.print("Temp:");
  Serial.print(DHT.temperature, 0);
  Serial.print("°C");
  Serial.println(" ");
  Serial.println(" ");

  delay(2000);


  lcd.setCursor(0, 1);
  lcd.print("U:");
  lcd.print(DHT.humidity);
  lcd.print(" & ");

  lcd.print("T:");
  lcd.print(DHT.temperature, 0);
  lcd.print("*C");
}

//Função de overlay do sistema
void sinalizacao()
{
  if (DHT.humidity >= 60)
  {
    digitalWrite(led_vm, 1);
    digitalWrite(K1, 0);
  }

}

//Função de loop/repetição
void loop()
{
  Temp_Um();
  sinalizacao();
}
