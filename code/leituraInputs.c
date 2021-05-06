/**
 * @file leituraInputs.c
 *
 * Este é o ficheiro que contém todas as funções relacionadas com os comandos de leitura. 
 * 
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "pushpop.h"




/**
 * 
 * Esta é a função responsável pela execução do comando l.  
 * 
 */
void loperation (STACK *s) {
    char line1[10000];
    assert( fgets (line1,10000,stdin) != NULL);
    assert( line1  [strlen (line1)-1] == '\n');
    DATA Z; make_datas(Z,STRING,line1);
    push(s,Z);
}

/**
 * 
 * Esta é a função responsável pela execução do comando t.  
 * 
 */
void toperation (STACK *s) {
    char line1[2000];
    char line2[10000];
    while (fgets (line1,2000,stdin) != NULL) {
           strcpy(line2+strlen(line2),line1);
    }
    assert( line2  [strlen (line2)-1] == '\n');
    DATA Z; make_datas(Z,STRING,line2);
    push(s,Z);
    
}

/**
 * 
 * Esta é a função responsável pela execução do comando p , que imprime o topo da stack.  
 * 
 */
void printtop (STACK *s) {
    DATA elem = top(s);
    TYPE type = elem.type;
    switch(type) {
      case LONG:
        printf("%ld", elem.elems.LONG); break;
      case DOUBLE:
        printf("%g", elem.elems.DOUBLE); break;
      case CHAR:
        printf("%c", elem.elems.CHAR); break;
      case STRING:
        printf("%s", elem.elems.STRING); break;
      case BLOCO:
        printf("%s", elem.elems.BLOCO); break;        
      case STACKK:
        print_stack(elem.elems.STACKK);break;
    }
    printf("\n");
} 

/**
 * 
 * Esta é a função responsável pela execução dos comandos de leitura dependendo do token.  
 * 
 */
void leituraop (char *token,STACK *s) {
     switch (*token)
     {
     case ('l'): loperation(s);break;
     case ('t'): toperation(s);break;
     case ('p'): printtop(s);break;
 
     }
}