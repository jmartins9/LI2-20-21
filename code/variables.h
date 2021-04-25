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
 * \struct
 * Nesta struct é definida o tipo VAR, que representa uma variável, armazenando o seu valor e o char correspondente à variável.
 * 
 */
typedef struct var /**< var - struct definida */
{
        char letra; /**< Caratere que nos diz a variável correspondente ao valor guardado */
        DATA valor; /**< Valor DATA que guarda o valor da variável */
} VAR; /**< Variável struct VAR */

/**
 * \struct
 * Nesta definição da stack de variáveis, é criado um array de elementos do tipo VAR (de maneira a armazenar as variáveis),
 * é definido o tamanho da stack de variáveis (size), e o número de elementos da mesma (será 0 no início).
 * 
 */
typedef struct variables /**< variables - struct definida */
{
        VAR * variables; /**< Array de dados do tipo Var */
        int size; /**< Tamanho do array */
        int n_elems; /**< Variável que contem a posiçao seguinte a ser preenchida */
} VARIABLES; /**< Variável struct VARIABLES */

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

/**
 *
 * Esta é o header da função que atribui o valor às variáveis.
 * 
 */
DATA darValor(char token, VARIABLES *x);

/**
 *
 * Esta é o header da função que cria a stack de variáveis.
 * 
 */
VARIABLES *create_varlist();

/**
 *
 * Esta é o header da função que introduz variáveis na stack de variáveis.
 * 
 */
void pushvar(VARIABLES *vars, VAR var);

#endif