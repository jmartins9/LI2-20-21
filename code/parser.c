/** 
 * @file parser.c 
 * 
 * Neste ficheiro do trabalho é onde se vai suceder as operações aritméticas ou operações bitwise de inteiros.
 * Depois procedemos a criar a parse que é onde vamos trabalhar com as operações aritméticas usando
 * a função pop e a função push. O push recebe um argumenta um argumento mas não retorne nenhum; este argumento é introduzindo no topo da 
 * stack. O pop é mais ou menos o inverso, não recebe nenhum argumento e retorna um inteiro, sendo o valor que está no topo da stack e 
 * remove-o da stack, visto que o valor foi impresso.
 *  
 */  
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "parser.h"
#include "pushpop.h"



#define make_datas(var, TYPE, value)     \
        var.elems.TYPE =value;           \
        var.type       =TYPE;                      



/**
 * Esta é a função responsável pelas operações aritméticas com os valores e instruções dadas para a stack.  
 * As operações aritméticas são:
 * Operação para a soma;
 * Operação para a subtração;
 * Operação para a multiplicação;
 * Operação para a divisão;
 * Operação para o resto da divisão entre dois valores;
 * Operação de incrementar: Ao último valor adicionado á stack vai incrementar uma unidade;
 * Operação de decrementar: Ao último valor adicionado á stack vai decrementar uma unidade;
 * Operação de Exponenciação : Operação para a potência de um valor pelo outro (X elevado a Y);
 * Operação E (bitwise);
 * Operação ou (bitwise);
 * Operação xor (bitwise);
 * Operação not (bitwise);
 */
void parse(char *line) {
     STACK *s = create_stack();
     char *sobra;
     char *delimitadores = " \t\n" ;
     for (char *token = strtok(line, delimitadores); token != NULL ; token = strtok (NULL, delimitadores)) {
         DATA X;
         float F;
         long L;
         L=strtol (token,&sobra,10);
         F=strtod (token,&sobra);
         if (strlen(sobra)==0) {
         if (F==L) {
         make_datas(X, LONG, L);push (s,X);} 
         else {
         make_datas(X, DOUBLE, F);push (s,X);}  
         }
         else if (strcmp(token,"+")==0) {
             DATA p1 = pop(s);
             DATA p2 = pop(s);
             long soma = p2.elems.LONG+p1.elems.LONG;
             DATA Z;
             make_datas(Z,LONG,soma);
             push (s,Z);  
              }     
         else if (strcmp(token,"-")==0) {
             DATA p1 = pop(s);
             DATA p2 = pop(s);
             long sub = p2.elems.LONG-p1.elems.LONG;
             DATA Z;
             make_datas(Z,LONG,sub);
             push (s,Z);                  
         } 
         else if (strcmp(token,"*")==0) {
             DATA p1 = pop(s);
             DATA p2 = pop(s);
             long mult = p2.elems.LONG*p1.elems.LONG;
             DATA Z;
             make_datas(Z,LONG,mult);
             push (s,Z);                 
         } 
         else if (strcmp(token,"/")==0) {
             DATA p1 = pop(s);
             DATA p2 = pop(s);
             long div = p2.elems.LONG/p1.elems.LONG;
             DATA Z;
             make_datas(Z,LONG,div);
             push (s,Z);                       
         }
         else if (strcmp(token,"%")==0) {
             DATA p1 = pop(s);
             DATA p2 = pop(s);
             long mod = p2.elems.LONG%p1.elems.LONG;
             DATA Z;
             make_datas(Z,LONG,mod);
             push (s,Z);                    
         }
         else if (strcmp(token,")")==0) {
             DATA p1 = pop(s);
             long inc = p1.elems.LONG + 1;
             DATA Z;
             make_datas(Z,LONG,inc);
             push (s,Z);                 
         }
         else if (strcmp(token,"(")==0) {
             DATA p1 = pop(s);
             long dec = p1.elems.LONG - 1;
             DATA Z;
             make_datas(Z,LONG,dec);
             push (s,Z);                        
         }
         else if (strcmp(token,"#")==0) {
             DATA p1 = pop(s);
             DATA p2 = pop(s);
             long exp = pow(p2.elems.LONG,p1.elems.LONG);
             DATA Z;
             make_datas(Z,LONG,exp);
             push (s,Z);                        
         }
         else if (strcmp(token,"~")==0) {      
             DATA p1 = pop(s);
             long not = ~p1.elems.LONG;
             DATA Z;
             make_datas(Z,LONG,not);
             push (s,Z);                        //Aqui damos o valor binário e nesta operação é invertida o seu valor, nomeadamente 0's passa para 1's e vice-versa 
         }                                      
         else if (strcmp(token,"&")==0) {
             DATA p1 = pop(s);
             DATA p2 = pop(s);
             long e = p2.elems.LONG&p1.elems.LONG;
             DATA Z;
             make_datas(Z,LONG,e);
             push (s,Z);                       //Compara os elementos do inteiro em binário e verifica se tem numeros iguais nas mesmas posições  
         }    
         else if (strcmp(token,"|")==0) {
             DATA p1 = pop(s);
             DATA p2 = pop(s);
             long ou = p2.elems.LONG|p1.elems.LONG;
             DATA Z;
             make_datas(Z,LONG,ou);
             push (s,Z);                     //Disjunção dos elementos bits, neste caso vê quais são iguais e os diferentes mas retorna os valores todos ("ou" em lógica)
         }                                      
         else if (strcmp(token,"^")==0) {
             DATA p1 = pop(s);
             DATA p2 = pop(s);
             long xor = p2.elems.LONG^p1.elems.LONG;
             DATA Z;
             make_datas(Z,LONG,xor);
             push (s,Z);                     //Verifica se os bits são iguais e retorna 0 se forem diferentes e 1 se forem iguais
         }
         else if (strlen(token)==1) {
         make_datas(X, CHAR, *token);push (s,X);}
         else if (strlen(token)>1) { 
         make_datas(X, STRING,strdup(token));push (s,X);}
     }
    print_stack (s);
} 
