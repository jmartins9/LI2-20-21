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
#include "stackoperations.h"
#include "matoperations.h"
#include "logicoperations.h"
#include "variables.h"
#include "convoperations.h"
#include "arrays.h"
#include "leituraInputs.h"
#include "blocos.h"


/**
 *
 * Esta é a função que faz o parse de dados tipo char e string.
 * 
 */
void parsedatas (char *token,STACK *s) {
     DATA data;
     if (strlen(token)==1) {
     make_datas(data,CHAR,*token);push (s,data);}
     if (strlen(token)>1) { 
     make_datas(data, STRING,strdup(token));push (s,data);}
}

/**
 *
 * Esta é a função que gere os dados dados no token e executa as suas instruções.
 * De maneira a não ter demasiadas condições, optamos por criar arrays auxiliares com certos operador do mesmo grupo,
 * e de seguida é verificado se o token pertence a estes arrays, chamando a função correspondente.
 * 
 */
void alloperations (char *token,STACK *s,VARIABLES *x) {
     char *blocoOperadores = "~%*,$w";
     char *charsMatOp = "+-*/)(%#&|^~";
     char *charsLogicOp = "=<>!?e&e|e<e>";
     char *charsConvOpStackOpLeitura = "fcis\\_;$@ltp";
     char *charsVar = ":A:B:C:D:E:F:G:H:I:J:K:L:M:N:O:P:Q:R:S:T:U:V:W:X:Y:Z";
     char *charsArray = ",S/N/";
     if (strstr(blocoOperadores,token)!=NULL && top(s).type == BLOCO) blocoOperations(token,s,x);
     else if (strstr(charsMatOp,token)!=NULL) {matoperations(token,s);}
     else if (strstr(charsLogicOp,token)!=NULL) {logicoperations(token,s);}
     else if (strstr(charsConvOpStackOpLeitura,token)!=NULL) {convoperations(token,s);}
     else if (strstr(charsVar,token)!=NULL) {varoperations(token,s,x);}
     else if (strstr(charsArray,token)!=NULL) {arrayops(token,s);}
     else parsedatas(token,s);
}

/**
 *
 * Esta é a função que faz o parse de dados tipo long e double.
 * 
 */
int parseNumbers (char *token,STACK *s) {
    int r=0;
    char *sobra;
    char *sobra1;
    DATA data;
    float Float;
    long Long;
    Long=strtol (token,&sobra,10);
    Float=strtod (token,&sobra1);
    if (strlen(sobra1)==0) {
        if (strlen(sobra)!=0) {make_datas(data,DOUBLE,Float);push (s,data);r=1;} 
        else {make_datas(data,LONG,Long);push (s,data);r=1;}
    }
    return r;
}



/**
 * 
 * Esta é a função responsável pelo parse da linha lida e executar as intruções dadas com a ajuda de uma stack.  
 * 
 */
STACK *parse(char *line,STACK *s,VARIABLES *x) {
    if (s == NULL) s = create_stack();
    char *rest[strlen(line)+1];
    char *token = (char*) malloc(sizeof(char)*(strlen(line)+1));
    *rest = (char*) malloc(sizeof(char)*(strlen(line)+1));

    for (token = get_token(line,rest); token != NULL; token = get_token(line,rest)) {      
        if (*token == '[') criarArray(line+2,s,x,rest);
        else if (*token == '"') criarString(line+1,s,rest);
        else if (*token == '{') criarBloco(line,s,rest);
        else if (parseNumbers(token,s)==1);
        else alloperations(token,s,x);
        
        line=*rest;
    }
    free(token);
    return s;
}


