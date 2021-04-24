/**
 * @file variables.h
 *
 * Este é o ficheiro que contém o header de todas as funções relacionadas com as variáveis. 
 * 
 */
#ifndef ___VARIABLES_H___
#define ___VARIABLES_H___

#include "pushpop.h"


typedef struct var {
        char letra;
        DATA valor;
} VAR;

typedef struct variables {
        VAR * variables;
        int size;
        int n_elems;
} VARIABLES;

/**
 *
 * Esta é o header da função faz push do valor das variáveis para o topo da stack.
 * 
 */
void putVarTop (char *token,STACK *s,VARIABLES *x);

/**
 *
 * Esta é o header da função que executa as instruções relativas às variáveis dependendo do token.
 * 
 */
void varoperations (char *token,STACK *s,VARIABLES *x);


/**
 *
 * Esta é o header da função que inicia as variáveis.
 * 
 */
DATA omissionvalues (char token);

/**
 *
 * Esta é a função que executa as instruções :<letra>,em que a variavel fica com o valor do topo da stack.
 * 
 */
void assvalue (char *token,STACK *s,VARIABLES *x);

DATA darValor(char token, VARIABLES *x);

VARIABLES *create_varlist();

void pushvar(VARIABLES *vars, VAR var);

#endif