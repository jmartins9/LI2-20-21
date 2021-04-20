/**
 * @file logicoperations.c 
 *
 * Este é o ficheiro que contém todas as funções relacionadas com as operações lógitas. 
 */
#include <stdio.h>
#include <string.h>
#include "logicoperations.h"
#include "pushpop.h"

/**
 *
 * Esta é a função que executa o comando =, ou seja, compara os dois elementos no topo da stack,
 * e introduz na stack o valor 0 ou 1 conforme o resultado.
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
 * Se o terceiro elemento a contar do topo da stack for diferente de 0, então devolve o topo da stack,
 * Caso contrário, devolve o elemento anterior ao topo da stack.
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



/**
 *
 * Esta é a função que executa o comando e<, ou seja, devolve o menor dos dois ultimos valores colocados na stack.
 * 
 */
void minoftwo (STACK *s) {
    DATA p1 = pop(s);
    DATA p2 = pop(s);
    DATA data;
    if (what_type (p1)==LONG && what_type(p2)==LONG) {
        long val = MIN(p1.elems.LONG,p2.elems.LONG);
        make_datas(data,LONG,val);
        push (s,data);
        }
    if (what_type (p1)==DOUBLE && what_type(p2)==LONG) {
        double val = MIN(p1.elems.DOUBLE,p2.elems.LONG);
        make_datas(data,DOUBLE,val);
        push (s,data);
    }
    if (what_type (p1)==DOUBLE && what_type(p2)==DOUBLE) {
        double val = MIN(p1.elems.DOUBLE,p2.elems.DOUBLE);
        make_datas(data,DOUBLE,val);
        push (s,data);
        }
    if (what_type (p1)==LONG && what_type(p2)==DOUBLE) {
        double val = MIN(p1.elems.LONG,p2.elems.DOUBLE);
        make_datas(data,DOUBLE,val);
        push (s,data);
        }
}



/**
 *
 * Esta é a função que executa o comando e>, ou seja, devolve o maior dos dois ultimos valores colocados na stack.
 * 
 */
void maxoftwo (STACK *s) {
    DATA p1 = pop(s);
    DATA p2 = pop(s);
    DATA data;
    if (what_type (p1)==LONG && what_type(p2)==LONG) {
        long val = MAX(p1.elems.LONG,p2.elems.LONG);
        make_datas(data,LONG,val);
        push (s,data);
        }
    if (what_type (p1)==DOUBLE && what_type(p2)==LONG) {
        double val = MAX(p1.elems.DOUBLE,p2.elems.LONG);
        make_datas(data,DOUBLE,val);
        push (s,data);
    }
    if (what_type (p1)==DOUBLE && what_type(p2)==DOUBLE) {
        double val = MAX(p1.elems.DOUBLE,p2.elems.DOUBLE);
        make_datas(data,DOUBLE,val);
        push (s,data);
        }
    if (what_type (p1)==LONG && what_type(p2)==DOUBLE) {
        double val = MAX(p1.elems.LONG,p2.elems.DOUBLE);
        make_datas(data,DOUBLE,val);
        push (s,data);
        }
}

/**
 *
 * Esta é a função que executa o comando e&, ou seja, devolve o segundo valor se os dois valores forem verdadeiros, caso contrário devolve 0.
 * 
 */
void andlogic (STACK *s) {
    DATA p1 = pop(s);
    DATA p2 = pop(s);
    if (p2.elems.LONG==0) push(s,p2);
    else push(s,p1);
}


/**
 *
 * Esta é a função que executa o comando e|, ou seja, devolve o primeiro valor se os dois valores forem verdadeiros, caso contrário devolve o valor verdadeiro.
 * Se forem os dois 0 devolve 0 à stack;
 * 
 */
void orlogic (STACK *s) {
    DATA p1 = pop(s);
    DATA p2 = pop(s);
    if (p2.elems.LONG==0) push(s,p1);
    else push(s,p2);
}

/**
 *
 * Esta é a função que executa o comando !, ou seja, devolve a negação do valor.
 * 
 */
void negate (STACK *s) {
    DATA p1 = pop(s);
    DATA data;
    if (what_type(p1)==LONG) {long val = !(p1.elems.LONG); make_datas(data,LONG,val); push(s,data);}
}

/**
 *
 * Esta é a função que recorre a outras funçõoes para executar as operações lógicas dependendo da instrução dada.
 * 
 */
void logicoperations (char *token,STACK *s) {
    if (strcmp(token,"=")==0) {equivalente(s);}
    else if (strcmp(token,"?")==0) {ifthenelse(s);}
    else if (strcmp(token,"e")==0) {pop(s);pop(s);}
    else if (strcmp(token,"e<")==0) {minoftwo(s);}
    else if (strcmp(token,"e>")==0) {maxoftwo(s);}
    else if (strcmp(token,"e&")==0) {andlogic(s);}
    else if (strcmp(token,"e|")==0) {orlogic(s);}
    else if (strcmp(token,"!")==0) {negate(s);}
}