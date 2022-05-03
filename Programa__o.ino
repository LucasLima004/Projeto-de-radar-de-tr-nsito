#include<LiquidCrystal.h>

//Define as portas de comunicação com o display.
LiquidCrystal lcd(0,1,2,3,4,5);
//Define a velocidade do display.
byte x=200;
//Declara a variável que terá o tempo armazenado.
int  seg2 =0;

void setup()
{
  //Declara as portas e seus uso.
  pinMode(6, INPUT);
  pinMode(7, INPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  //Inicia o display.
  lcd.begin(16, 2);
}

void loop()
{
  //Declaração dos sensores.
  bool sensorUm = digitalRead(7);
  bool sensorDois = digitalRead(6);
 
 //Inicia contagem ao ativar balança.
  if(sensorUm && !sensorDois){
    //Espera 1 segundo.
    delay(1000);
    //Soma 1 segundo ao tempo.
    seg2++;
  }
  //Calcula a velocidade média em metros por segundo.
  int vm= 50/seg2;
  
  //Indica se a velocidade é permitida em Metros/Segundo.
  if(vm>=20){
    //Velocidade ultrapassada.
  	digitalWrite(8,HIGH);
    digitalWrite(9,LOW);
  } else{
    //Velocidade permitida.
  	digitalWrite(9,HIGH);
    digitalWrite(8,LOW);
  }

  if(!sensorUm && !sensorDois){
    //Zera o contador de tempo.
    seg2=0;
    //Limpa a tela caso não tenha nada ativando o sensor.
    lcd.print(0); 
    lcd.clear();      
  	delay(x);
  }else{
    //Imprime a velocidade caso o sensor ative.
  	lcd.print(vm); 
  	lcd.setCursor(0, 0);      
  	delay(x);
  }
              

}
