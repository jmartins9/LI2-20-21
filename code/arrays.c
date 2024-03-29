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
#include "blocos.h"

/**
 * 
 *  Função que separa o token do resto do input.
 *  
 *  \returns O token e o resto da linha.
 * 
 */
char *get_token(char *line, char **rest) { 
    char *delimitadores = " \t\n" ;
    while (strchr(delimitadores,*line)!=NULL && *line != '\0') {
        line++;
    }
    if (strlen(line) == 0) return NULL;
    //if (strlen(line) == 0 || *line == '\n' ) return NULL;

    int i=0;
    char *linenova = (char *) malloc((strlen(line)+1)* sizeof(char));
    strcpy(linenova,line);

    for (i=0; (strchr(delimitadores,linenova[i])==NULL) ; i++); //aumentar o valor de i ate ao indice final do primeiro token
    linenova[i++] = '\0';

    (*rest) = line + i;
    while ((strchr(delimitadores,**rest)!=NULL && **rest != '\0')) (*rest)++; //aumentar o valor do resto enquanto estiver em cima de uns dos delimitadores
    //para que ele aponte diretamente para um char que nao é espaços

    line = linenova;
    return line;
}

/**
 * 
 *  Função que separa o token de um array do resto do input.
 *  Dado que podem haver arrays uns dentro dos outros, utilizamos uma variável auxiliar que contava quantos parêntesis
 *  já tinham aparecido, de modo a não fechar o array mais cedo do que o suposto
 *  
 *  \returns O token e o resto da linha.
 * 
 */
char *get_delimited_array(char *line, char **rest) {
    char *linenova = (char*) malloc((strlen(line)+1)* sizeof(char));
    long unsigned int i=0;
    int j=0,k=0;
    for (i=0;i<strlen(line);i++) {
        if (line[i] == ']' && j<=0) break;
        else {
            //if (line[i+1] == ']' && j<=0) break;
            linenova[k] = line[i];
            k++;
        }
        if(line[i] == '[') j++;
        else if (line[i] == ']') j--;
    }
    linenova[k] = '\n'; //isto é perigoso
    linenova[k+1] = '\0';
    *rest = line + k + 2;
    line = linenova;
    return line;
}

/**
 * 
 *  Função que separa o token de uma string do resto do input.
 *  
 *  \returns O token e o resto da linha.
 * 
 */
char *get_delimited_string(char *line, char **rest) {
    char *linenova = (char*) malloc((strlen(line)+1)* sizeof(char));
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
 *  Função que cria uma string, e insere-a na stack. 
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
    else if(p1.type==STRING) {
         long tamanho=strlen(p1.elems.STRING);
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
 *  separa uma string por newlines. Dado que a função get_token, se usada recursivamente, atinge o mesmo objetivo,
 *  decidimos usá-la de maneira a ser mais eficiente.
 *  
 */
void separaWhitespace (STACK *s) {
     DATA p1 = pop(s);
     STACK *x=create_stack();
     char *token = (char*) malloc(sizeof(char) * 50);
     
     char *line;
     DATA tmp;
     if (p1.type==STRING) {
        line = strdup(p1.elems.STRING);
        char *rest[strlen(line)+1];
        *rest = (char*) malloc(sizeof(char)*(strlen(line)+1));
        for (token = get_token(line,rest); token != NULL; token = get_token(line,rest)) {
            make_datas(tmp,STRING,token);
            push(x,tmp);

            line = *rest;
        }
        make_datas(tmp,STACKK,x);
        push(s,tmp);
     }
     free(token);
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
         DATA p2;
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
             make_datas(p2,STRING,guardastring);
             push(x,p2);
         }
        pop(x);
        make_datas(p1,STACKK,x);
        push(s,p1);
     }
}


/**
 * 
 *  Função lê um token sobre operações relacionadas com arrays e manda executar as operações. 
 * 
 */
void arrayops (char *token,STACK *s) {
    if (strcmp(token,",")==0) tamanho_range(s);
    else if (strcmp(token,"S/")==0) separaWhitespace(s);
    else if (strcmp(token,"N/")==0) separaNewlines(s);
}
    
