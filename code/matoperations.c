/**
 * @file matoperations.c 
 *
 * Este é o ficheiro que contém todas as funções relacionadas com as operações matemáticas. 
 */
#include <stdio.h>
#include <string.h>
#include "pushpop.h"
#include <math.h>


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
 * Esta é a função que executa o comando (, ou seja, decrementa o elemento no topo da stack.
 * 
 */
void subtrairTop (STACK *s) { 
    DATA p1 = pop(s);
    DATA Z;
    if (what_type (p1)==LONG) {long inc = p1.elems.LONG-1;make_datas(Z,LONG,inc);}
    if (what_type (p1)==DOUBLE) {double inc = p1.elems.DOUBLE-1;make_datas(Z,DOUBLE,inc);}
    if (what_type (p1)==CHAR) {char inc = p1.elems.CHAR-1;make_datas(Z,CHAR,inc);}
    push (s,Z);
}

/**
 *
 * Esta é a função que executa o comando #, ou seja, vai elevar o valor do topo da stack ao seu valor anterior.
 * 
 */
void expoente (STACK *s) { 
    DATA p1 = pop(s);
    DATA p2 = pop(s);
    DATA Z;
    if (what_type (p1)==LONG && what_type(p2)==LONG) {long exp = pow(p2.elems.LONG,p1.elems.LONG);make_datas(Z,LONG,exp);}
    if (what_type (p1)==DOUBLE && what_type(p2)==LONG) {double exp = pow(p2.elems.LONG,p1.elems.DOUBLE);make_datas(Z,DOUBLE,exp);}
    if (what_type (p1)==DOUBLE && what_type(p2)==DOUBLE) {double exp = pow(p2.elems.DOUBLE,p1.elems.DOUBLE);make_datas(Z,DOUBLE,exp);}
    if (what_type (p1)==LONG && what_type(p2)==DOUBLE) {double exp = pow(p2.elems.DOUBLE,p1.elems.LONG);make_datas(Z,DOUBLE,exp);} 
    push (s,Z);           
}

/**
 *
 * Aqui damos o valor binário e nesta operação é invertida o seu valor, nomeadamente 0's passa para 1's e vice-versa
 * 
 */
void notBin (STACK *s) { 
    DATA p1 = pop(s);
    long not = ~p1.elems.LONG;
    DATA Z;
    make_datas(Z,LONG,not);
    push (s,Z);
}

/**
 *
 * Compara os elementos do inteiro em binário e verifica se tem numeros iguais nas mesmas posições
 * 
 */
void andBin (STACK *s) { 
    DATA p1 = pop(s);
    DATA p2 = pop(s);
    long e = p2.elems.LONG&p1.elems.LONG;
    DATA Z;
    make_datas(Z,LONG,e);
    push (s,Z);  
}             

/**
 *
 * Disjunção dos elementos bits, neste caso vê quais são iguais e os diferentes mas retorna os valores todos ("ou" em lógica)
 * 
 */
void orBin (STACK *s) { 
    DATA p1 = pop(s);
    DATA p2 = pop(s);
    long ou = p2.elems.LONG|p1.elems.LONG;
    DATA Z;
    make_datas(Z,LONG,ou);
    push (s,Z);     
}             

/**
 *
 * Verifica se os bits são iguais e retorna 0 se forem diferentes e 1 se forem iguais
 * 
 */
void xorBin (STACK *s) { 
    DATA p1 = pop(s);
    DATA p2 = pop(s);
    long xor = p2.elems.LONG^p1.elems.LONG;
    DATA Z;
    make_datas(Z,LONG,xor);
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
    else if (strcmp(token,"#")==0) {expoente(s);}  
    else if (strcmp(token,"(")==0) {subtrairTop(s);}  
    else if (strcmp(token,"~")==0) {notBin(s);}  
    else if (strcmp(token,"&")==0) {andBin(s);}  
    else if (strcmp(token,"|")==0) {orBin(s);}  
    else if (strcmp(token,"^")==0) {xorBin(s);}      
}