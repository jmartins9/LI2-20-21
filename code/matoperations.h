/**
 * @file matoperations.h
 *
 * Este é o ficheiro que contém o header de todas as funções relacionadas com as operações matemáticas. 
 * 
 */
#ifndef ___MATOPERATIONS_H___
#define ___MATOPERATIONS_H___

#include <assert.h>
#include "pushpop.h"

/**
 *
 * Esta é o header da função que decide qual das operações matemáticas deve ser executada dependendo da instrução dada.
 * 
 */
void matoperations (char *token,STACK *s);

/**
 *
 * Este é o header da função que executa o comando +.
 * 
 */
void somar (STACK *S);

/**
 *
 * Este é o header da função que executa o comando -.
 * 
 */
void subtrair (STACK *S);

/**
 *
 * Este é o header da função que executa o comando *.
 * 
 */
void multiplicar (STACK *S);

/**
 *
 * Este é o header da função que executa o comando /.
 * 
 */
void divInteira (STACK *S);

/**
 *
 * Este é o header da função que executa o comando %.
 * 
 */
void divResto (STACK *S);

/**
 *
 * Este é o header da função que executa o comando ).
 * 
 */
void somarTop (STACK *S);

/**
 *
 * Este é o header da função que executa o comando (.
 * 
 */
void subtrairTop (STACK *s);

/**
 *
 * Este é o header da função que executa o comando #.
 * 
 */
void expoente (STACK *s);

/**
 *
 * Este é o header da função que executa o comando ~.
 * 
 */
void notBin (STACK *s);

/**
 *
 * Este é o header da função que executa o comando &.
 * 
 */
void andBin (STACK *s);

/**
 *
 * Este é o header da função que executa o comando |.
 * 
 */
void orBin (STACK *s);

/**
 *
 * Este é o header da função que executa o comando ^.
 * 
 */
void xorBin (STACK *s);
void handle_arithmetic (char *token,STACK *s);



#endif
