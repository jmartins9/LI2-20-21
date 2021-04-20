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
 * Esta é a função faz push do valor das variáveis para o topo da stack.
 * 
 */
void putVarTop (char *token,STACK *s,VAR *x) {
   switch (*token) {
     case ('A'): push(s,x->A);break;
     case ('B'): push(s,x->B);break;
     case ('C'): push(s,x->C);break;
     case ('D'): push(s,x->D);break;
     case ('E'): push(s,x->E);break;
     case ('F'): push(s,x->F);break;
     case ('N'): push(s,x->N);break;
     case ('S'): push(s,x->S);break;
     case ('X'): push(s,x->X);break;
     case ('Y'): push(s,x->Y);break;
     case ('Z'): push(s,x->Z);break;
     }  
}



/**
 *
 * Esta é a função que executa as instruções relativas às variáveis dependendo do token.
 * 
 */
void varoperations (char *token,STACK *s,VAR *x) {
     putVarTop (token,s,x);
     if (strcmp(token,":A")==0)  {    
             x->A = top (s);        
     }  
     else if (strcmp(token,":B")==0)  {    
             x->B = top (s);         
          }        
}


/**
 *
 * Esta é a função inicia as variáveis com os seus valores por omissão.
 * 
 */
VAR *omissionvalues () {
     VAR *x = (VAR *) calloc(1, sizeof(VAR));
     DATA A;make_datas(A,LONG,10);x->A=A;
     DATA B;make_datas(B,LONG,11);x->B=B;
     DATA C;make_datas(C,LONG,12);x->C=C;
     DATA D;make_datas(D,LONG,13);x->D=D;
     DATA E;make_datas(E,LONG,14);x->E=E;
     DATA F;make_datas(F,LONG,15);x->F=F;
     DATA N;make_datas(N,CHAR,'\n');x->N=N;
     DATA S;make_datas(S,CHAR,' ');x->S=S;
     DATA X;make_datas(X,LONG,0);x->X=X;
     DATA Y;make_datas(Y,LONG,1);x->Y=Y;
     DATA Z;make_datas(Z,LONG,2);x->Z=Z;
     return x;
}