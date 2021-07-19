/*
    instrumentacao_potenciometro.ino
    Versão 1 
    Autora: Mirela de Oliveira Tomazini
    Data: 13 de julho de 2021
    Descrição: O objetivo desse código é a realização de simples tarefas com o Arduino tendo em vista, 
    me habituar com o ambiente de programação e linguagem.
    Esse código recebe os valores da resistência acoplada, tensão máxima fornecida pelo microcontrolador e
    valor do pino analogico ligado ao ponto do potenciômetro e controla 3 LEDs com base no valor medido. 
    O LED vermelho é ligado se o paciente está com febre, o LED azul é ligado se o paciente está com hipotermia
    e o LED verde é ligado se o paciente está normal, dentro de valores esperados.
      Além disso, é possível verificar o valor de resistência calculado através do Plotter Serial e Monitor Serial.
*/

int resist_acoplada   = 501 ;                  // completar com o valor da resistencia acoplada para realizacao do dividor de tensao     (valor deve ser o valor real e inteiro)
float tensao_max      = 5;                     // completar com o valor máximo de tensao de entrada
int analogPin         = A3;                    // leitura do pino analogico - conferir se o pino esta correto

int valor             = 0;                     // variavel para guardar o valor lido               (10 bits, mede de 0 a 1023)
float tensao          = 0;                     // variavel para guardar o valor da tensao          (valor deve variar de 0 a 5V)
int resist_medida     = 0;                     // variavel para guardar o valor da resistencia do potenciometro (varia de 0 a potenciometro)
int lim_hipotermia    = 1600;                  // variavel para guardar o valor do limite da resistencia para hipotermia
int lim_febre         = 600;                   // variavel para guardar o valor do limite da resistencia para febre

void setup() {                                 // realiza as configuracoes do Arduino, roda apenas 1 vez, quando eh ligado
  
  pinMode(13, OUTPUT);                         // configura o pino 13 como saida - condicao normal
  pinMode(12, OUTPUT);                         // configura o pino 12 como saida - hipotermia
  pinMode(11, OUTPUT);                         // configura o pino 11 como saida - febre 
  Serial.begin(9600);                          // configura a porta serial e configura para 9600 bps a taxa de dados
}

void loop() {                                 // loop do Arduino, roda infinitas vezes, onde o programa sera executado
  
  valor = analogRead(analogPin);              // le o pino de entrada
  tensao = (5.0*float(valor))/1023.0;         // converte o valor lido para um valor de tensao, sendo a tensao maxima de (5 V) equivalente a 1023
                                              // O valor de tensao pode ser obtido atraves da expressao (5*valor)/1023. E estou forcando que a variável valor seja float.
                                              
  resist_medida = ((tensao/tensao_max)* resist_acoplada)/(1-(tensao/tensao_max));  
                                              //calculo de resistencia medida sera deduzido no portfolio anexo
                            
  Serial.println(resist_medida);              // imprime o valor da resistencia medida na porta serial
  Serial.print(" ");                          // imprime o valor de espaço na porta serial
  delay(50);                                  // aguarda 50 ms

  if(resist_medida < lim_febre){              // condicao de febre - deve acender o LED vermelho - atencao o operador "<" foi definido atraves da caracteristica do sensor NTC
    digitalWrite(13, LOW);                    // apaga LED verde
    digitalWrite(12, LOW);                    // apaga LED azul
    digitalWrite(11, HIGH);                   // acende LED vermelho
  }
  else if(resist_medida > lim_hipotermia){    // condicao de hipotermia - deve acender o LED azul - atencao o operador ">" foi definido atraves da caracteristica do sensor NTC
    digitalWrite(13, LOW);                    // apaga LED verde
    digitalWrite(12, HIGH);                   // acende LED azul
    digitalWrite(11, LOW);                    // apaga LED vermelho
  }
  else{                                       // caso nenhuma condicao se satisfaça, entao o paciente esta normal
    digitalWrite(13, HIGH);                   // acende LED verde
    digitalWrite(12, LOW);                    // apaga LED azul
    digitalWrite(11, LOW);                    // apaga LED vermelho
  }

  delay(50);                                  // aguarda 50 ms           
  
}
