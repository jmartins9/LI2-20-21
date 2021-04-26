

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "pushpop.h"

char *get_token(char *line, char **rest) {
    if (strlen(line) == 0) return NULL;

    printf("cp1 %s\n", line);

    const char *delimitadores = " \t\n\0" ;
    int i=0;
    char *linenova = (char *) malloc(strlen(line) * sizeof(char));
    strcpy(linenova,line);

    printf("cp2 %s\n", linenova);

    for (i=0; (strchr(delimitadores,linenova[i])==NULL) ; i++); //aumentar o valor de i ate ao indice final do primeiro token
    linenova[i] = '\0';

    printf("cp3 %s\n", linenova);

    (*rest) = line + i + 1;

    line = linenova;

    printf("cp4 %s\n", line);
    printf("resto e .%s.\n", *rest);
    
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