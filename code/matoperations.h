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

/**
 *
 * Este é o header da função que decide a operação a executar conforme o tipo dos elementos no topo da stack.
 * 
 */
void handle_arithmetic (char *token,STACK *s);

/**
 *
 * Este é o header da função que coloca os elementos de um array na stack.
 * 
 */
void putArrayStack (STACK *s);

/**
 *
 * Este é o header da função que concatena arrays.
 * 
 */
void concatenateArrays (STACK *s,DATA array1,DATA array2);
void concatenateStrings (STACK *s,DATA array1,DATA array2);



#endif
