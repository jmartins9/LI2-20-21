#include <stdio.h>
#include "pushpop.h" //tal como a parser.c e parser.h, é preciso haver um ficheiro .h que declare as funçoes e variaveis que vais usar

//

int stack[10240]; //tamanho da stack 
int conta = 0; //definição da variável que guarda o tamanho da stack

void push(int x) { 
    if (conta == 10240) { //caso a stack esteja cheia dá print ao enunciado abaixo escrito, e não faz nada 
        printf("Nao ha espaço na stack\n");
        return;
    }
    stack[conta] = x; // adiciona à stack o valor "x"
    conta++; //Incrementação à função
}

int pop() { 
    if (conta == 0) { 
        printf("Nada pra tirar da stack\n");
        return 0; //isto é um erro, secalhar parar o programa em vez?
    }
    int resto = stack[conta-1]; //guarda na variável resto o valor que está no topo da stack 
    conta--; //decresce à variável que guarda o tamanho da stack
    return resto;
}

