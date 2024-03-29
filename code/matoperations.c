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
#include "arrays.h"
#include "variables.h"
#include "matoperations.h"
#include "blocos.h"
#include "stackoperations.h"

/**
 *
 * Esta é a função que executa o comando +, ou seja, soma os dois elementos no topo da stack.
 * 
 */
void somar (STACK *s) { 
    DATA p1 = pop(s);
    DATA p2 = pop(s);
    DATA Z;
    if (p1.type==LONG && p2.type==LONG) {long soma = p2.elems.LONG+p1.elems.LONG;make_datas(Z,LONG,soma);}
    if (p1.type==DOUBLE && p2.type==LONG) {double soma = p2.elems.LONG+p1.elems.DOUBLE;make_datas(Z,DOUBLE,soma);}
    if (p1.type==DOUBLE && p2.type==DOUBLE) {double soma = p2.elems.DOUBLE+p1.elems.DOUBLE;make_datas(Z,DOUBLE,soma);}
    if (p1.type==LONG && p2.type==DOUBLE) {double soma = p2.elems.DOUBLE+p1.elems.LONG;make_datas(Z,DOUBLE,soma);}            
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
    if (p1.type==LONG && p2.type==LONG) {long subtracao = p2.elems.LONG-p1.elems.LONG;make_datas(Z,LONG,subtracao);}
    if (p1.type==DOUBLE &&p2.type==LONG) {double subtracao = p2.elems.LONG-p1.elems.DOUBLE;make_datas(Z,DOUBLE,subtracao);}
    if (p1.type==DOUBLE &&p2.type==DOUBLE) {double subtracao = p2.elems.DOUBLE-p1.elems.DOUBLE;make_datas(Z,DOUBLE,subtracao);}
    if (p1.type==LONG && p2.type==DOUBLE) {double subtracao = p2.elems.DOUBLE-p1.elems.LONG;make_datas(Z,DOUBLE,subtracao);} 
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
    if (p1.type==LONG && p2.type==LONG) {long mult = p2.elems.LONG*p1.elems.LONG;make_datas(Z,LONG,mult);}
    if (p1.type==DOUBLE && p2.type==LONG) {double mult = p2.elems.LONG*p1.elems.DOUBLE;make_datas(Z,DOUBLE,mult);}
    if (p1.type==DOUBLE && p2.type==DOUBLE) {double mult = p2.elems.DOUBLE*p1.elems.DOUBLE;make_datas(Z,DOUBLE,mult);}
    if (p1.type==LONG && p2.type==DOUBLE) {double mult = p2.elems.DOUBLE*p1.elems.LONG;make_datas(Z,DOUBLE,mult);} 
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
    if (p1.type==LONG && p2.type==LONG) {long div = p2.elems.LONG/p1.elems.LONG;make_datas(Z,LONG,div);}
    if (p1.type==DOUBLE && p2.type==LONG) {double div = p2.elems.LONG/p1.elems.DOUBLE;make_datas(Z,DOUBLE,div);}
    if (p1.type==DOUBLE && p2.type==DOUBLE) {double div = p2.elems.DOUBLE/p1.elems.DOUBLE;make_datas(Z,DOUBLE,div);}
    if (p1.type==LONG && p2.type==DOUBLE) {double div = p2.elems.DOUBLE/p1.elems.LONG;make_datas(Z,DOUBLE,div);} 
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
    if (p1.type==LONG) {long inc = p1.elems.LONG+1;make_datas(Z,LONG,inc);}
    if (p1.type==DOUBLE) {double inc = p1.elems.DOUBLE+1;make_datas(Z,DOUBLE,inc);}
    if (p1.type==CHAR) {char inc = p1.elems.CHAR+1;make_datas(Z,CHAR,inc);}
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
    if (p1.type==LONG) {long inc = p1.elems.LONG-1;make_datas(Z,LONG,inc);}
    if (p1.type==DOUBLE) {double inc = p1.elems.DOUBLE-1;make_datas(Z,DOUBLE,inc);}
    if (p1.type==CHAR) {char inc = p1.elems.CHAR-1;make_datas(Z,CHAR,inc);}
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
    if (p1.type==LONG && p2.type==LONG) {long exp = pow(p2.elems.LONG,p1.elems.LONG);make_datas(Z,LONG,exp);}
    if (p1.type==DOUBLE && p2.type==LONG) {double exp = pow(p2.elems.LONG,p1.elems.DOUBLE);make_datas(Z,DOUBLE,exp);}
    if (p1.type==DOUBLE && p2.type==DOUBLE) {double exp = pow(p2.elems.DOUBLE,p1.elems.DOUBLE);make_datas(Z,DOUBLE,exp);}
    if (p1.type==LONG && p2.type==DOUBLE) {double exp = pow(p2.elems.DOUBLE,p1.elems.LONG);make_datas(Z,DOUBLE,exp);} 
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
        for(i=0;i<tamanho;i++) {
            push(s,x->stack[i]);
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
    } else if (array1.type==STRING && array2.type==CHAR) {
        char *aux = (char*) malloc((strlen(array1.elems.STRING)) * sizeof(char));
        aux[0] = array2.elems.CHAR;
        strcpy(aux+1,array1.elems.STRING);
        DATA Z; make_datas(Z, STRING, aux);
        push (s,Z);
    }
    else if (array1.type==CHAR && array2.type==STRING) {
        strncat(array2.elems.STRING, &array1.elems.CHAR,1);
        push(s,array2);
    }
}

/**
 *
 * Concatena dois arrays.
 * Percorre os elementos de um array e dá push a todos os elementos no outro array. 
 * 
 */
