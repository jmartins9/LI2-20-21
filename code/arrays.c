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
    //if (strlen(line) == 0 || *line == '\n' ) return NULL;

    int i=0;
    char *linenova = (char *) malloc(strlen(line) * sizeof(char));
    strcpy(linenova,line);

    for (i=0; (strchr(delimitadores,linenova[i])==NULL) ; i++); //aumentar o valor de i ate ao indice final do primeiro token
    linenova[i++] = '\0';

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

char *get_delimited_string(char *line, char **rest) {
    char *linenova = (char*) malloc(strlen(line) * sizeof(char));
    long unsigned int i=0;
    int k=0;
    for (i=0;i<strlen(line);i++) {
        if (line[i] == '"') break;
        else {
            linenova[k] = line[i];
            k++;
        }
    }
    linenova[k++] = '\0';
    *rest = line + k + 1;
    line = linenova;

    return line;
}

/**
 * 
 *  Função que cria um array e realiza as operaçoes nele contidas. 
 * 
 */
void criarString (char *line, STACK *s, char **rest) {
    char *token = get_delimited_string(line, rest);
    DATA Z; make_datas(Z,STRING,token);
    push(s,Z);
}

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
 *  Função que executa o comando 'S/' , ou seja, 
 *  separa uma string por newlines.
 *  
 */
void separaWhitespace (STACK *s) {
     DATA p1 = pop(s);
     STACK *x=create_stack();
     if (p1.type==STRING) {
         int i=0;
         while (p1.elems.STRING[i]!='\0') {
             int j=0;
             char *guardastring = (char *) malloc(strlen(p1.elems.STRING) * sizeof(char));
             while ((p1.elems.STRING[i]==' ' || p1.elems.STRING[i]=='\n' || p1.elems.STRING[i]=='\t') &&  p1.elems.STRING[i]!='\0') i++;
             while (p1.elems.STRING[i]!=' ' && p1.elems.STRING[i]!='\n' && p1.elems.STRING[i]!='\t' &&  p1.elems.STRING[i]!='\0') {
              guardastring[j]=p1.elems.STRING[i];
              j++;
              i++;
             } 
             guardastring[j]='\0';
             DATA p2;
             make_datas(p2,STRING,guardastring);
             push(x,p2);
            
         }
        make_datas(p1,STACKK,x);
        push(s,p1);
     }
}

/**
 * 
 *  Função que executa o comando 'N/' , ou seja, 
 *  separa uma string por newlines.
 *  
 */
void separaNewlines (STACK *s) {
     DATA p1 = pop(s);
     STACK *x=create_stack();
     if (p1.type==STRING) {
         int i=0;
         while (p1.elems.STRING[i]!='\0') {
             int j=0;
             char *guardastring = (char *) malloc(strlen(p1.elems.STRING) * sizeof(char));
             while (p1.elems.STRING[i]=='\n' &&  p1.elems.STRING[i]!='\0') i++;
             while (p1.elems.STRING[i]!='\n' && p1.elems.STRING[i]!='\0') {
              guardastring[j]=p1.elems.STRING[i];
              j++;
              i++;
             }
             guardastring[j]='\0';
             DATA p2;
             make_datas(p2,STRING,guardastring);
             push(x,p2);
         }
        make_datas(p1,STACKK,x);
        push(s,p1);
     }
}

char *get_delimited_array(char *line, char **rest) {
    char *linenova = (char*) malloc(strlen(line) * sizeof(char));
    long unsigned int i=0;
    int j=0,k=0;
    for (i=0;i<strlen(line);i++) {
        if (line[i] == ']' && j<=0) break;
        else {
            linenova[k] = line[i];
            k++;
        }
        if(line[i] == '[') j++;
        else if (line[i] == ']') j--;
    }
    linenova[k++] = '\0';
    *rest = line + k + 1;
    line = linenova;
    return line;
}

/**
 * 
 *  Função lê um token sobre operações relacionadas com arrays e manda executar as operações. 
 * 
 */
void arrayops (char *token,STACK *s) {
    if (strcmp(token,",")==0) tamanho_range(s);
    if (strcmp(token,"S/")==0) separaWhitespace(s);
    if (strcmp(token,"N/")==0) separaNewlines(s);
}