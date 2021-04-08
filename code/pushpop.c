#include <stdio.h>
#include <stdlib.h>

#include "pushpop.h"

int has_type(DATA elem, int mask) {
  return (elem.type & mask) != 0;
}

int what_type (DATA d) {
    int r=0;
    if (d.type == LONG) r=1;
    if (d.type == DOUBLE) r=2;
    if (d.type == CHAR) r=4;
    if (d.type == STRING) r=8;
    return r;   
}

STACK *create_stack() {
  STACK *s = (STACK *) calloc(1, sizeof(STACK));
  s->size = 100;
  s->stack = (DATA *) calloc(s->size, sizeof(DATA));
  return s;
}

void push(STACK *s, DATA elem) {
  if(s->size == s->n_elems) {
    s->size += 100;
    s->stack = (DATA *) realloc(s->stack, s->size * sizeof(DATA));
  }
  s->stack[s->n_elems] = elem;
  s->n_elems++;
}

DATA pop(STACK *s) {
  s->n_elems--;
  return s->stack[s->n_elems];
}

DATA top(STACK *s) {
  return s->stack[s->n_elems - 1];
}

int is_empty(STACK *s) {
  return s->n_elems == 0;
}

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
    }
  }
  printf("\n");                               
}

