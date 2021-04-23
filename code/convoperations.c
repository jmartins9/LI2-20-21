/**
 * @file convoperations.c
 *
 * Este é o ficheiro que contém todas as funções relacionadas com as conversões. 
 * 
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "variables.h"
#include "pushpop.h"

/**
 *
 * Esta é a função que executa o comando i, ou seja, converte o topo da stack em long.
 *
 */
void convertLong (STACK *s) {
    DATA data;
    DATA p1 = pop(s);
    if (what_type (p1)==LONG) {long conv = p1.elems.LONG;make_datas(data,LONG,conv);}
    if (what_type (p1)==DOUBLE) {long conv = p1.elems.DOUBLE;make_datas(data,LONG,conv);}
    if (what_type (p1)==CHAR) {long conv = p1.elems.CHAR;make_datas(data,LONG,conv);}
    if (what_type (p1)==STRING) {long conv = strtol(p1.elems.STRING,NULL,10);make_datas(data,LONG,conv);}
    push (s,data);
}

/**
 *
 * Esta é a função que executa o comando f, ou seja, converte o topo da stack em float.
 *
 */
void convertFloat (STACK *s) {
    DATA data;
    DATA p1 = pop(s);
    if (what_type (p1)==LONG) {float conv = p1.elems.LONG;make_datas(data,DOUBLE,conv);}
    if (what_type (p1)==DOUBLE) {float conv = p1.elems.DOUBLE;make_datas(data,DOUBLE,conv);}
    if (what_type (p1)==CHAR) {float conv = p1.elems.CHAR;make_datas(data,DOUBLE,conv);}
    if (what_type (p1)==STRING) {float conv = strtod(p1.elems.STRING,NULL);make_datas(data,DOUBLE,conv);}
    push (s,data);
}

/**
 *
 * Esta é a função que executa o comando c, ou seja, converte o topo da stack em char.
 *
 */
void convertChar (STACK *s) {
    DATA p1 = pop(s);
    DATA data;
    if (what_type (p1)==LONG) {char conv = p1.elems.LONG;make_datas(data,CHAR,conv);}
    if (what_type (p1)==DOUBLE) {char conv = p1.elems.DOUBLE;make_datas(data,CHAR,conv);}
    if (what_type (p1)==CHAR) {char conv = p1.elems.CHAR;make_datas(data,CHAR,conv);}
    push(s,data);
}

/**
 *
 * Esta é a função que decide qual das operações de conversão deve ser executada dependendo da instrução dada.
 *
 */
void convoperations (char *token,STACK *s) {
    switch (*token) {
        case ('f'): convertFloat(s);break;
        case ('c'): convertChar(s);break;
        case ('i'): convertLong(s);break;
    }
}



