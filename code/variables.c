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
     switch (*token)
     {
     case (':'): assvalue (token+1,s,x);break; // atribui valores a variaveis
     }   
}


/**
 *
 * Esta é a função inicia as variáveis com os seus valores por omissão.
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

DATA darValor(char token, VARIABLES *x) {
     int i = 0;
     DATA Z;
     Z = omissionvalues(token);
     for (i=0; i< x->n_elems; i++) {
          if (token == (x->variables[i]).letra) {
               Z = (x->variables[i]).valor;
          }
     }
     return Z;
}

VARIABLES *create_varlist() {
  VARIABLES *vars = (VARIABLES *) calloc(1, sizeof(VARIABLES));
  vars->size = 100;
  vars->variables = (VAR *) calloc(vars->size, sizeof(VAR));
  return vars;
}

void pushvar(VARIABLES *vars, VAR var) {
  if(vars->size == vars->n_elems) {
    vars->size += 100;
    vars->variables = (VAR *) realloc(vars->variables, vars->size * sizeof(VAR));
  }
  vars->variables[vars->n_elems] = var;
  vars->n_elems++;
}