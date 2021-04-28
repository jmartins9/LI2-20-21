/**
 * @file leituraInputs.h
 *
 * Este é o ficheiro que contém o header de todas as funções relacionadas com os comandos de leitura. 
 * 
 */
#ifndef ___LEITURAINPUTS_H___
#define ___LEITURAINPUTS_H___

#include "pushpop.h"

/**
 * 
 * Esta é o header da função responsável pela execução do comando l.  
 * 
 */
void loperation (STACK *s);
void toperation (STACK *s);
void leituraop (char *token,STACK *s);

#endif