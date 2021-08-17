/*
    instrumentacao_projeto.ino
    Versão 1 
    Autora: Mirela de Oliveira Tomazini
    Data: 12 de agosto de 2021
    Descrição: O objetivo desse código é o desenvolvimento do projeto da disciplina de Instrumentação Biomédica. 
    O projeto consiste na realização de um sensor de hipotermia/febre. 
    Princípio de operação: Um termistor NTC foi calibrado e é utilizado para medir a temperatura, a medida que seu valor de resistência
    varia de forma inversa com a temperatura. Dessa maneira, quando a temperatua aumenta, sua resistência dimimui. 
    Para verificar se o valor de tensão do sensor está de acordo com o esperado foi realizado um comparador que compara o valor da tesão de saída]
    do sensor comum valor previamente estabelecido, porém que pode ser facilmente alterado, mudando o duty cycle do Arduino.
    Desa forma, se o valor estiver fora do valor considerado normal é aceso um LED amarelo indicando que é necessário ter ATENÇÃO. 
    Caso o valor esteja dentro dos limites aceitáveis, um LED verde é aceso. 
    Sempre é possível verificar a temperatura atual medida através do Plotter Serial/Monitor Serial.

*/

#include "calc_temp.h"

// No bloco abaixo, encontram-se as variaveis que determinam o funcionamento do projeto
float tensao_max      = 5.0;                            // completar com o valor máximo de tensao de entrada
int analogPin         = A3;                             // completar com o pino analógico de entrada
int PWM               = 10;                             // completar com o pino do PWM de saida
int duty_c            = 50;                             // completar com o valor de duty cycle desejado do PWM em % (valores de 0 a 100)
double R10k           = 9700;                           // completar com o valor medido (real) do resistor de 10k
float ten_ali         = 5.0;                            // completar com o valor de alimentação do conjunto resistor + termistor


// No bloco abaixo, encontram-se as variaveis que o programa ira usar em sua execucao 
int valor_medido      = 0;                              // variavel para guardar o valor lido               (10 bits, mede de 0 a 1023)
float tensao          = 0;                              // variavel para guardar o valor da tensao          (valor deve variar de 0 a 5V)
int duty_cycle        = 2.55*duty_c;                    // variavel que guarda um valor inteiro convertido de porcentagem para valores aceitos na funcao do PWM (0 a 255)
double temperatura    = 0;                              // variavel para guardar o valor calculado de temperatura     
double R_termistor    = 0;                              // variavel para guardar o valor calculado da resistência do termistor 


// No bloco abaixo, encontram-se as cofiguracoes iniciais do Arduino
void setup() {                                          // realiza as configuracoes do Arduino, roda apenas 1 vez, quando eh ligado
  pinMode(PWM, OUTPUT);                                 // configura o 10 (PWM) como saída
  Serial.begin(9600);                                   // configura a porta serial e configura para 9600 bps a taxa de dados
}


//No bloco abaixo, encontra-se o loop dentro do qual o projeto sera de fato exceutado
void loop() {                                           // loop do Arduino, roda infinitas vezes, onde o programa sera executado
  analogWrite(PWM, duty_cycle);                         //analogWrite recebe apenas valores inteiros de 0 a 255, entao foi feita a conversao de porcentagem para essa escala
                                                        // e a funcao recebe de argumentos o pino que sera o PWM e duty cycle
  valor_medido = analogRead(analogPin);                 // le o pino de entrada, varia entre os valores de 0 a 1023
  tensao = (tensao_max*float(valor_medido))/1023.0;     // converte o valor lido para um valor de tensao, sendo a tensao maxima de (5 V) equivalente a 1023
                                                        // O valor de tensao pode ser obtido atraves da expressao (5*valor)/1023. E estou forcando que a variável valor seja float.
  
  // tensao = (R_termistor/(R10k +R_termistor))*ten_ali         ----    divisor de tensao                                            
  R_termistor = (R10k*tensao)/(ten_ali-tensao);         // calcula o divisor de tensao para encontrar o valor da resistencia do termistor

  temperatura = calculo_temperatura1(R_termistor);      // calcula a temperatura
                            
  Serial.println(temperatura);                          // imprime o valor calculado de temperatura
  Serial.print(" ");                                    // imprime o valor de espaço na porta serial
  delay(50);                                            // aguarda 50 ms
      
  
}
