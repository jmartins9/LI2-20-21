/**
 * @file variables.c 
 *
 * Este é o ficheiro que contém todas as funções relacionadas com as variáveis. 
 */
#include <stdio.h>
#include <string.h>
#include "variables.h"
#include "pushpop.h"

void varoperations (char *token,STACK *s) {
     DATA data;
     switch (*token) {
     case ('A'): make_datas(data,LONG,A);push(s,data);break;
     case ('B'): make_datas(data,LONG,B);push(s,data);break;
     case ('C'): make_datas(data,LONG,C);push(s,data);break;
     case ('D'): make_datas(data,LONG,D);push(s,data);break;
     case ('E'): make_datas(data,LONG,E);push(s,data);break;
     case ('F'): make_datas(data,LONG,F);push(s,data);break;
     case ('N'): make_datas(data,CHAR,N);push(s,data);break;
     case ('S'): make_datas(data,CHAR,S);push(s,data);break;
     case ('X'): make_datas(data,LONG,X);push(s,data);break;
     case ('Y'): make_datas(data,LONG,Y);push(s,data);break;
     case ('Z'): make_datas(data,LONG,Z);push(s,data);break;
     }
     
}



