/**
 * @file stackoperations.c 
 *
 * Este é o ficheiro que contém todas as funções relacionadas com as operações sobre a stack. 
 */
#include <stdio.h>
#include <string.h>
#include "pushpop.h"


/**
 *
 * Esta é a função que executa o comando ;, ou seja, retira o topo da stack.
 * 
 */
void retiratop (STACK *s) { 
     pop(s);
}


/**
 *
 * Esta é a função que executa o comando \, ou seja, altera a ordem dos dois elementos no topo da stack.
 * 
 */
void changetop2 (STACK *s) { 
    DATA p1 = pop(s);
    DATA p2 = pop(s);
    push(s,p1);
    push(s,p2);
}

/**
 *
 * Esta é a função que executa o comando _, ou seja, duplica o topo da stack.
 * 
 */
void duplicatop (STACK *s) { 
     DATA p1 =top(s);
     push(s,p1);
}

/**
 *
 * Esta é a função que executa o comando @, ou seja, altera a ordem dos três elementos no topo da stack.
 * 
 */
void changetop3 (STACK *s) { 
    DATA p1 = pop(s);
    DATA p2 = pop(s);
    DATA p3 = pop(s);
    push(s,p2);
    push(s,p1);
    push(s,p3);
}

/**
 *
 * Esta é a função que executa o comando n $, ou seja, copia o elemento na posição (topodastack - n) para o topo da stack.
 * 
 */
void copynelems (STACK *s) {//  $ 
     DATA p1 = pop(s);
     int in = p1.elems.LONG; 
     s->n_elems -= in;
     DATA p2 = top(s); 
     s->n_elems += in; 
     push(s,p2); 
}

/**
 *
 * Esta é a função que decide qual das operações sobre a stack deve ser executada dependendo da instrução dada.
 * 
 */
void stackoperations (char *token,STACK *s) {
    if (strcmp(token,"_")==0) {duplicatop(s);}
    else if (strcmp(token,";")==0) {retiratop(s);}
    else if (strcmp(token,"@")==0) {changetop3(s);}
    else if (strcmp(token,"$")==0) {copynelems(s);}
    else if (strcmp(token,"\\")==0) {changetop2(s);}    
}
