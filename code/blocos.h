/**
 * @file blocos.h
 *
 * Este é o ficheiro que contém o header de todas as funções relacionadas com os arrays. 
 * 
 */
#ifndef ___BLOCOS_H___
#define ___BLOCOS_H___

#include "variables.h"

/**
 *
 * Esta é o header da função que delimita a string do bloco, incluindo as chavetas.
 * 
 */
char *get_delimited_bloco(char *line, char **rest);

/**
 *
 * Esta é o header da função que cria o bloco, dando push à stack o mesmo.
 * 
 */
void criarBloco (char *line,STACK *s,char **rest);

/**
 *
 * Esta é o header da função que cria a string da parte parsável do bloco.
 * 
 */
char *criaexecBloco (DATA p1);

/**
 *
 * Esta é o header da função que executa o comando ~ para blocos.
 * 
 */
void executaBloco (STACK *s,VARIABLES *x);

/**
 *
 * Esta é o header da função que executa o comando % para blocos.
 * 
 */
void aplicaBloco (STACK *s,VARIABLES *x);
void aplicaBlocoString (DATA array_string,char *execbloco,STACK *s,VARIABLES *x);
void aplicaBlocoStack (DATA array_string,char *execbloco,STACK *s,VARIABLES *x);


/**
 *
 * Esta é o header da função que executa o comando , para blocos em arrays.
 * 
 */
void filtraBlocoArray (STACK *s, VARIABLES *x, char* execbloco);

/**
 *
 * Esta é o header da função que executa o comando , para blocos em strings.
 * 
 */
void filtraBlocoString (STACK *s, VARIABLES *x, char* execbloco);

/**
 *
 * Esta é o header da função que executa o comando , para blocos.
 * 
 */
void filtraBloco (STACK *s, VARIABLES *x);

/**
 *
 * Esta é o header da função que executa o comando * para blocos.
 * 
 */
void foldBloco (STACK *s, VARIABLES *x);

/**
 *
 * Esta é o header das funções que executam o comando $ para blocos, conforme este esteja vazio ou não.
 * 
 */
void ordenarBloco (STACK *s, VARIABLES *x);
void ordenaString (int tamanho,STACK *tmp,STACK *pilha);

/**
 *
 * Esta é o header da função que executa troca a posição de dois elementos na stack.
 * 
 */
void swapStack (STACK *s, int index1, int index2);

/**
 *
 * Esta é o header da função que executa o comando w para blocos.
 * 
 */
void executatruthy (STACK *s,VARIABLES *x);

/**
 *
 * Esta é o header da função que define a função que vai correr conforme o operador em blocos.
 * 
 */
void blocoOperations (char *token,STACK *s, VARIABLES *x);

#endif