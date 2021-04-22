/**
 * @file parser.h 
 * 
 * Este é o ficheiro que contêm as declarações das funções do fichero parser.c.
 * 
 */
#ifndef ___PARSER_H___
#define ___PARSER_H___

#include "variables.h"
#include "pushpop.h"

/**
 *
 * Esta é o header da função que converte uma linha em tipo de dados STRING.
 * 
 */
void leituradatas (char *line,STACK *s);

/**
 *
 * Esta é o header da função que guarda a linha de comandos dada numa string.
 * 
 */
void preenche (char *line,char v[]);

/**
 *
 * Esta é o header da função responsável pelo parser da linha de comandos dada.
 * 
 */
void parse(char *line,STACK *s,VAR *x);

/**
 *
 * Esta é o header da função que faz o parse de dados tipo char e string.
 * 
 */
void parsedatas (char *token,STACK *s); 

/**
 *
 * Esta é o header da função que executa as instruções.
 * 
 */
void alloperations (char *token,STACK *s,VAR *x);

/**
 *
 * Esta é o header da função que faz o parse de dados tipo long e double.
 * 
 */
int parseNumbers (char *token,STACK *s);


#endif