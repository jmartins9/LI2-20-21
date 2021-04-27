

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "pushpop.h"

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

STACK *eval (char *line, STACK *init_stack) {
    int i=0;

    if (init_stack == NULL) {
        init_stack = create_stack();
    }

    for (i=0; line[i] != '\0'; i++) {

    }

    return init_stack;
}
*/