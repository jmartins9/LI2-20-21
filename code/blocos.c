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

char *get_delimited_bloco(char *line, char **rest) {
    char *linenova = (char*) malloc((strlen(line)+1)* sizeof(char));
    long unsigned int i=0;
    int k=0;
    for (i=0;i<strlen(line);i++) {
        if (line[i] == '}') break;
        else {
            linenova[k] = line[i];
            k++;
        }
    }
    if (line[i]=='}') {
        linenova[k]=line[i];
        k++;
    }
    linenova[k]='\0';
    *rest = line + i + 1;

    return linenova;
}

void criarBloco (char *line,STACK *s,char **rest) {
    char *token = get_delimited_bloco(line, rest);
    DATA d;
    make_datas(d,BLOCO,token);
    push(s,d);
}

void executaBloco (STACK *s,VARIABLES *x) {
     DATA p1 = pop(s);
     char *execbloco = (char *) calloc(sizeof(char),strlen(p1.elems.BLOCO)-4);
     int i;
     int tamanho=strlen(p1.elems.BLOCO)-4;
     for (i=0;i<tamanho;i++) {
         if (p1.elems.BLOCO[i+2]=='}') break;
         else execbloco[i]=p1.elems.BLOCO[i+2];
     }
     execbloco[++i]='\0';

     s=parse(execbloco,s,x);
}

void aplicaBloco (STACK *s,VARIABLES *x) {
     DATA bloco = pop (s);
     DATA array_string = pop (s);
    
     char *execbloco = (char *) calloc(sizeof(char),strlen(bloco.elems.BLOCO)-4);
     int j;
     int length=strlen(bloco.elems.BLOCO)-4;
     for (j=0;j<length;j++) {
         if (bloco.elems.BLOCO[j+2]=='}') break;
         else execbloco[j]=bloco.elems.BLOCO[j+2];
     }
     execbloco[++j]='\0';


     if (array_string.type==STACKK) {
         int i;
         STACK *pilha=array_string.elems.STACKK;
         int tamanho=pilha->n_elems;
         STACK *tmp=create_stack();
         for (i=0;i<tamanho;i++) {
             pilha->n_elems=i+1;
             //STACK *tmp=create_stack();
             push(tmp,top(pilha));
             parse(execbloco,tmp,x);
             //DATA data;
             //make_datas(data,STACKK,tmp);
             //push(s,data);
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
             array_string.elems.STRING[i] = top(tmp).elems.CHAR;
         }
         push(s,array_string);
     }
}

void filtraBloco (STACK *s, VARIABLES *x) {
    DATA bloco = pop (s);
    DATA array_string = pop (s);
    
    char *execbloco = (char *) calloc(sizeof(char),strlen(bloco.elems.BLOCO)-4);
    int j;
    int length=strlen(bloco.elems.BLOCO)-4;
    for (j=0;j<length;j++) {
        if (bloco.elems.BLOCO[j+2]=='}') break;
        else execbloco[j]=bloco.elems.BLOCO[j+2];
    }
    execbloco[++j]='\0';

    if (array_string.type==STACKK) {
         int i;
         STACK *pilha=array_string.elems.STACKK;
         int tamanho=pilha->n_elems;
         for (i=0;i<tamanho;i++) {
             STACK *tmp=create_stack();
             push(tmp,pilha->stack[i]);
             parse(execbloco,tmp,x);
             if (pop(tmp).elems.LONG) push(tmp,pilha->stack[i]);
             DATA data;
             make_datas(data,STACKK,tmp);
             push(s,data);
         }
     }
}

void foldBloco (STACK *s, VARIABLES *x) {
    DATA bloco = pop (s);
    DATA array_string = pop (s);
    
    char *execbloco = (char *) calloc(sizeof(char),strlen(bloco.elems.BLOCO)-4);
    int j;
    int length=strlen(bloco.elems.BLOCO)-4;
    for (j=0;j<length;j++) {
        if (bloco.elems.BLOCO[j+2]=='}') break;
        else execbloco[j]=bloco.elems.BLOCO[j+2];
    }
    execbloco[++j]='\0';

    if (array_string.type==STACKK) {
        int i;
        STACK *pilha=array_string.elems.STACKK;
        int tamanho=pilha->n_elems;
        STACK *tmp=create_stack();
        push(tmp,pilha->stack[0]);
        for (i=1;i<tamanho;i++) {
            push(tmp,pilha->stack[i]);
            parse(execbloco,tmp,x);
        }
        DATA data;
        make_datas(data,STACKK,tmp);
        push(s,data);
    }
}

void swapStack (STACK *s, int index1, int index2) {
    DATA tmp;
    tmp = s->stack[index1];
    s->stack[index1] = s->stack[index2];
    s->stack[index2] = tmp;
}


void ordenaSeForVazio (STACK *s,DATA array_string) {
        if (array_string.type==STACKK) {
        int i,j;
        STACK *pilha=array_string.elems.STACKK; //Stack original nao mapada
        int tamanho=pilha->n_elems;
        STACK *tmp=create_stack(); //Stack mapada
        for (i=0;i<tamanho;i++) {
            push(tmp,pilha->stack[i]);
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
            for (i=0; i<tamanho; i++) {
                for (j=0; j<tamanho-1; j++) {
                    if (strcmp(tmp->stack[j].elems.STRING,tmp->stack[j+1].elems.STRING)>0) {
                        swapStack(pilha,j,j+1);
                        swapStack(tmp,j,j+1);
                    }
                }
            }
        }


        DATA data;
        make_datas(data,STACKK,pilha);
        push(s,data);
    }
}


void ordenaSeNaoForVazio (STACK *s,VARIABLES *x,DATA bloco,DATA array_string) {
    char *execbloco = (char *) calloc(sizeof(char),strlen(bloco.elems.BLOCO)-4);
    int j;
    int length=strlen(bloco.elems.BLOCO)-4;
    for (j=0;j<length;j++) {
        if (bloco.elems.BLOCO[j+2]=='}') break;
        else execbloco[j]=bloco.elems.BLOCO[j+2];
    }
    execbloco[++j]='\0';

    if (array_string.type==STACKK) {
        int i,j;
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
            for (i=0; i<tamanho; i++) {
                for (j=0; j<tamanho-1; j++) {
                    if (strcmp(tmp->stack[j].elems.STRING,tmp->stack[j+1].elems.STRING)>0) {
                        swapStack(pilha,j,j+1);
                        swapStack(tmp,j,j+1);
                    }
                }
            }
        }


        DATA data;
        make_datas(data,STACKK,pilha);
        push(s,data);
    }
}

void ordenarBloco (STACK *s, VARIABLES *x) {
    DATA bloco = pop (s);
    DATA array_string = pop (s);
    if (strlen(bloco.elems.BLOCO)<=3) {
        ordenaSeForVazio(s,array_string);
    }
    else {
        ordenaSeNaoForVazio(s,x,bloco,array_string);
    }
}

void executatruthy (STACK *s,VARIABLES *x) {
    DATA bloco = top(s);
    executaBloco(s,x);
    while (pop(s).elems.LONG) {
           push(s,bloco);
           executaBloco(s,x);
    }
}