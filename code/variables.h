/**
 * @file variables.h
 *
 * Este é o ficheiro que contém o header de todas as funções relacionadas com as variáveis. 
 * 
 */
#ifndef ___VARIABLES_H___
#define ___VARIABLES_H___

#include "pushpop.h"

/*
typedef struct variables {
        VAR variables[30];
} * VARIABLES;

typedef struct var {
        char letra;
        DATA valor;
} VAR;



#define bla (VAR, valor, letra)  \
VAR.letra = letra                \
VAR.valor = valor
*/

/**
 *
 * Esta é a struct responsável por conter o valor das variáveis.
 * 
 */
typedef struct variables {  
        DATA A; /** value A*/  
        DATA B; /** value B*/
        DATA C; /** value C*/
        DATA D; /** value D*/
        DATA E; /** value E*/
        DATA F; /** value F*/
        DATA G; /** value G*/
        DATA H; /** value H*/
        DATA I; /** value I*/ 
        DATA J; /** value J*/
        DATA K; /** value K*/
        DATA L; /** value L*/
        DATA M; /** value M*/
        DATA N; /** value N*/ 
        DATA O; /** value O*/
        DATA P; /** value P*/
        DATA Q; /** value Q*/ 
        DATA R; /** value R*/
        DATA S; /** value S*/
        DATA T; /** value T*/ 
        DATA U; /** value U*/ 
        DATA V; /** value V*/ 
        DATA W; /** value W*/ 
        DATA X; /** value X*/ 
        DATA Y; /** value Y*/ 
        DATA Z; /** value Z*/
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

/**
 *
 * Esta é a função que executa as instruções :<letra>,em que a variavel fica com o valor do topo da stack.
 * 
 */
void assvalue (char *token,STACK *s,VAR *x);

#endif