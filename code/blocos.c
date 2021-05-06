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

void aplicaBloco (STACK *s,VARIABLES *x) {
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