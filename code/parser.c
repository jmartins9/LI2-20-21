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

/**
 *
 * Esta é a função que guarda a linha de comandos dada numa string.
 * 
 */
void preenche (char *line,char v[]) {
     int i;
     for(i=0;*line;i++) {
         v[i]=*line;
         line++;
     } 
}

/**
 *
 * Esta é a função que converte uma linha de dados em tipo de dados STRING e coloca na Stack.
 * 
 */
void leituradatas (char *line,STACK *s) {
    char *delimitadores = " \t\n" ;
    for (char *token = strtok(line, delimitadores); token != NULL ; token = strtok (NULL, delimitadores)) {
              DATA data;
              make_datas(data, STRING,strdup(token));
              push (s,data);
    }
}

/**
 *
 * Esta é a função que faz o parse de dados tipo char e string.
 * 
 */
void parsedatas (char *token,STACK *s,VARIABLES *x) {
     DATA data = darValor(*token, x);
     if (strlen(token)==1) {
     push (s,data);}
     if (strlen(token)>1) { 
     make_datas(data, STRING,strdup(token));push (s,data);}
}

/**
 *
 * Esta é a função que gere os dados dados no token e executa as suas instruções.
 * 
 */
void alloperations (char *token,STACK *s,VARIABLES *x) {
     int r=0;
     char *charsStackop = "_;@$\\";
     char *charsMatOp = "+-*/)(%#&|^~";
     char *charsLogicOp = "=<>!?e&e|e<e>";
     char *charsConvOp = "fci";
     char *charsVar = ":A:B:C:D:E:F:G:H:I:J:K:L:M:N:O:P:Q:R:S:T:U:V:W:X:Y:Z";
     if (*token >= 'A' && *token <= 'Z') {parsedatas(token,s,x);r=1;}
     if (strstr(charsStackop,token)!=NULL) {stackoperations(token,s);r=1;}
     if (strstr(charsMatOp,token)!=NULL) {matoperations(token,s);r=1;}
     if (strstr(charsLogicOp,token)!=NULL) {logicoperations(token,s);r=1;}
     if (strstr(charsConvOp,token)!=NULL) {convoperations(token,s);r=1;}
     if (strstr(charsVar,token)!=NULL) {varoperations(token,s,x);r=1;}
     if (r==0) parsedatas(token,s,x);
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
 * Esta é a função responsável pela execução do comando l.  
 * 
 */
void loperation (char *token,char *guardaline,STACK *s,VARIABLES *x) {
    char line1[10240];
    assert( fgets (line1,10240,stdin) != NULL);
    assert( line1  [strlen (line1)-1] == '\n');
    leituradatas(line1,s);
    parse(strstr(guardaline,token)+strlen(token),s,x);
}

/**
 * 
 * Esta é a função responsável pelo parse da linha lida e executar as intruções dadas com a ajuda de uma stack.  
 * 
 */
void parse(char *line,STACK *s,VARIABLES *x) {
     char guardaline[12040]; preenche(line,guardaline);
     char *delimitadores = " \t\n" ;
     for (char *token = strtok(line, delimitadores); token != NULL ; token = strtok (NULL, delimitadores)) {
         if (parseNumbers(token,s)==1);
         else if (strcmp(token,"l")==0) { 
              loperation (token,guardaline,s,x); 
         }
         else {
             alloperations(token,s,x);
         }
     }
} 


