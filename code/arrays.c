

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "pushpop.h"

char *get_token(char *line, char **rest) {
    char *delimitadores = " \t\n" ;
    int i=0, j=0;

    for (i=0; (strchr(delimitadores,line[i])==NULL) ; i++); //aumentar o valor de i ate ao indice final do token
    line[i] = '\0'; i++; //"fechar" o token e aumentar i para começar a preencher o rest
    for (j=0; line[i] != '\0'; j++) {
        (*rest)[j] = line[i+j]; //preencher o resto da linha no array rest. Secalhar ta mal pq rest é pointer de pointer de char.
    }
    (*rest)[j] = '\0';

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