/**
 * @file variables.c 
 *
 * Este é o ficheiro que contém todas as funções relacionadas com as variáveis. 
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "variables.h"
#include "pushpop.h"

/**
 *
 * Esta é a função que executa as instruções :<letra>,em que a variavel fica com o valor do topo da stack.
 * 
 */
void assvalue (char *token,STACK *s,VARIABLES *x) {
     DATA p1 = top(s);
     VAR V;
     V.letra = * token;
     V.valor = p1;
     pushvar(x,V);
}

/**
 *
 * Esta é a função que executa as instruções relativas às variáveis dependendo do token.
 * 
 */
void varoperations (char *token,STACK *s,VARIABLES *x) {
     DATA z;
     switch (*token)
     {
     case (':'): assvalue (token+1,s,x);break; // atribui valores a variaveis
     default : z = darValor(*token,x); push(s,z); 
     }   
}


/**
 *
 * Esta é a função que recebe um char, e devolve o seu valor de omissão.
 * 
 */
DATA omissionvalues (char token) {
     DATA Z;
     switch (token) {
          case ('A'): make_datas(Z,LONG,10);break;
          case ('B'): make_datas(Z,LONG,11);break;
          case ('C'): make_datas(Z,LONG,12);break;
          case ('D'): make_datas(Z,LONG,13);break;
          case ('E'): make_datas(Z,LONG,14);break;
          case ('F'): make_datas(Z,LONG,15);break;
          case ('X'): make_datas(Z,LONG,0);break;
          case ('Y'): make_datas(Z,LONG,1);break;
          case ('Z'): make_datas(Z,LONG,2);break;
          case ('N'): make_datas(Z,CHAR,'\n');break;
          case ('S'): make_datas(Z,CHAR,' ');break;
     }
     return Z;
}

/**
 *
 * Esta função recebe um char e um pointer para a stack de variáveis, e atribui valor a uma variável.
 * - Inicialmente é atribuido à variável o seu valor de omissão, para o caso da variável não ter sido definida;
 * - De seguida, é encontrado o valor que foi atribuido à variável (se foi atribuido), através de um ciclo for que percorre
 *   todas as variáveis que foram introduzidas na stack de variáveis.
 * 
 */
DATA darValor(char token, VARIABLES *x) {
     int i = 0;
     DATA Z = omissionvalues(token);
     for (i=0; i< x->n_elems; i++) {
          if (token == (x->variables[i]).letra) {
               Z = (x->variables[i]).valor;
          }
     }
     return Z;
}

/**
 *
 * Esta função é responsável por criar a stack de variáveis (funciona da mesma maneira que a função que cria a stack).
 * A stack de variáveis é inicializada com 100 de tamanho.
 * 
 */
VARIABLES *create_varlist() {
  VARIABLES *vars = (VARIABLES *) calloc(1, sizeof(VARIABLES));
  vars->size = 100;
  vars->variables = (VAR *) calloc(vars->size, sizeof(VAR));
  return vars;
}

/**
 *
 * Esta é a função que é responsável por introduzir novas variáveis e os seus respetivos valores à stack.
 * Ela recebe a stack de variáveis, e a variável a introduzir.
 * Tal como a função push principal, é verificado se atingiu o tamanho máximo e é realocado espaço se assim for necessário.
 * 
 */
void pushvar(VARIABLES *vars, VAR var) {
  if(vars->size == vars->n_elems) {
    vars->size += 100;
    vars->variables = (VAR *) realloc(vars->variables, vars->size * sizeof(VAR));
  }
  vars->variables[vars->n_elems] = var;
  vars->n_elems++;
}