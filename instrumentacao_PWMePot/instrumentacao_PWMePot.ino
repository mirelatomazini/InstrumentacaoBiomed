/*
    instrumentacao_PWMePot.ino
    Versão 1 
    Autora: Mirela de Oliveira Tomazini
    Data: 18 de julho de 2021
    Descrição: O objetivo desse código é a realização de simples tarefas bem como iniciar a utilização da saída PWM.
    Esse código recebe os valores do potenciometro  e controla o brilho de um LED branco com base no valor medido. 
    Além disso, é possível verificar o valor medido na entrada analogica através do Plotter Serial e Monitor Serial.
*/

float tensao_max      = 5;                     // completar com o valor máximo de tensao de entrada
int analogPin         = A3;                    // completar com o pino analógico de entrada
int PWM               = 10;                    // completar com o pino do PWM de saida

int valor             = 0;                     // variavel para guardar o valor lido               (10 bits, mede de 0 a 1023)
float tensao          = 0;                     // variavel para guardar o valor da tensao          (valor deve variar de 0 a 5V)

void setup() {                                 // realiza as configuracoes do Arduino, roda apenas 1 vez, quando eh ligado
  
  pinMode(PWM, OUTPUT);                        // configura o 10 (PWM) como saída
  Serial.begin(9600);                          // configura a porta serial e configura para 9600 bps a taxa de dados
}

void loop() {                                 // loop do Arduino, roda infinitas vezes, onde o programa sera executado
  
  valor = analogRead(analogPin);              // le o pino de entrada, varia entre os valores de 0 a 1023
  //tensao = (tensao_max*float(valor))/1023.0;// converte o valor lido para um valor de tensao, sendo a tensao maxima de (5 V) equivalente a 1023
                                              // O valor de tensao pode ser obtido atraves da expressao (5*valor)/1023. E estou forcando que a variável valor seja float.
                                              
  analogWrite(PWM, valor/4);                  //analogWrite recebe apenas valores de 0 a 255, como a variavel valor varia de 0 a 1023
                                              // eh necessario realizar a divisao por 4 para converter
                            
  Serial.println(valor);                      // imprime o valor medido da entrada analogica
  Serial.print(" ");                          // imprime o valor de espaço na porta serial
  delay(50);                                  // aguarda 50 ms
      
  
}
