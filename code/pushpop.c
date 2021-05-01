/** 
 * @file pushpop.c 
 * 
 * Neste ficheiro encontram-se as funções responsáveis por manusear a stack e simplificar o processo de armanezamento de data.
 *  
 */  

#include <stdio.h>
#include <stdlib.h>

#include "pushpop.h"


/**
 *
 * Esta função recebe como argumento um elemento do tipo DATA, e devolve um inteiro correspondente ao tipo do elemento.
 * Utilizamos este método de modo a poder representar os tipos de data como inteiro (manuseamento mais fácil), também foi
 * necessário criar uma definição 'enum' de maneira a representar estes tipos como um inteiro.
 * 
 */
int what_type (DATA d) {
    int r=0;
    if (d.type == LONG) r=1;
    if (d.type == DOUBLE) r=2;
    if (d.type == CHAR) r=4;
    if (d.type == STRING) r=8;
    if (d.type == STACKK) r=16;
    return r;   
}

/**
 *
 * Esta função é utilizada para inicializar a stack. Esta é inicializada com tamanho 100, e é alocado espaço para armazenar
 * os elementos do tipo DATA. A stack também tem um parâmetro 'n_elems' que inicialmente toma valor 0, e representa a quantidade
 * elementos na stack.
 *
 */
STACK *create_stack() {
  STACK *s = (STACK *) calloc(1, sizeof(STACK));
  s->size = 5;
  s->stack = (DATA *) calloc(s->size, sizeof(DATA));
  return s;
}

/**
 *
 * Esta função recebe como argumento a stack e um elemento, e introduz-lo na stack. Além de adicionar o elemento
 * à stack na n-ésima posição, é necessário verificar se a stack está cheia antes de introduzir o elemento.
 * Caso esteja cheia (s->size == s->n_elems), então é realocado mais espaço na memória de modo a armazenar mais elementos.
 * 
 */
void push(STACK *s, DATA elem) {
  if(s->size == s->n_elems) {
    s->size += 5;
    s->stack = (DATA *) realloc(s->stack, s->size * sizeof(DATA));
  }
  s->stack[s->n_elems] = elem;
  s->n_elems++;
}

/**
 *
 * Esta função recebe como argumento a stack e devolve o elemento no topo da mesma, decrescendo o número de elementos.
 * 
 */
DATA pop(STACK *s) {
  s->n_elems--;
  return s->stack[s->n_elems];
}

/**
 *
 * Tal como a função pop, a função top devolve o elemento no topo da stack, mas não muda o número de elementos na stack.
 * 
 */
DATA top(STACK *s) {
  return s->stack[s->n_elems - 1];
}

/**
 *
 * Esta função devolve um inteiro (booleano) que representa se a stack está vazia.
 * 
 */
int is_empty(STACK *s) {
  return s->n_elems == 0;
}

/**
 *
 * A função print_stack, como o nome indica, dá print aos elementos da stack.
 * Esta função percorre todos os elementos do array que guarda os elementos, e verifica o tipo do dado elemento
 * De seguida é executado um switch em que se verifica qual é o tipo do elemento, e dá print conforme o mesmo.
 * 
 */
void print_stack(STACK *s) {
  for(int K = 0; K < s->n_elems; K++) {
    DATA elem = s->stack[K];
    TYPE type = elem.type;
    switch(type) {
      case LONG:
        printf("%ld", elem.elems.LONG); break;
      case DOUBLE:
        printf("%g", elem.elems.DOUBLE); break;
      case CHAR:
        printf("%c", elem.elems.CHAR); break;
      case STRING:
        printf("%s", elem.elems.STRING); break;
      case STACKK:
        print_stack(elem.elems.STACKK);break;
    }
  }
}

