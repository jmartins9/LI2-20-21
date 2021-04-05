/**
 * @file pushpop.h 
 * 
 * Este é o ficheiro que contêm as declarações das funções do ficheiro pushpop.c
 * 
 */
#ifndef ___STACK_H___
#define ___STACK_H___

#include <assert.h>

typedef enum {LONG = 1, DOUBLE = 2, CHAR = 4, STRING = 8} TYPE;

#define INTEGER  (LONG | CHAR)
#define NUMBER   (INTEGER | DOUBLE)


typedef struct data {
  TYPE   type;
  union {
  long   LONG;
  double DOUBLE;
  char   CHAR;
  char*  STRING;
  } elems;
} DATA;

typedef struct stack {
  DATA *stack;
  int size;
  int n_elems;
} STACK;

int has_type(DATA elem, int mask);
STACK *create_stack();
void push(STACK *s, DATA elem);
DATA pop(STACK *s);
DATA top(STACK *s);
int is_empty(STACK *s);
void print_stack(STACK *s);

#endif