/**
 * @file pushpop.c  
 * 
 * Este é o ficheiro que contêm as funções relativas à stack 
 * 
 */
#include <stdio.h>
#include "pushpop.h" 

/*
 * 
 * Array stack: criamos a stack.
 * 
 */
int stack[10240];
/*
 * 
 * Variável que nos diz o tamanho da stack.
 * 
 */
int conta = 0; 

/** 
 * Esta é a função que faz push, ou seja, adiciona um valor ao topo da stack.
 */
void push(int x) { 
    if (conta == 10240) {                  //caso a stack esteja cheia dá print ao enunciado abaixo escrito, e não faz nada 
        printf("Nao ha espaço na stack\n");
        return;
    }
    stack[conta] = x;
    conta++; 
}
/** 
 * Esta é a função que faz pop, ou seja, retira um valor do topo da stack.
 * 
 * @returns O valor "resto", o valor retirado da stack.
 */
int pop() { 
    if (conta == 0) { 
        printf("Nada pra tirar da stack\n");
        return 0;                           //isto é um erro, secalhar parar o programa em vez?
    }
    int resto = stack[conta-1];             //guarda na variável resto o valor que está no topo da stack 
    conta--;                                //decresce à variável que guarda o tamanho da stack
    return resto;
}

/** 
 * Esta é a função que imprime a stack, imprime o resultado debaixo para o topo da stack 
 */
void print_stack (int v[],int N) {
    int i;
    for (i=0;i<N;i++) {
        printf("%d",v[i]);
    }
    printf("\n");
}
