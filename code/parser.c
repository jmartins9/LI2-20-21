#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "parser.h"
#include "pushpop.h"

/* Neste ficheiro do trabalho é onde se vai suceder as operações aritméticas ou operações bitwise de inteiros. Começamos por criar uma
   função onde imprimimos a nossa stack. Depois procedemos a criar a parse que é onde vamos trabalhar com as operações aritméticas usando
   a função pop e a função push. O push recebe um argumenta um argumento mas não retorne nenhum; este argumento é introduzindo no topo da 
   stack. O pop é mais ou menos o inverso, não recebe nenhum argumento e retorna um inteiro, sendo o valor que está no topo da stack e 
   remove-o da stack, visto que o valor foi impresso. */  

// Imprimir a stack

void print_stack (int v[],int N) {
    int i;
    for (i=0;i<N;i++) {
        printf("%d",v[i]);
    }
    printf("\n");
}

// Operações aritméticas com os valores dados para a stack  

void parse(char *line) {
     char *sobra;
     char *delimitadores = " \t\n" ;
     for (char *token = strtok(line, delimitadores); token != NULL ; token = strtok (NULL, delimitadores)) {
         long valor = strtol (token,&sobra,10);
         if (strlen(sobra)==0) {
             push (valor);
         }
         else if (strcmp(token,"+")==0) {
             long Y = pop();
             long X = pop();
             push (X+Y);                        // Operação para a soma
         } 
         else if (strcmp(token,"-")==0) {
             long Y = pop();
             long X = pop();
             push (X-Y);                        // Operação para a subtração
         } 
         else if (strcmp(token,"*")==0) {
             long Y = pop();
             long X = pop();
             push (X*Y);                        // Operação para a multiplicação
         } 
         else if (strcmp(token,"/")==0) {
             long Y = pop();
             long X = pop();
             push (X/Y);                        // Operação para a divisão
         }
         else if (strcmp(token,"%")==0) {
             long Y = pop();
             long X = pop();
             push (X%Y);                        // Operação para o resto da divisão de um valor pelo outro
         }
         else if (strcmp(token,")")==0) {
             long Y = pop();
             push (Y+1);                        // Ao último valor adicionado á stack vai incrementar uma unidade 
         }
         else if (strcmp(token,"(")==0) {
             long Y = pop();
             push (Y-1);                        // Ao último valor adicionado á stack vai decrementar uma unidade
         }
         else if (strcmp(token,"#")==0) {
             long Y = pop();
             long X = pop();
             long res = pow(X,Y);
             push (res);                        // Operação para a potência de um valor pelo outro (X elevado a Y)
         }
         else if (strcmp(token,"~")==0) {       // --> apartir daqui trabalhamos bitwise para valores inteiros 
             long X = pop();
             push (~X);                         // Aqui damos o valor binário e nesta operação é invertida o seu valor, nomeadamente 0's passa
         }                                      // para 1's e vice-versa 
         else if (strcmp(token,"&")==0) {
             long Y = pop();
             long X = pop();
             push (X&Y);                        // Compara os elementos do inteiro em binário e verifica se tem numeros iguais nas mesmas posições  
         }    
         else if (strcmp(token,"|")==0) {
             long Y = pop();
             long X = pop();
             push (X|Y);                        // Disjunção dos elementos bits, neste caso vê quais são iguais e os diferentes mas retorna
         }                                      // os valores todos ("ou" em lógica)
         else if (strcmp(token,"^")==0) {
             long Y = pop();
             long X = pop();
             push (X^Y);                        // Verifica se os bits são iguais e retorna 0 se forem diferentes e 1 se forem iguais
         }
     }
    print_stack (stack,conta);                  // Após feita as operações chamamos a função "print_stack" e imprimimos o resultado
}                                               // debaixo da stack para cima da stack 
