/*
    calc_temp.h
    Versão 1 
    Autora: Mirela de Oliveira Tomazini
    Data: 12 de agosto de 2021
    Descrição: O objetivo desse código e o desenvolvimento de funcoes para realizar o calculo da temperatura em graus Celcius
    a partir de um valor previamente calculado da resistencia do termistor.
*/


# include "math.h"

double calculo_temperatura0 (float R){
  // essa funcao recebe o valor de resistencia do resistor e retorna o valor em Kelvin
   
  double Aum      = 3.354016e-03;                   // Valor de A1 encontrado no datasheet usado para o calculo da temperatura
  double Bum      = 2.569850e-04;                   // Valor de B1 encontrado no datasheet usado para o calculo da temperatura
  double Cum      = 2.620131e-06;                   // Valor de C1 encontrado no datasheet usado para o calculo da temperatura
  double Dum      = 6.383091e-08;                   // Valor de D1 encontrado no datasheet usado para o calculo da temperatura

  double Rref    = 10000;                           // Valor da resistencia em 25graus Celcius

  
  double Rdiv    = R/Rref;                          // Valor adimensional resultante da divisao do valor de R pelo valor de Resistencia a 25 ºC, conforme calculo do datasheet
    
  double i_t = Aum + Bum*log(Rdiv) + Cum* pow(log(Rdiv),2) + Dum* pow(log(Rdiv),3);       // Calculo do datasheet 
  double tempk = 1/i_t;                             // Calculo do datasheet 

  return tempk;                                     // Retorna o valor de temperatura calculado em Kelvin
 
}

double calculo_temperatura1 (float R){
  // essa funcao recebe o valor de resistencia do resistor e retorna o valor em Celcius

  double tempk = calculo_temperatura0(R);         // Chama a funcao que encontra o valor em Kelvin, a partir do valor de resistencia medida do termistor
  double tempc = tempk - 273.15;                  // Calcula o valor em Celcius a partir do valor encontrado em Kelvim

  return tempc;
 
}

double calculo_temp_cal1 (float R){
  // essa funcao recebe o valor de resistencia do resistor e retorna o valor em Kelvin
  // calculado a partir dos valores de coeficientes encontrados com a Calibracao 1 (0º, 100º e 35,4ºC)
   
  double Aum      = 3.3432563e-03;                   // Valor de A1 encontrado na calibracao 1
  double Bum      = 2.6025183e-04;                   // Valor de B1 encontrado na calibracao 1
  double Cum      = 4.9214600e-06;                   // Valor de C1 encontrado na calibracao 1

  double Rref    = 10000;                           // Valor da resistencia em 25graus Celcius

  
  double Rdiv    = R/Rref;                          // Valor adimensional resultante da divisao do valor de R pelo valor de Resistencia a 25 ºC, conforme calculo do datasheet
    
  double i_t = Aum + Bum*log(Rdiv) + Cum* pow(log(Rdiv),2);       // Calculo do datasheet, usando coeficientes calculados 
  double tempk = 1/i_t;                             // Calculo do datasheet 

  double tempc = tempk - 273.15; 
  return tempc;                                     // Retorna o valor de temperatura calculado em Celsius
 
}

double calculo_temp_cal2 (float R){
  // essa funcao recebe o valor de resistencia do resistor e retorna o valor em Kelvin
  // calculado a partir dos valores de coeficientes encontrados com a Calibracao 2 (0º, 100º,33,9ºC e 41,7ºC)
   
  double Aum      =  3.354099e-03;                   // Valor de A1 encontrado na calibracao 2
  double Bum      =  2.619226e-04;                   // Valor de B1 encontrado na calibracao 2
  double Cum      = -1.584360e-06;                   // Valor de C1 encontrado na calibracao 2
  double Dum      = -2.094466e-06;                   // Valor de D1 encontrado na calibracao 2

  double Rref    = 10000;                           // Valor da resistencia em 25graus Celcius

  
  double Rdiv    = R/Rref;                          // Valor adimensional resultante da divisao do valor de R pelo valor de Resistencia a 25 ºC, conforme calculo do datasheet
    
  double i_t = Aum + Bum*log(Rdiv) + Cum* pow(log(Rdiv),2) + Dum* pow(log(Rdiv),3);       // Calculo do datasheet 
  double tempk = 1/i_t;                             // Calculo do datasheet 

  double tempc = tempk - 273.15; 
  return tempc;                                     // Retorna o valor de temperatura calculado em Celsius
}

double calculo_temp_cal3 (float R){
  // essa funcao recebe o valor de resistencia do resistor e retorna o valor em Kelvin
  // calculado a partir dos valores de coeficientes encontrados com a Calibracao 3 (32,2ºC, 37,5ºC, 42,5ºC)
   
  double Aum      =  3.3440885e-03;                   // Valor de A1 encontrado na calibracao 3
  double Bum      =  2.3892993e-04;                   // Valor de B1 encontrado na calibracao 3
  double Cum      = -1.3030307e-05;                   // Valor de C1 encontrado na calibracao 3

  double Rref    = 10000;                           // Valor da resistencia em 25graus Celcius

  
  double Rdiv    = R/Rref;                          // Valor adimensional resultante da divisao do valor de R pelo valor de Resistencia a 25 ºC, conforme calculo do datasheet
    
  double i_t = Aum + Bum*log(Rdiv) + Cum* pow(log(Rdiv),2);       // Calculo do datasheet, usando coeficientes calculados 
  double tempk = 1/i_t;                             // Calculo do datasheet 

  double tempc = tempk - 273.15; 
  return tempc;                                     // Retorna o valor de temperatura calculado em Celsius
}

double calculo_temp_cal4 (float R){
  // essa funcao recebe o valor de resistencia do resistor e retorna o valor em Kelvin
  // calculado a partir dos valores de coeficientes encontrados com a Calibracao 4 (32,2ºC,34,5ºC 37,5ºC, 42,5ºC)
   
  double Aum      = 3.360734e-03;                   // Valor de A1 encontrado na calibracao 2
  double Bum      = 3.534920e-04;                   // Valor de B1 encontrado na calibracao 2
  double Cum      = 2.301034e-04;                   // Valor de C1 encontrado na calibracao 2
  double Dum      = 1.617165e-04;                   // Valor de D1 encontrado na calibracao 2

  double Rref    = 10000;                           // Valor da resistencia em 25graus Celcius

  
  double Rdiv    = R/Rref;                          // Valor adimensional resultante da divisao do valor de R pelo valor de Resistencia a 25 ºC, conforme calculo do datasheet
    
  double i_t = Aum + Bum*log(Rdiv) + Cum* pow(log(Rdiv),2) + Dum* pow(log(Rdiv),3);       // Calculo do datasheet 
  double tempk = 1/i_t;                             // Calculo do datasheet 

  double tempc = tempk - 273.15; 
  return tempc;                                     // Retorna o valor de temperatura calculado em Celsius
}
