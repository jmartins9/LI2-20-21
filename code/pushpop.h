/**
 * @file pushpop.h 
 * 
 * Este é o ficheiro que contêm as declarações das funções do ficheiro pushpop.c
 * 
 */
#ifndef ___STACK_H___
#define ___STACK_H___

#include <assert.h>

/*!
 *
 * De modo a simplificar o manuseamento de dados, criamos uma definição 'enum' de maneira a representar os tipos como inteiros.
 * 
 */
typedef enum {LONG = 1,  /** tipo de dados LONG*/ 
              DOUBLE = 2, /** tipo de dados DOUBLE*/ 
              CHAR = 4,  /** tipo de dados CHAR*/
              STRING = 8   /** tipo de dados STRING*/
              } 
              TYPE;



/*!
 *
 * Esta struct é responsável por definir o tipo (data) de cada elemento da stack.
 * Da maneira que a stack está criada, é possível, no mesmo array, possuir elementos que representam tipos de dados
 * diferentes, dado que todos tem o tipo DATA.
 * 
 */
typedef struct data {
  TYPE   type; /** tipo do elemnento guardado*/ 
  union {
  long   LONG; /** tipo de dados LONG*/ 
  double DOUBLE; /** tipo de dados DOUBLE*/ 
  char   CHAR; /** tipo de dados CHAR*/
  char*  STRING; /** tipo de dados STRING*/
  } elems;
} DATA;  /**< variável struct DATA. */

/*!
 *
 * Nesta definição da stack, é criado um array de elementos do tipo DATA (de maneira a ter elementos diferentes no mesmo array),
 * é definido o tamanho da stack (size), e o número de elementos da stack (será 0 no início).
 * 
 */
typedef struct stack{
  DATA *stack; /** apontador para elementos da stack*/
  int size; /** tamanho do array de DATAS */
  int n_elems; /** apontador do topo da stack */
} STACK;  /**< variavel struct STACK. */

/**
 *
 * Esta macro é utilizada para simplificar o modo de criação de um elemento.
 * Por exemplo, para introduzir o inteiro 3 na stack, é neccessário este ser do tipo DATA.
 * Logo, será necessário definir o tipo do elemento DATA, e o respetivo valor.
 * Assim, através desta macro é facilitado este processo.
 * 
 */
#define make_datas(var, TYPE, value)     \
        var.elems.TYPE =value;           \
        var.type       =TYPE;                      


/**
 *
 * Definições dos headers das funções em pushpop.c
 * 
 */
int has_type(DATA elem, int mask);
int what_type (DATA d);
STACK *create_stack();
void push(STACK *s, DATA elem);
DATA pop(STACK *s);
DATA top(STACK *s);
int is_empty(STACK *s);
void print_stack(STACK *s);

#endif