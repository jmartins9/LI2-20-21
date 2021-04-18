/**
 * @file logicoperations.c 
 *
 * Este é o ficheiro que contém todas as funções relacionadas com as operações lógitas. 
 */
#include <stdio.h>
#include <string.h>
#include "pushpop.h"

/**
 *
 * Esta é a função que executa o comando =, ou seja, compara os dois elementos no topo da stack,
  e introduz na stack o valor 0 ou 1 conforme o resultado.
 * 
 */
void equivalente (STACK *s) { 
    DATA p1 = pop(s);
    DATA p2 = pop(s);
    DATA Z;
    //long p1long = p1.elems.LONG, p2long = p2.elems.LONG;
    //double p1double = p1.elems.DOUBLE, p2double = p2.elems.DOUBLE;
    if (what_type (p1)==LONG && what_type(p2)==LONG) {long equiv = p2.elems.LONG == p1.elems.LONG;make_datas(Z,LONG,equiv);}
    if (what_type (p1)==DOUBLE && what_type(p2)==LONG) {long equiv = p2.elems.LONG == p1.elems.DOUBLE;make_datas(Z,LONG,equiv);}
    if (what_type (p1)==DOUBLE && what_type(p2)==DOUBLE) {long equiv = p2.elems.DOUBLE == p1.elems.DOUBLE;make_datas(Z,LONG,equiv);}
    if (what_type (p1)==LONG && what_type(p2)==DOUBLE) {long equiv = p2.elems.DOUBLE == p1.elems.LONG;make_datas(Z,LONG,equiv);}            
    push (s,Z);  
}

/**
 *
 * Esta é a função que executa o comando ?, ou seja, executa um if then else:
    Se o terceiro elemento a contar do topo da stack for diferente de 0, então devolve o topo da stack,
    Caso contrário, devolve o elemento anterior ao topo da stack.
 * 
 */
void ifthenelse (STACK *s) {  //esta aqui provavelmente pode ser simplificada...
    DATA p1 = pop(s); //else
    DATA p2 = pop(s); //then
    DATA p3 = pop(s); //booleano a avaliar
    if (what_type (p3)==LONG) {
        if (p3.elems.LONG) {
            push(s,p2);
        } else {
            push(s,p1);
        }
    }
    else {
        if (p3.elems.DOUBLE) {
            push(s,p2);
        } else {
            push(s,p1);
        }
    }         
}

void logicoperations (char *token,STACK *s) {
    if (strcmp(token,"=")==0) {equivalente(s);}
    else if (strcmp(token,"?")==0) {ifthenelse(s);}
}