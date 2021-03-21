#include <stdio.h>
#include "pushpop.h" //tal como a parser.c e parser.h, é preciso haver um ficheiro .h que declare as funçoes e variaveis que vais usar

int stack[10240];
int conta = 0;

void push(int x) {
    if (conta == 10240) { //isto é um erro, secalhar parar o programa?
        printf("Nao ha espaço na stack\n");
        return;
    }
    stack[conta] = x;
    conta++;
}

int pop() {
    if (conta == 0) {
        printf("Nada pra tirar da stack\n");
        return 0; //isto é um erro, secalhar parar o programa em vez?
    }
    int resto = stack[conta-1];
    conta--;
    return resto;
}

