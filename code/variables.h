/**
 * @file variables.h
 *
 * Este é o ficheiro que contém o header de todas as funções relacionadas com as variáveis. 
 * 
 */
#ifndef ___VARIABLES_H___
#define ___VARIABLES_H___

#include "pushpop.h"


typedef struct variables {  
        DATA A;
        DATA B;
        DATA C;
        DATA D;
        DATA E;
        DATA F;
        DATA N;
        DATA S;
        DATA X;
        DATA Y;
        DATA Z;
} VAR;

/**
 *
 * Esta é o header da função faz push do valor das variáveis para o topo da stack.
 * 
 */
void putVarTop (char *token,STACK *s,VAR *x);

/**
 *
 * Esta é o header da função que executa as instruções relativas às variáveis dependendo do token.
 * 
 */
void varoperations (char *token,STACK *s,VAR *x);


/**
 *
 * Esta é o header da função que inicia as variáveis.
 * 
 */
VAR *omissionvalues ();

#endif