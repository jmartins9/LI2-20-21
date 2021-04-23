/**
 * @file convoperations.h
 *
 * Este é o ficheiro que contém o header de todas as funções relacionadas com as conversões. 
 * 
 */
#ifndef ___CONVOPERATIONS_H___
#define ___CONVOPERATIONS_H___

#include "pushpop.h"

/**
 *
 * Este é o header da função que executa o comando i.
 *
 */
void convertLong (STACK *s);

/**
 *
 * Este é o header da função que executa o comando f.
 *
 */
void convertFloat (STACK *s);

/**
 *
 * Este é o header da função que executa o comando c.
 *
 */
void convertChar (STACK *s);

/**
 *
 * Esta é o header da função que decide qual das operações de conversão deve ser executada dependendo da instrução dada.
 *
 */
void convoperations (char *token,STACK *s);


#endif