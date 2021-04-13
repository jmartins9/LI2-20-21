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
#include <assert.h>
#include "parser.h"
#include "pushpop.h"




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
void parse(char *line,STACK *s) {
     char *sobra;
     char *sobra1;
     char *delimitadores = " \t\n" ;
     for (char *token = strtok(line, delimitadores); token != NULL ; token = strtok (NULL, delimitadores)) {
         DATA X;
         float F;
         long L;
         L=strtol (token,&sobra,10);
         F=strtod (token,&sobra1);
         if (strlen(sobra1)==0) {
          if (strlen(sobra)!=0) {make_datas(X,DOUBLE,F);push (s,X);} 
          else {make_datas(X, LONG, L);push (s,X);}
         }
         else if (strcmp(token,"l")==0) {
                  char line1[10240];
                  assert( fgets (line1,10240,stdin) != NULL);
                  assert( line1  [strlen (line1)-1] == '\n');
                  parse(line1,s);
  
         }
         else if (strcmp(token,"i")==0) {
             DATA Z;
             DATA p1 = pop(s);
             if (what_type (p1)==LONG) {long conv = p1.elems.LONG;make_datas(Z,LONG,conv);}
             if (what_type (p1)==DOUBLE) {long conv = p1.elems.DOUBLE;make_datas(Z,LONG,conv);}
             if (what_type (p1)==CHAR) {long conv = p1.elems.CHAR;make_datas(Z,LONG,conv);}
             //if (what_type (p1)==LONG) {long conv = p1.elems.STRING;make_datas(Z,LONG,conv);}      
             push (s,Z);
         }
         else if (strcmp(token,"+")==0) {
             DATA p1 = pop(s);
             DATA p2 = pop(s);
             DATA Z;
             if (what_type (p1)==LONG && what_type(p2)==LONG) {long soma = p2.elems.LONG+p1.elems.LONG;make_datas(Z,LONG,soma);}
             if (what_type (p1)==DOUBLE && what_type(p2)==LONG) {double soma = p2.elems.LONG+p1.elems.DOUBLE;make_datas(Z,DOUBLE,soma);}
             if (what_type (p1)==DOUBLE && what_type(p2)==DOUBLE) {double soma = p2.elems.DOUBLE+p1.elems.DOUBLE;make_datas(Z,DOUBLE,soma);}
             if (what_type (p1)==LONG && what_type(p2)==DOUBLE) {double soma = p2.elems.DOUBLE+p1.elems.LONG;make_datas(Z,DOUBLE,soma);}            
             push (s,Z);  
        }
        else if (strcmp(token,"-")==0) {
             DATA p1 = pop(s);
             DATA p2 = pop(s);
             DATA Z;
             if (what_type (p1)==LONG && what_type(p2)==LONG) {long subtracao = p2.elems.LONG-p1.elems.LONG;make_datas(Z,LONG,subtracao);}
             if (what_type (p1)==DOUBLE && what_type(p2)==LONG) {double subtracao = p2.elems.LONG-p1.elems.DOUBLE;make_datas(Z,DOUBLE,subtracao);}
             if (what_type (p1)==DOUBLE && what_type(p2)==DOUBLE) {double subtracao = p2.elems.DOUBLE-p1.elems.DOUBLE;make_datas(Z,DOUBLE,subtracao);}
             if (what_type (p1)==LONG && what_type(p2)==DOUBLE) {double subtracao = p2.elems.DOUBLE-p1.elems.LONG;make_datas(Z,DOUBLE,subtracao);} 
             push (s,Z);         
         } 
          else if (strcmp(token,"*")==0) {
             DATA p1 = pop(s);
             DATA p2 = pop(s);
             DATA Z;
             if (what_type (p1)==LONG && what_type(p2)==LONG) {long mult = p2.elems.LONG*p1.elems.LONG;make_datas(Z,LONG,mult);}
             if (what_type (p1)==DOUBLE && what_type(p2)==LONG) {double mult = p2.elems.LONG*p1.elems.DOUBLE;make_datas(Z,DOUBLE,mult);}
             if (what_type (p1)==DOUBLE && what_type(p2)==DOUBLE) {double mult = p2.elems.DOUBLE*p1.elems.DOUBLE;make_datas(Z,DOUBLE,mult);}
             if (what_type (p1)==LONG && what_type(p2)==DOUBLE) {double mult = p2.elems.DOUBLE*p1.elems.LONG;make_datas(Z,DOUBLE,mult);} 
             push (s,Z);                 
         } 
         else if (strcmp(token,"/")==0) {
             DATA p1 = pop(s);
             DATA p2 = pop(s);
             DATA Z;
             if (what_type (p1)==LONG && what_type(p2)==LONG) {long div = p2.elems.LONG/p1.elems.LONG;make_datas(Z,LONG,div);}
             if (what_type (p1)==DOUBLE && what_type(p2)==LONG) {double div = p2.elems.LONG/p1.elems.DOUBLE;make_datas(Z,DOUBLE,div);}
             if (what_type (p1)==DOUBLE && what_type(p2)==DOUBLE) {double div = p2.elems.DOUBLE/p1.elems.DOUBLE;make_datas(Z,DOUBLE,div);}
             if (what_type (p1)==LONG && what_type(p2)==DOUBLE) {double div = p2.elems.DOUBLE/p1.elems.LONG;make_datas(Z,DOUBLE,div);} 
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
             DATA Z;
             if (what_type (p1)==LONG) {long inc = p1.elems.LONG+1;make_datas(Z,LONG,inc);}
             if (what_type (p1)==DOUBLE) {double inc = p1.elems.DOUBLE+1;make_datas(Z,DOUBLE,inc);}
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
         else if (strcmp(token,"@")==0) {
             DATA p1 = pop(s);
             DATA p2 = pop(s);
             DATA p3 = pop(s);

             push(s,p2);
             push(s,p1);
             push(s,p3);
         }
         else if (strcmp(token,"_")==0) {
             DATA p1 = pop(s);

             push(s,p1);
             push(s,p1);
         }
         else if (strcmp(token,"\\")==0) {
             DATA p1 = pop(s);
             DATA p2 = pop(s);

             push(s,p1);
             push(s,p2);
         }
         else if (strcmp(token,"c")==0) {
             DATA p1 = pop(s);

             char c = p1.elems.LONG;
             DATA Z;
             make_datas(Z,CHAR,c);
             push(s,Z);
         }
         else if (strlen(token)==1) {
         make_datas(X, CHAR, *token);push (s,X);}
         else if (strlen(token)>1) { 
         make_datas(X, STRING,strdup(token));push (s,X);}
     }
} 
