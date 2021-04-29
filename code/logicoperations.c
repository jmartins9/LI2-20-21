/**
 * @file logicoperations.c 
 *
 * Este é o ficheiro que contém todas as funções relacionadas com as operações lógitas. 
 */
#include <stdio.h>
#include <stdlib.h>
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
    if (what_type (p1)==LONG && what_type(p2)==LONG) {long equiv = p2.elems.LONG == p1.elems.LONG;make_datas(Z,LONG,equiv);}
    if (what_type (p1)==DOUBLE && what_type(p2)==LONG) {long equiv = p2.elems.LONG == p1.elems.DOUBLE;make_datas(Z,LONG,equiv);}
    if (what_type (p1)==DOUBLE && what_type(p2)==DOUBLE) {long equiv = p2.elems.DOUBLE == p1.elems.DOUBLE;make_datas(Z,LONG,equiv);}
    if (what_type (p1)==LONG && what_type(p2)==DOUBLE) {long equiv = p2.elems.DOUBLE == p1.elems.LONG;make_datas(Z,LONG,equiv);}
    if ( p1.type==STRING && p2.type==STRING ) {long equiv = !strcmp(p1.elems.STRING,p2.elems.STRING);make_datas(Z,LONG,equiv);}            
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
    if (what_type (p1)==LONG && what_type(p2)==LONG && p1.elems.LONG<p2.elems.LONG) {
        push(s,p1);
    }
    else if (what_type (p1)==DOUBLE && what_type(p2)==LONG && p1.elems.DOUBLE<p2.elems.LONG) {
        push(s,p1);
    }
    else if (what_type (p1)==LONG && what_type(p2)==DOUBLE && p1.elems.LONG<p2.elems.DOUBLE) {
        push(s,p1);
    }
    else if (what_type (p1)==DOUBLE && what_type(p2)==DOUBLE && p1.elems.DOUBLE<p2.elems.DOUBLE) {
        push(s,p1);
    }
    else if (p1.type==STRING && p2.type==STRING && strcmp(p2.elems.STRING,p1.elems.STRING)>0) {
        push(s,p1);
    }
    else push(s,p2); 
}


/**
 *
 * Esta é a função que executa o comando e>, ou seja, devolve o maior dos dois ultimos valores colocados na stack.
 * 
 */
void maxoftwo (STACK *s) {
    DATA p1 = pop(s);
    DATA p2 = pop(s);
    if (what_type (p1)==LONG && what_type(p2)==LONG && p1.elems.LONG>p2.elems.LONG) {
        push(s,p1);
    }
    else if (what_type (p1)==DOUBLE && what_type(p2)==LONG && p1.elems.DOUBLE>p2.elems.LONG) {
        push(s,p1);
    }
    else if (what_type (p1)==LONG && what_type(p2)==DOUBLE && p1.elems.LONG>p2.elems.DOUBLE) {
        push(s,p1);
    }
    else if (what_type (p1)==DOUBLE && what_type(p2)==DOUBLE && p1.elems.DOUBLE>p2.elems.DOUBLE) {
        push(s,p1);
    }
    else if (p1.type==STRING && p2.type==STRING && strcmp(p2.elems.STRING,p1.elems.STRING)<0) {
        push(s,p1);
    }
    else push(s,p2); 
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
    if (what_type(p1)==DOUBLE) {long val = !(p1.elems.DOUBLE); make_datas(data,LONG,val); push(s,data);}
    if (what_type(p1)==CHAR) {long val = !(p1.elems.CHAR); make_datas(data,LONG,val); push(s,data);}
}


/**
 *
 * Esta é a função que converte um valor data para um data do tipo double.
 * 
 */
DATA converteDouble (DATA a) {
    double valor;
    if (what_type(a)==LONG) {valor = a.elems.LONG;make_datas(a,DOUBLE,valor);} 
    if (what_type(a)==DOUBLE) {valor = a.elems.DOUBLE;make_datas(a,DOUBLE,valor);} 
    if (what_type(a)==CHAR) {valor = a.elems.CHAR;make_datas(a,DOUBLE,valor); }
    return a;
} 



/**
 *
 * Esta é a função que executa o comando <, ou seja, devolve 1 se a condição for verdadeira e 0 se for falsa.
 * 
 */
void smallerthan (STACK *s) {
    DATA p1 = pop(s);
    DATA p2 = pop(s);
    DATA data;
    long val;
    if (p1.type==STRING && p2.type==STRING) {
        if (strcmp(p2.elems.STRING,p1.elems.STRING)<0) {
            make_datas(data,LONG,1);
            push(s,data);
            }
        else {
            make_datas (data,LONG,0);
            push(s,data);
       }   
    }
    else {
    p1 = converteDouble(p1);
    p2 = converteDouble(p2);
    val = p2.elems.DOUBLE < p1.elems.DOUBLE;
    make_datas(data,LONG,val); 
    push(s,data);
    }
}

