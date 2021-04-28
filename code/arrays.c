/**
 * @file arrays.c
 *
 * Este é o ficheiro que contém todas as funções relacionadas com os arrays. 
 * 
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "pushpop.h"
#include "variables.h"
#include "parser.h"

/**
 * 
 *  Função que separa o token do resto do input.
 *  
 *  \returns O token e o resto da linha.
 * 
 */
char *get_token(char *line, char **rest) {
    if (strlen(line) == 0) return NULL;
    char *delimitadores = " \t\n" ;
    while (strchr(delimitadores,*line)!=NULL && *line != '\0') {
        line++;
    }
    if (strlen(line) == 0 || *line == '\n') return NULL;
    int i=0;
    char *linenova = (char *) malloc(strlen(line) * sizeof(char));
    strcpy(linenova,line);

    for (i=0; (strchr(delimitadores,linenova[i])==NULL) ; i++); //aumentar o valor de i ate ao indice final do primeiro token
    linenova[i] = '\0';

    (*rest) = line + i;
    while ((strchr(delimitadores,**rest)!=NULL && **rest != '\0')) (*rest)++; //aumentar o valor do resto enquanto estiver em cima de uns dos delimitadores
    //para que ele aponte diretamente para um char que nao é espaços

    line = linenova;
    return line;
}

/*
char *get_delimited (char *line, char *seps, char **rest) {
    int i = 0, x=0;
    for (i=0; line[i] != '\0'; i++) {
        if (strstr(seps,line[i])!=NULL) x++;
    }
    return line;
}

*/

/**
 * 
 *  Função que cria um array e realiza as operaçoes nele contidas. 
 * 
 */
void criarArray (char *line, STACK *s,VARIABLES *x, char **rest) {
    char *token = get_delimited_array(line, rest);
    STACK *arrayS = NULL;
    arrayS = parse(token, arrayS, x);
    DATA Z; make_datas(Z,STACKK,arrayS);
    push(s,Z);
}


/**
 * 
 *  Função que executa o comando ',' , ou seja, 
 *  se for um array o topo da stack da-nos o seu tamanho, caso contrário cria um array.
 *  
 */
void tamanho_range (STACK *s) {
    DATA p1 = pop(s);
    if (p1.type==STACKK) {
      STACK *x = p1.elems.STACKK;
      long tamanho = x->n_elems;
      make_datas(p1,LONG,tamanho);
      push(s,p1);
    }
    else {
        int i;
        DATA p2;
        STACK *x=create_stack();
         for (i=0;i<p1.elems.LONG;i++) {
         make_datas(p2,LONG,i);
         push(x,p2);
        }
        make_datas(p2,STACKK,x);
        push(s,p2);
    }
}




/**
 * 
 *  Função lê um token sobre operações relacionadas com arrays e manda executar as operações. 
 * 
 */
void arrayops (char *token,STACK *s) {
     switch (*token)
     {
     case (','): tamanho_range(s); break; 
     
     }
}