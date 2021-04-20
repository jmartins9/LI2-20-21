/**
 * @file variables.c 
 *
 * Este é o ficheiro que contém todas as funções relacionadas com as variáveis. 
 */
#include <stdio.h>
#include <string.h>
#include "variables.h"
#include "pushpop.h"

/**
 *
 * Esta é a função faz push do valor das variáveis para o topo da stack.
 * 
 */
void putVarTop (char *token,STACK *s) {
   switch (*token) {
     case ('A'): push(s,A);break;
     case ('B'): push(s,B);break;
     case ('C'): push(s,C);break;
     case ('D'): push(s,D);break;
     case ('E'): push(s,E);break;
     case ('F'): push(s,F);break;
     case ('N'): push(s,N);break;
     case ('S'): push(s,S);break;
     case ('X'): push(s,X);break;
     case ('Y'): push(s,Y);break;
     case ('Z'): push(s,Z);break;
     }  
}



/**
 *
 * Esta é a função que executa as instruções relativas às variáveis dependendo do token.
 * 
 */
void varoperations (char *token,STACK *s) {
     putVarTop (token,s);
     if (strcmp(token,":A")==0)  {    
             DATA p1 = top (s);       
             if (what_type (p1)==LONG) {long val = p1.elems.LONG;make_datas(A,LONG,val);} 
     }  
     else if (strcmp(token,":B")==0)  {    
             DATA p1 = top (s);        
             if (what_type (p1)==LONG) {long val = p1.elems.LONG;make_datas(B,LONG,val);} 
          }        
}


/**
 *
 * Esta é a função inicia as variáveis com os seus valores por omissão.
 * 
 */
void omissionvalues () {
     make_datas(A,LONG,10);
     make_datas(B,LONG,11);
     make_datas(C,LONG,12);
     make_datas(D,LONG,13);
     make_datas(E,LONG,14);
     make_datas(F,LONG,15);
     make_datas(N,CHAR,'\n');
     make_datas(S,CHAR,' ');
     make_datas(X,LONG,0);
     make_datas(Y,LONG,1);
     make_datas(Z,LONG,2);
}