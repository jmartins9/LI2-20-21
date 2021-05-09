/**
 * @file blocos.c
 *
 * Este é o ficheiro que contém todas as funções relacionadas com os blocos. 
 * 
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "pushpop.h"
#include "variables.h"
#include "parser.h"
#include "matoperations.h"

/**
 *
 * Esta é a função responsável por delimitar a zona correspondente ao bloco.
 * Após a parse encontrar uma linha que começa com o caracter '{',
 * esta função cria a string que contém o bloco, e têm em conta os blocos aninhados.
 * 
 */
char *get_delimited_bloco(char *line, char **rest) {
    char *linenova = (char*) malloc((strlen(line)+1)* sizeof(char));
    long unsigned int i=0;
    int k=0, j=0;
    for (i=0;i<strlen(line);i++) {
        linenova[k] = line[i]; k++;
        if (line[i] == '}') {
            if (j<=1) break;
            j--;
        }
        else if(line[i] == '{') j++;
    }
    linenova[k]='\0';
    *rest = line + i + 1;

    return linenova;
}

/**
 *
 * Esta função é responsável por criar o bloco (chamando a função que o delimita),
 * e dá push à stack da string que contém o bloco.
 * 
 */
void criarBloco (char *line,STACK *s,char **rest) {
    char *token = get_delimited_bloco(line, rest);
    DATA d;
    make_datas(d,BLOCO,token);
    push(s,d);
}

/**
 *
 * Esta é a função que cria o array que contém a parte do bloco que necessita ser executada, ou
 * por outras palavras, parsada.
 * Ao contrário da função 'get_delimited_bloco', esta função vai apenas colocar no array a parte interior do bloco.
 * Dado que bastantes funções que operam com blocos necessitam de criar este array, esta função será chamada
 * em maior parte das funções e por isso é eficiente a existência desta função.
 * 
 */
char *criaexecBloco (DATA p1) {
     char *execbloco = (char *) calloc(sizeof(char),strlen(p1.elems.BLOCO)-3);
     int i,j=0;
     if (strcmp(p1.elems.BLOCO,"{ }")==0) {
         strcpy(execbloco," ");
         return execbloco;
     }
     int tamanho=strlen(p1.elems.BLOCO)-4;
     for (i=0;i<tamanho;i++) {
         if (p1.elems.BLOCO[i+2]=='}') {
             if (j<=0) break;
             j--;
         }
         else if (p1.elems.BLOCO[i+2]=='{') j++;
         execbloco[i]=p1.elems.BLOCO[i+2];
     }
     execbloco[++i]='\0';
     return execbloco;
}

/**
 *
 * Esta é a função responsável por executar o comando '~' quando opera num bloco.
 * Este operador aplica o bloco apenas ao elemento no topo da stack, portanto simplesmente
 * faremos o parse da stack, alterando apenas o elemento no topo da mesma.
 * 
 */
void executaBloco (STACK *s,VARIABLES *x) {
     DATA p1 = pop(s);
     char *execbloco = criaexecBloco(p1);
     s=parse(execbloco,s,x);
}

/**
 *
 * Esta é a função que executa o comando % quando opera num bloco.
 * Ao contrário da função 'executaBloco', esta função aplicará o bloco não só ao topo da stack,
 * mas sim a todos os elementos da stack.
 * O método que usamos funciona de maneira similar para arrays e para strings, e funciona da seguinte maneira:
 * Dado que se simplesmente fizessemos o parse da stack com o bloco, apenas seria modificado o topo da stack,
 * tivemos que arranjar maneira de fazer o parse a todos os elementos da stack, um a um.
 * Assim, a nossa função percorre o array/string, e coloca o elemento o primeiro elemento numa stack auxiliar,
 * e faz o parse dessa stack auxiliar, de seguida coloca o próximo elemento, e faz o parse, e assim em diante.
 * Deste modo, todos os elementos serão parsados pelo nosso bloco.
 * 
 */
void aplicaBloco (STACK *s,VARIABLES *x) {
     DATA bloco = pop (s);
     DATA array_string = pop (s);
    
     char *execbloco = criaexecBloco(bloco);


     if (array_string.type==STACKK) {
         int i;
         STACK *pilha=array_string.elems.STACKK;
         int tamanho=pilha->n_elems;
         STACK *tmp=create_stack();
         for (i=0;i<tamanho;i++) {
             pilha->n_elems=i+1;
             push(tmp,top(pilha));
             parse(execbloco,tmp,x);
         }
         DATA Z; make_datas(Z,STACKK,tmp);
         push(s,Z);
     }
     else {
         int i;
         int tamanho=strlen(array_string.elems.STRING);
         for (i=0;i<tamanho;i++) {
             STACK *tmp=create_stack();
             DATA data;
             make_datas(data,CHAR,array_string.elems.STRING[i]);
             push(tmp,data);
             parse(execbloco,tmp,x);
             if (top(tmp).type == CHAR) array_string.elems.STRING[i] = top(tmp).elems.CHAR;
         }
         push(s,array_string);
     }
}

