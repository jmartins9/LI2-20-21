/**
 * @file arrays.h
 *
 * Este é o ficheiro que contém o header de todas as funções relacionadas com os arrays. 
 * 
 */
#ifndef ___ARRAYS_H___
#define ___ARRAYS_H___

/**
 * 
 * Header da função que divide uma linha em um tokem e o resto da mesma. 
 * 
 */
char *get_token(char *line, char **rest) ;

char *get_delimited_array(char *line, char **rest);

void criarArray (char *line, STACK *s,VARIABLES *x, char **rest);


#endif