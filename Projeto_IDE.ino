
// Inclusão da biblioteca para utilização do servo motor
#include <Servo.h> 

// Definição de variaveis
#define sinal A0
#define LedVermelho 5
#define LedAmarelo 6
#define LedVerde 7

// Criação de variaveis
Servo servo1; 
int valor;
int posicao;


void setup()
{
  Serial.begin(9600);
  servo1.attach(9);
  pinMode(sinal, INPUT);
  pinMode(LedVermelho, OUTPUT);
  pinMode(LedAmarelo, OUTPUT);
  pinMode(LedVerde, OUTPUT);
}
 
void loop()
{
  //Le o valor do pino A0 do sensor
  valor = analogRead(sinal);
 
  //Mostra o valor da porta analogica no serial monitor
  Serial.print("Porta analogica: ");
  Serial.print(valor);
  delay(100);
 
  //Solo umido, acende o led azul
  if (valor > 0 && valor < 600)
  {
    Serial.println(" Status: Solo umido");
    apagaleds();
    digitalWrite(LedVerde, HIGH);
    posicao = 0;
    servo1.write(posicao);
  }
 
  //Solo com umidade moderada, acende led amarelo
  if (valor > 600 && valor < 800)
  {
    Serial.println(" Status: Umidade moderada");
    apagaleds();
    digitalWrite(LedAmarelo, HIGH);
    posicao = 0;
    servo1.write(posicao);
  }
 
  //Solo seco, acende led vermelho
  if (valor > 800 && valor < 1024)
  {
    Serial.println(" Status: Solo seco");
    apagaleds();
    digitalWrite(LedVermelho, HIGH);
    // Define posição do variação do servo motor e aciona o mesmo
    posicao = 90;
    servo1.write(posicao);
  }
  delay(100);
}

// Função para apagar os leds
void apagaleds()
{
  digitalWrite(LedVermelho, LOW);
  digitalWrite(LedAmarelo, LOW);
  digitalWrite(LedVerde, LOW);
}
