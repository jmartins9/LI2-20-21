/**
 * @file matoperations.c 
 *
 * Este é o ficheiro que contém todas as funções relacionadas com as operações matemáticas. 
 */
#include <stdio.h>
#include <string.h>
#include "pushpop.h"
#include <stdlib.h>
#include <math.h>
#include "convoperations.h"


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
 * Coloca todos os valores do array na stack. 
 * 
 */
void putArrayStack (STACK *s) {
    DATA p1=pop(s);
    if (p1.type==STACKK) {
        STACK *x=p1.elems.STACKK;
        int i;
        int tamanho=x->n_elems;
        for(i=0;i<=tamanho;i++) {
            x->n_elems=i;
            push(s,top(x));
        }
    }
    else {
        int i;
        for (i=0;p1.elems.STRING[i]!='\0';i++) {
             DATA p;
             make_datas(p,CHAR,p1.elems.STRING[i]);
             push(s,p);
        }
    }
}

/**
 *
 * Concatena duas Strings.
 * 
 */
void concatenateStrings (STACK *s,DATA array1,DATA array2) {
    if (array1.type==STRING && array2.type==STRING) {  
        strcat(array2.elems.STRING,array1.elems.STRING);  // nao funcina quando faço : "ola" S "mundo" + + , mas "ola" "mundo" funciona
        push (s,array2);
    }
    else if (array1.type==STRING && array2.type!=STRING) {
        char string[strlen(array1.elems.STRING)+1];
        string[0]=array2.elems.CHAR;  
        memcpy(string+1,array1.elems.STRING,strlen(array1.elems.STRING));
        array1.elems.STRING=string;
        push (s,array1);
    }
    else if (array1.type!=STRING && array2.type==STRING) {
        *(array2.elems.STRING+strlen(array2.elems.STRING))=array1.elems.CHAR;
        push (s,array2);
    }
}

/**
 *
 * Concatena dois arrays.
 * Percorre os elementos de um array e dá push a todos os elementos no outro array. 
 * 
 */
void concatenateArrays (STACK *s,DATA array1,DATA array2) {
    if (array1.type==STACKK && array2.type==STACKK) {
        STACK *stack1 = array1.elems.STACKK;
        STACK *stack2 = array2.elems.STACKK;
        int i;
        for (i=0; i<stack1->n_elems; i++) {
            push(stack2,stack1->stack[i]);
        }
        make_datas(array2, STACKK, stack2);
        push (s,array2);

    }
    else if (array1.type==STACKK) {
        STACK *x=create_stack();
        push(x,array2);
        push(x,array1);
        DATA p;
        make_datas(p,STACKK,x);
        push(s,p);
         
    }
    else if (array2.type==STACKK) {
        push(array2.elems.STACKK,array1);
        push(s,array2);
    }
}

/**
 * 
 * Função que remove o primeiro elemento de uma string e coloca a string e o elemento na stack.
 * 
 */
void remove1string (STACK *s,DATA array1) {
    if (array1.type==STRING) {
         char c = *array1.elems.STRING;
         array1.elems.STRING=array1.elems.STRING+1;
         DATA p;
         push(s,array1);
         make_datas(p,CHAR,c);
         push(s,p);
    
    }
}

/**
 * 
 * Função que remove o primeiro elemento de um array e coloca o array e o elemento na stack.
 * 
 */
void remove1array (STACK *s,DATA array1) {
     if (array1.type==STACKK) {
         STACK *x=array1.elems.STACKK;
         STACK *z=create_stack();
         int i;
         int tamanho=x->n_elems;
         for(i=2;i<=tamanho;i++) {
             x->n_elems=i;
             push(z,pop(x));
         }
         make_datas(array1,STACKK,z);
         push(s,array1);
         x->n_elems=1;
         push(s,pop(x));
     }
}

/**
 * 
 * Função que remove o ultimo elemento de uma string e coloca a string e o elemento na stack.
 * 
 */
void removeUltstring (STACK *s,DATA array1) {
     if (array1.type==STRING) {
         char c = array1.elems.STRING[strlen(array1.elems.STRING)-1];
         array1.elems.STRING[strlen(array1.elems.STRING)-1]='\0';
         DATA p;
         push(s,array1);
         make_datas(p,CHAR,c);
         push(s,p);
     }

}

/**
 * 
 * Função que remove o ultimo elemento de um array e coloca o array e o elemento na stack.
 * 
 */
void removeUltarray (STACK *s,DATA array1) {
    if (array1.type==STACKK) {
        STACK *x=array1.elems.STACKK;
        DATA p = pop(x);
        push(s,array1);
        push(s,p);
    }
}

void concatenaNvezes_array (STACK *s,DATA p1,DATA p2);

void concatenaNvezes_string (STACK *s,DATA p1,DATA p2);


/**
 * 
 * Decide qual instrução deve ser executado dependendo dos tipos dos argumentos que as operações aritméticas recebem.
 * 
 */
void handle_arithmetic (char *token,STACK *s) {
    DATA p1=pop(s);
    DATA p2=top(s);
    if ((p1.type==STRING || p1.type==STACKK) || (p2.type==STACKK || p2.type==STRING)) {
        push(s,p1);
        DATA array1;
        DATA array2;
        switch (*token) {
            case ('~'): putArrayStack(s);break;
            case ('+'): array1 = pop(s);array2 = pop(s); concatenateArrays(s,array1,array2); concatenateStrings(s,array1,array2); break;
            case ('*'): array1 = pop(s);array2 = pop(s); concatenaNvezes_array(s,array1,array2); concatenaNvezes_string(s,array1,array2); break;
            case ('('): array1 = pop(s);remove1string(s,array1);remove1array(s,array1);break;
            case (')'): array1 = pop(s);removeUltstring(s,array1);removeUltarray(s,array1);break;
            case ('#'): break;
            case ('/'): break;
        }
    } 
    else {
        push(s,p1);
        switch (*token) {
            case ('~'): notBin(s);break;
            case ('+'): somar(s);break;
            case ('*'): multiplicar(s);break;
            case ('('): subtrairTop(s);break;
            case (')'): somarTop(s);break;
            case ('#'): expoente(s);break;
            case ('/'): divInteira(s);break;
        }
    }
} 

/**
 *
 * Esta é a função que decide qual das operações matemáticas deve ser executada dependendo da instrução dada.
 * 
 */
void matoperations (char *token,STACK *s) {
    switch (*token) {
    case ('-'): subtrair(s);break;
    case ('%'): divResto(s);break;
    case ('&'): andBin(s);break;
    case ('|'): orBin(s);break;
    case ('^'): xorBin(s);break;
    default : handle_arithmetic(token,s);break;
    }      
}