/**
 * @file stackoperations.h
 *
 * Este é o ficheiro que contém o header de todas as funções relacionadas com as operções sobre a stack. 
 * 
 */
#ifndef ___STACKOPERATIONS_H___
#define ___STACKOPERATIONS_H___

#include <assert.h>
#include "pushpop.h"

/**
 *
 * Esta é o header daa função que decide qual das operações sobre a stack deve ser executada dependendo da instrução dada.
 * 
 */
void stackoperations (char *token,STACK *s,VARIABLES *x);

/**
 *
 * Este é o header da função que executa o comando ;.
 * 
 */
void retiratop (STACK *S);

/**
 *
 * Este é o header da função que executa o comando \.
 * 
 */
void changetop2 (STACK *s);

/**
 *
 * Este é o header da função que executa o comando _.
 * 
 */
void duplicatop (STACK *s);

/**
 *
 * Este é o header da função que executa o comando @.
 * 
 */
void changetop3 (STACK *s);

/**
 *
 * Este é o header da função que executa o comando n $.
 * 
 */
void copynelem (STACK *s);

#endif
