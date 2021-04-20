/**
 * @file variables.h
 *
 * Este é o ficheiro que contém o header de todas as funções relacionadas com as variáveis. 
 * 
 */
#ifndef ___VARIABLES_H___
#define ___VARIABLES_H___

#include "pushpop.h"

/**
 * Variável global A.
 */
DATA A;
/**
 * Variável global B.
 */
DATA B;
/**
 * Variável global C.
 */
DATA C;
/**
 * Variável global D.
 */
DATA D;
/**
 * Variável global E.
 */
DATA E;
/**
 * Variável global F.
 */
DATA F;
/**
 * Variável global N.
 */
DATA N;
/**
 * Variável global S.
 */
DATA S;
/**
 * Variável global X.
 */
DATA X;
/**
 * Variável global Y.
 */
DATA Y;
/**
 * Variável global Z.
 */
DATA Z;


/**
 *
 * Esta é o header da função faz push do valor das variáveis para o topo da stack.
 * 
 */
void putVarTop (char *token,STACK *s);

/**
 *
 * Esta é o header da função que executa as instruções relativas às variáveis dependendo do token.
 * 
 */
void varoperations(char *token,STACK *s);


/**
 *
 * Esta é o header da função que inicia as variáveis.
 * 
 */
void omissionvalues ();

#endif