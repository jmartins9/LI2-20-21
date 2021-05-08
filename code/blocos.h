/**
 * @file blocos.h
 *
 * Este é o ficheiro que contém o header de todas as funções relacionadas com os arrays. 
 * 
 */
#ifndef ___BLOCOS_H___
#define ___BLOCOS_H___

#include "variables.h"

char *get_delimited_bloco(char *line, char **rest);
void criarBloco (char *line,STACK *s,char **rest);
char *criaexecBloco (DATA p1);
void executaBloco (STACK *s,VARIABLES *x);
void aplicaBloco (STACK *s,VARIABLES *x);
void filtraBloco (STACK *s, VARIABLES *x);
void foldBloco (STACK *s, VARIABLES *x);
void ordenarBloco (STACK *s, VARIABLES *x);
void ordenaSeNaoForVazio (STACK *s,VARIABLES *x,DATA bloco,DATA array_string);
void ordenaSeForVazio (STACK *s,DATA array_string);
void swapStack (STACK *s, int index1, int index2);
void executatruthy (STACK *s,VARIABLES *x);

#endif