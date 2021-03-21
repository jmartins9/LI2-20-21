#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "pushpop.h"

void parse(char *line) {
     char *delimitadores = " \t\n" ;
     for (char *token = strtok(line, delimitadores); token != NULL ; token = strtok (NULL, delimitadores)) {
         printf ("%s\n",token); 
     }
}