/**
 * @file matoperations.c 
 *
 * Este é o ficheiro que contém todas as funções relacionadas com as operações matemáticas. 
 */
#include <stdio.h>
#include <string.h>
#include "pushpop.h"


/**
 *
 * Esta é a função que executa o comando +, ou seja, soma os dois elementos no topo da stack.
 * 
 */
void somar (STACK *s) { 
    DATA p1 = pop(s);
    DATA p2 = pop(s);
    DATA Z;
    if (what_type (p1)==LONG && what_type(p2)==LONG) {long soma = p2.elems.LONG+p1.elems.LONG;make_datas(Z,LONG,soma);}
    if (what_type (p1)==DOUBLE && what_type(p2)==LONG) {double soma = p2.elems.LONG+p1.elems.DOUBLE;make_datas(Z,DOUBLE,soma);}
    if (what_type (p1)==DOUBLE && what_type(p2)==DOUBLE) {double soma = p2.elems.DOUBLE+p1.elems.DOUBLE;make_datas(Z,DOUBLE,soma);}
    if (what_type (p1)==LONG && what_type(p2)==DOUBLE) {double soma = p2.elems.DOUBLE+p1.elems.LONG;make_datas(Z,DOUBLE,soma);}            
    push (s,Z);  
}

/**
 *
 * Esta é a função que executa o comando -, ou seja, subtrai os dois elementos no topo da stack.
 * 
 */
void subtrair (STACK *s) { 
    DATA p1 = pop(s);
    DATA p2 = pop(s);
    DATA Z;
    if (what_type (p1)==LONG && what_type(p2)==LONG) {long subtracao = p2.elems.LONG-p1.elems.LONG;make_datas(Z,LONG,subtracao);}
    if (what_type (p1)==DOUBLE && what_type(p2)==LONG) {double subtracao = p2.elems.LONG-p1.elems.DOUBLE;make_datas(Z,DOUBLE,subtracao);}
    if (what_type (p1)==DOUBLE && what_type(p2)==DOUBLE) {double subtracao = p2.elems.DOUBLE-p1.elems.DOUBLE;make_datas(Z,DOUBLE,subtracao);}
    if (what_type (p1)==LONG && what_type(p2)==DOUBLE) {double subtracao = p2.elems.DOUBLE-p1.elems.LONG;make_datas(Z,DOUBLE,subtracao);} 
    push (s,Z); 
}

/**
 *
 * Esta é a função que executa o comando *, ou seja, multiplica os dois elementos no topo da stack.
 * 
 */
void multiplicar (STACK *s) { 
    DATA p1 = pop(s);
    DATA p2 = pop(s);
    DATA Z;
    if (what_type (p1)==LONG && what_type(p2)==LONG) {long mult = p2.elems.LONG*p1.elems.LONG;make_datas(Z,LONG,mult);}
    if (what_type (p1)==DOUBLE && what_type(p2)==LONG) {double mult = p2.elems.LONG*p1.elems.DOUBLE;make_datas(Z,DOUBLE,mult);}
    if (what_type (p1)==DOUBLE && what_type(p2)==DOUBLE) {double mult = p2.elems.DOUBLE*p1.elems.DOUBLE;make_datas(Z,DOUBLE,mult);}
    if (what_type (p1)==LONG && what_type(p2)==DOUBLE) {double mult = p2.elems.DOUBLE*p1.elems.LONG;make_datas(Z,DOUBLE,mult);} 
    push (s,Z); 
}

/**
 *
 * Esta é a função que executa o comando /, ou seja, faz a divisão inteira dos dois elementos no topo da stack.
 * 
 */
void divInteira (STACK *s) { 
    DATA p1 = pop(s);
    DATA p2 = pop(s);
    DATA Z;
    if (what_type (p1)==LONG && what_type(p2)==LONG) {long div = p2.elems.LONG/p1.elems.LONG;make_datas(Z,LONG,div);}
    if (what_type (p1)==DOUBLE && what_type(p2)==LONG) {double div = p2.elems.LONG/p1.elems.DOUBLE;make_datas(Z,DOUBLE,div);}
    if (what_type (p1)==DOUBLE && what_type(p2)==DOUBLE) {double div = p2.elems.DOUBLE/p1.elems.DOUBLE;make_datas(Z,DOUBLE,div);}
    if (what_type (p1)==LONG && what_type(p2)==DOUBLE) {double div = p2.elems.DOUBLE/p1.elems.LONG;make_datas(Z,DOUBLE,div);} 
    push (s,Z);   
}

/**
 *
 * Esta é a função que executa o comando %, ou seja, calcula o resto da divisão entre os dois elementos no topo da stack.
 * 
 */
void divResto (STACK *s) { 
    DATA p1 = pop(s);
    DATA p2 = pop(s);
    long mod = p2.elems.LONG%p1.elems.LONG;
    DATA Z;
    make_datas(Z,LONG,mod);
    push (s,Z);
}

/**
 *
 * Esta é a função que executa o comando ), ou seja, incrementa o elemento no topo da stack.
 * 
 */
void somarTop (STACK *s) { 
    DATA p1 = pop(s);
    DATA Z;
    if (what_type (p1)==LONG) {long inc = p1.elems.LONG+1;make_datas(Z,LONG,inc);}
    if (what_type (p1)==DOUBLE) {double inc = p1.elems.DOUBLE+1;make_datas(Z,DOUBLE,inc);}
    if (what_type (p1)==CHAR) {char inc = p1.elems.CHAR+1;make_datas(Z,CHAR,inc);}
    push (s,Z); 
}


/**
 *
 * Esta é a função que decide qual das operações matemáticas deve ser executada dependendo da instrução dada.
 * 
 */
void matoperations (char *token,STACK *s) {
    if (strcmp(token,"+")==0) {somar(s);}
    else if (strcmp(token,"-")==0) {subtrair(s);}
    else if (strcmp(token,"*")==0) {multiplicar(s);}
    else if (strcmp(token,"/")==0) {divInteira(s);}
    else if (strcmp(token,"%")==0) {divResto(s);} 
    else if (strcmp(token,")")==0) {somarTop(s);}    
}