void concatenateArrays (STACK *s,DATA array1,DATA array2) {
    int i;
    if (array1.type==STACKK && array2.type==STACKK) {
        for (i=0; i<array1.elems.STACKK->n_elems; i++) {
            push(array2.elems.STACKK,array1.elems.STACKK->stack[i]);
        }
        make_datas(array2, STACKK, array2.elems.STACKK);
        push (s,array2);
    }
    else if (array1.type==STACKK) {
        STACK *x=create_stack();
        push(x,array2);
        for (i=0; i<array1.elems.STACKK->n_elems; i++) {
            push(x,array1.elems.STACKK->stack[i]);
        }
        make_datas(array1, STACKK, x);
        push(s,array1);
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

/**
 * 
 * Função que concatena várias vezes um array, e coloca o array concatenado na stack.
 * 
 */
void concatenaNvezes_array (STACK *s,DATA p1,DATA p2) {
     if (p2.type==STACKK) {
        int i;
        STACK *x=p2.elems.STACKK;
        STACK *new=create_stack();
        int length = x->n_elems;

        for (i=0;i<p1.elems.LONG;i++) {
            x->n_elems=1;
            while (x->n_elems!=length+1) {
                push(new,pop(x));
                x->n_elems+=2;
            }
            x->n_elems=1;            
        }

        p2.elems.STACKK=new;
        push(s,p2);
     }
}

/**
 *
 * Função que concatena strings n vezes
 *
 */
void concatenaNvezes_string (STACK *s,DATA p1,DATA p2) {
     if (p2.type==STRING) {
         int i;
         char *string= (char *) calloc(p1.elems.LONG*strlen(p2.elems.STRING),sizeof(char));
         for (i=0;i<p1.elems.LONG;i++) {
             strcat(string,p2.elems.STRING);
         }
         p2.elems.STRING=string;
         push(s,p2);
     }
}


/**
 * 
 * Função que divide string por substring e devolve o resultado desta operação num array que é colocado na stack.
 * 
 */
void dividirString (STACK *s) {
    DATA delims = pop(s);
    DATA toDivide = pop(s);
    STACK *x = create_stack();
    DATA Z; make_datas(Z,STACKK,x);
    DATA str;
    if (delims.type == STRING && toDivide.type == STRING) {
        char *strdelims = delims.elems.STRING;
        char * strToDivide = toDivide.elems.STRING;
        char *token;
        token = strtok(strToDivide,strdelims);
        while (token!=NULL) {
            make_datas(str, STRING, token);
            push(Z.elems.STACKK,str);
            token = strtok(NULL,strdelims);
        }
        push(s,Z);
    }
}

/**
 *
 * Função que procura uma string dentro de outra string e devolve o índice onde a mesma aparece
 *
 */
void procuraStringString (DATA arraytoBeSearched,DATA arraytoSearch,STACK *s) {
        char *str1 = arraytoSearch.elems.STRING;
        char *str2 = arraytoBeSearched.elems.STRING;
        char *line = strstr(str1,str2);
        int i = 0;
    
        while (str1 != line && *str1) {
            str1++; i++;
        }
        if (line == NULL) i=-1;
        DATA Z; make_datas(Z,LONG, i);
        push(s,Z);
}

/**
 *
 * Função que procura um caratere dentro de outra string e devolve o índice onde a mesma aparece
 *
 */
void procuraStringChar (DATA arraytoBeSearched,DATA arraytoSearch,STACK *s) {
        char *str1 = (char*) malloc(sizeof(char) * 2);
        str1[0] = arraytoBeSearched.elems.CHAR; str1[1] = '\0';
        char *str2 = arraytoSearch.elems.STRING;
        char *line = strstr(str2,str1);
        int i = 0;
    
        while (str2 != line && *str2) {
            str2++; i++;
        }
        if (line == NULL) i=-1;
        DATA Z; make_datas(Z,LONG, i);
        push(s,Z);
}

/**
 *
 * Função que procura uma string dentro de outra string e devolve o índice onde a mesma aparece
 *
 */
void procurarSubstring (STACK *s) {
    DATA arraytoBeSearched = pop(s);
    DATA arraytoSearch = pop(s);
    if (arraytoBeSearched.type == STRING && arraytoSearch.type == STRING) {
        procuraStringString(arraytoBeSearched,arraytoSearch,s);
    } else if (arraytoBeSearched.type == CHAR && arraytoSearch.type == STRING) {
        procuraStringChar(arraytoBeSearched,arraytoSearch,s);
    }
}

/**
 * 
 * Decide qual instrução deve ser executado dependendo dos tipos dos argumentos que as operações aritméticas recebem.
 * 
 */
void handle_arithmetic (char *token,STACK *s) {
    DATA p1=pop(s);
    DATA p2=top(s);
    push(s,p1);
    if ((p1.type==STRING || p1.type==STACKK) || (p2.type==STACKK || p2.type==STRING)) {
        switch (*token) {
            case ('~'): putArrayStack(s);break;
            case ('+'): p1 = pop(s); p2 = pop(s); concatenateArrays(s,p1,p2); concatenateStrings(s,p1,p2); break;
            case ('*'): p1 = pop(s); p2 = pop(s); concatenaNvezes_array(s,p1,p2); concatenaNvezes_string(s,p1,p2); break;
            case ('('): p1 = pop(s);remove1string(s,p1);remove1array(s,p1);break;
            case (')'): p1 = pop(s);removeUltstring(s,p1);removeUltarray(s,p1);break;
            case ('#'): procurarSubstring(s);break;
            case ('/'): dividirString(s);break;
        }
    } 
    else {
        switch (*token) {
            case ('%'): divResto(s);break;
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
    case ('&'): andBin(s);break;
    case ('|'): orBin(s);break;
    case ('^'): xorBin(s);break;
    default : handle_arithmetic(token,s);break;
    }      
}