/**
 *
 * Esta é a função que executa o comando ',' quando opera num bloco.
 * 
 * 
 */
void filtraBloco (STACK *s, VARIABLES *x) {
    DATA bloco = pop (s);
    DATA array_string = pop (s);
    int i;
    char *execbloco = criaexecBloco(bloco);

    if (array_string.type==STACKK) {
         int tamanho=array_string.elems.STACKK->n_elems;
         STACK *tmp=create_stack();
         for (i=0;i<tamanho;i++) {
             push(tmp,array_string.elems.STACKK->stack[i]);
             parse(execbloco,tmp,x);
             if (pop(tmp).elems.LONG) push(tmp,array_string.elems.STACKK->stack[i]);
         }
         array_string.elems.STACKK=tmp;
         push(s,array_string);
     }
    else if (array_string.type==STRING) {
          int tamanho = strlen(array_string.elems.STRING);
          STACK *tmp=create_stack();
          DATA d;
          int j=0;
          for (i=0;i<tamanho;i++) {
             make_datas(d,CHAR,array_string.elems.STRING[i]);
             push(tmp,d);
             parse(execbloco,tmp,x);
             if ((top(tmp).elems.LONG)) {
                 array_string.elems.STRING[j]=array_string.elems.STRING[i];
                 j++;
             } 
         }
         array_string.elems.STRING[j]='\0';         
         push(s,array_string);
    }
}

/**
 *
 * Esta é a função que executa o comando '*' , ou seja, faz o fold sobre um array usando um bloco.
 * 
 * 
 */
void foldBloco (STACK *s, VARIABLES *x) {
    DATA bloco = pop (s);
    DATA array_string = pop (s);
    
    char *execbloco = criaexecBloco(bloco);

    if (array_string.type==STACKK) {
        int i;
        int tamanho=array_string.elems.STACKK->n_elems;
        STACK *tmp=create_stack();
        push(tmp,array_string.elems.STACKK->stack[0]);
        for (i=1;i<tamanho;i++) {
            push(tmp,array_string.elems.STACKK->stack[i]);
            parse(execbloco,tmp,x);
        }
        array_string.elems.STACKK=tmp;
        push(s,array_string);
    }
}

/**
 *
 * Esta é uma função auxiliar à função 'ordenarBloco', e tem como objetivo trocar a posição de dois elementos numa stack.
 * 
 */
void swapStack (STACK *s, int index1, int index2) {
    DATA tmp;
    tmp = s->stack[index1];
    s->stack[index1] = s->stack[index2];
    s->stack[index2] = tmp;
}

/**
 *
 * Esta é uma função auxiliar às funções de ordenar, e tem como objetivo ordenar uma String.
 * 
 */
void ordenaString (int tamanho,STACK *tmp,STACK *pilha) {
    int i;
    int j;
    for (i=0; i<tamanho; i++) {
        for (j=0; j<tamanho-1; j++) {
            if (strcmp(tmp->stack[j].elems.STRING,tmp->stack[j+1].elems.STRING)>0) {
                        swapStack(pilha,j,j+1);
                        swapStack(tmp,j,j+1);
            }
        }
    }
}


/**
 *
 * Esta é a função que executa o comando $, ou seja, ordenar usando o bloco.
 * 
 */

void ordenarBloco (STACK *s,VARIABLES *x) {
    DATA bloco = pop (s);
    DATA array_string = pop (s);
    int i,j;
    char *execbloco = criaexecBloco(bloco);
 
    if (array_string.type==STACKK) {
        STACK *pilha=array_string.elems.STACKK; //Stack original nao mapada
        int tamanho=pilha->n_elems;
        STACK *tmp=create_stack(); //Stack mapada
        
        for (i=0;i<tamanho;i++) {
            push(tmp,pilha->stack[i]);
            parse(execbloco,tmp,x);
        }


        if ((tmp->stack[0]).type == LONG) { //entao vamos comparar inteiros?
            for (i=0; i<tamanho; i++) {
                for (j=0; j<tamanho-1; j++) {
                    if (tmp->stack[j].elems.LONG > tmp->stack[j+1].elems.LONG) {
                        swapStack(pilha,j,j+1);
                        swapStack(tmp,j,j+1);
                    }
                }
            }
        }
        else if ((tmp->stack[0]).type==STRING) {
                ordenaString(tamanho,tmp,pilha);
            }


        make_datas(array_string,STACKK,pilha);
        push(s,array_string);
    }
}

/**
 *
 * Esta é a função que executa o comando w, ou seja, executa o bloco enquanto ele deixar um truthy no topo da stack;
 * Remove da stack a condição.
 * 
 */
void executatruthy (STACK *s,VARIABLES *x) {
    DATA bloco = top(s);
    executaBloco(s,x);
    while (pop(s).elems.LONG) {
           push(s,bloco);
           executaBloco(s,x);
    }
}