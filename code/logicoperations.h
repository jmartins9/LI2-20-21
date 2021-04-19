/**
 * @file stackoperations.h
 *
 * Este é o ficheiro que contém o header de todas as funções relacionadas com as operações lógicas. 
 * 
 */
#ifndef ___LOGICOPERATIONS_H___
#define ___LOGICOPERATIONS_H___

#include <assert.h>
#include "pushpop.h"

/**
 *
 * Esta é o header da função que decide qual das operações matemáticas deve ser executada dependendo da instrução dada.
 * 
 */
void logicoperations (char *token,STACK *s);

/**
 *
 * Esta é a função que executa o comando =, ou seja, compara os dois elementos no topo da stack.
 * 
 */
void equivalente (char *token,STACK *s);

/**
 *
 * Esta é a função que executa o comando ?, ou seja, executa um 'if then else' com os 3 elementos no topo da stack.
 * 
 */
void ifthenelse (char *token,STACK *s);

/**
 *
 * Esta é o header da função que executa o comando e>.
 * 
 */
void minoftwo (STACK *s);

/**
 *
 * Esta é o header da função que executa o comando e>.
 * 
 */
void maxoftwo (STACK *s);

/**
 *
 * Esta é o header da função que executa o comando e&.
 * 
 */
void andlogic (STACK *s); 

/**
 *
 * Esta é o header da função que executa o comando e|.
 * 
 */
void orlogic (STACK *s);

#endif