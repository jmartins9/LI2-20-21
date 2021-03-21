#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "parser.h"
#include "pushpop.h"


void print_stack (int v[],int N) {
    int i;
    for (i=0;i<N;i++) {
        printf("%d",v[i]);
    }
}

void parse(char *line) {
     char *sobra;
     char *delimitadores = " \t\n" ;
     for (char *token = strtok(line, delimitadores); token != NULL ; token = strtok (NULL, delimitadores)) {
         long valor = strtol (token,&sobra,10);
         if (strlen(sobra)==0) {
             push (valor);
         }
         else if (strcmp(token,"+")==0) {
             long Y = pop();
             long X = pop();
             push (X+Y);
         } 
         else if (strcmp(token,"-")==0) {
             long Y = pop();
             long X = pop();
             push (X-Y);
         } 
         else if (strcmp(token,"*")==0) {
             long Y = pop();
             long X = pop();
             push (X*Y);
         } 
         else if (strcmp(token,"/")==0) {
             long Y = pop();
             long X = pop();
             push (X/Y);
         }
         else if (strcmp(token,"%")==0) {
             long Y = pop();
             long X = pop();
             push (X%Y);
         }
         else if (strcmp(token,")")==0) {
             long Y = pop();
             push (Y+1);
         }
         else if (strcmp(token,"(")==0) {
             long Y = pop();
             push (Y-1);
         }
         else if (strcmp(token,"#")==0) {
             long Y = pop();
             long X = pop();
             long res = pow(X,Y);
             push (res);
         }
     }
    print_stack (stack,conta);
}