/**
 *
 * Esta é a função que executa o comando >, ou seja, devolve 1 se a condição for verdadeira e 0 se for falsa.
 * 
 */
void biggerthan (STACK *s) {
    DATA p1 = pop(s);
    DATA p2 = pop(s);
    DATA data;
    long val;
    if (p1.type==STRING && p2.type==STRING) {
       if (strcmp(p2.elems.STRING,p1.elems.STRING)>0) {
            make_datas(data,LONG,1);
            push(s,data);
            }
       else {
            make_datas (data,LONG,0);
            push(s,data);
       }     
    }
    else {
    p1 = converteDouble(p1);
    p2 = converteDouble(p2);
    val = p2.elems.DOUBLE > p1.elems.DOUBLE;
    make_datas(data,LONG,val); 
    push(s,data);
    }
}

/**
 *
 * Esta é a função que recorre a outras funçõoes para executar as operações lógicas iniciadas por o caratere 'e' dependendo da instrução dada.
 * 
 */
void eoperations (char *token,STACK *s) {
    switch (*token) {
    case ('<'): minoftwo(s); break;
    case ('>'): maxoftwo(s); break;
    case ('&'): andlogic(s); break;
    case ('|'): orlogic(s); break;   
    
    default: pop(s);pop(s);break;
    }
}

/**
 * 
 * Função que vai buscar um valor por índice.
 * 
 */
void arrayelemN(STACK *s) {
     DATA p1=pop(s);
     DATA p2=pop(s);
     STACK *x=p2.elems.STACKK;
     x->n_elems-=p1.elems.LONG;
     push(s,top(x));

}

/**
 * 
 * Função vai buscar X elems/carat do início.
 * 
 */
void removeStart (STACK *s) {
    DATA p1 = pop(s);
    DATA p2 = pop(s);
    if (p2.type==STACKK) {
        STACK *x=p2.elems.STACKK;
        STACK *z=create_stack();
        int i;
        for (i=0;i<=p1.elems.LONG;i++) {
            x->n_elems=i;
            push(z,top(x));
        }
        make_datas(p1,STACKK,z);
        push(s,p1);
    }
    else {
        char *z = (char *) malloc (sizeof(char)*p1.elems.LONG);
        z=p2.elems.STRING;
        z[p1.elems.LONG]='\0';
        make_datas(p1,STRING,z);
        push(s,p1);
    }
}


/**
 * 
 * Função vai buscar X elems/carat do fim.
 * 
 */
void removeLast (STACK *s) {
     DATA p1 = pop(s);
     DATA p2 = pop(s);
     if (p2.type==STACKK) {
        STACK *x=p2.elems.STACKK;
        STACK *z=create_stack();
        int i;
        int posicao=x->n_elems+1;
        for (i=p1.elems.LONG;i>0;i--) {
             x->n_elems=posicao-i;
             push(z,top(x));
        }
        make_datas(p1,STACKK,z);
        push(s,p1);
     }
     else {
        char *z = (char *) malloc (sizeof(char)*p1.elems.LONG);
        int posicao=strlen(p2.elems.STRING);
        z=p2.elems.STRING+(posicao-p1.elems.LONG);
        make_datas(p1,STRING,z);
        push(s,p1);
     }
}

/**
 * 
 * Decide qual instrução com o mesmo comando '=' deve ser executado.
 * 
 */
void handlelogic (char *token,STACK *s) {
     DATA p1=pop(s);
     DATA p2=top(s);
     if (p1.type==LONG && (p2.type==STACKK || p2.type==STRING )) {
         push(s,p1);
         switch (*token) {
         case ('='): arrayelemN(s); break;
         case ('<'): removeStart(s);break;
         case ('>'): removeLast(s);break;
         }
     }
     else {
         push(s,p1);
         switch (*token) {
         case ('='): equivalente(s); break;
         case ('<'): smallerthan(s);break;
         case ('>'): biggerthan(s);break;
         }
     }
}

/**
 *
 * Esta é a função que recorre a outras funçõoes para executar as operações lógicas dependendo da instrução dada.
 * 
 */
void logicoperations (char *token,STACK *s) {
    switch (*token) {
    case ('='): handlelogic(token,s);break;
    case ('?'): ifthenelse(s);break;
    case ('e'): eoperations(token+1,s);break;
    case ('!'): negate(s);break;
    case ('<'): handlelogic(token,s);break;
    case ('>'): handlelogic(token,s);break;
    }
}