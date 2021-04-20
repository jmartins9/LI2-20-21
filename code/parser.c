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
 * Esta é a função responsável pelo parse da linha lida e executar as intruções dadas com a ajuda de uma stack.  
 * 
 */
void parse(char *line,STACK *s) {
     char *sobra;
     char *sobra1;
     char guardaline[12040]; preenche(line,guardaline);
     char *charsStackop = "_;@$\\";
     char *charsMatOp = "+-*/)(%#&|^~";
     char *charsLogicOp = "=<>!?e&e|e<e>";
     char *charsVar = ":A:B:C:D:E:F:N:S:X:Y:Z";
     char *delimitadores = " \t\n" ;
     for (char *token = strtok(line, delimitadores); token != NULL ; token = strtok (NULL, delimitadores)) {
         DATA data;
         float Float;
         long Long;
         Long=strtol (token,&sobra,10);
         Float=strtod (token,&sobra1);
         if (strlen(sobra1)==0) {
          if (strlen(sobra)!=0) {make_datas(data,DOUBLE,Float);push (s,data);} 
          else {make_datas(data,LONG,Long);push (s,data);}
         }
         else if (strstr(charsStackop,token)!=NULL) {stackoperations(token,s);}
         else if (strstr(charsMatOp,token)!=NULL) {matoperations(token,s);}
         else if (strstr(charsLogicOp,token)!=NULL) {logicoperations(token,s);}
         else if (strstr(charsVar,token)!=NULL) {varoperations(token,s);}
         else if (strcmp(token,"l")==0) {
                  char line1[10240];
                  assert( fgets (line1,10240,stdin) != NULL);
                  assert( line1  [strlen (line1)-1] == '\n');
                  leituradatas(line1,s);
                  parse(strstr(guardaline,token)+strlen(token),s);
         }
         else if (strcmp(token,"i")==0) {
             DATA data;
             DATA p1 = pop(s);
             if (what_type (p1)==LONG) {long conv = p1.elems.LONG;make_datas(data,LONG,conv);}
             if (what_type (p1)==DOUBLE) {long conv = p1.elems.DOUBLE;make_datas(data,LONG,conv);}
             if (what_type (p1)==CHAR) {long conv = p1.elems.CHAR;make_datas(data,LONG,conv);}
             if (what_type (p1)==STRING) {long conv = strtol(p1.elems.STRING,NULL,10);make_datas(data,LONG,conv);}      
             push (s,data);
         }
         else if (strcmp(token,"f")==0) {
             DATA data;
             DATA p1 = pop(s);
             if (what_type (p1)==LONG) {float conv = p1.elems.LONG;make_datas(data,DOUBLE,conv);}
             if (what_type (p1)==DOUBLE) {float conv = p1.elems.DOUBLE;make_datas(data,DOUBLE,conv);}
             if (what_type (p1)==CHAR) {float conv = p1.elems.CHAR;make_datas(data,DOUBLE,conv);}
             if (what_type (p1)==STRING) {float conv = strtod(p1.elems.STRING,NULL);make_datas(data,DOUBLE,conv);}      
             push (s,data);
         }
         else if (strcmp(token,"c")==0) {
             DATA p1 = pop(s);
             DATA data;
             if (what_type (p1)==LONG) {char conv = p1.elems.LONG;make_datas(data,CHAR,conv);}
             if (what_type (p1)==DOUBLE) {char conv = p1.elems.DOUBLE;make_datas(data,CHAR,conv);}
             if (what_type (p1)==CHAR) {char conv = p1.elems.CHAR;make_datas(data,CHAR,conv);}
             push(s,data);
         }
         else if (strlen(token)==1) {
         make_datas(data, CHAR, *token);push (s,data);}
         else if (strlen(token)>1) { 
         make_datas(data, STRING,strdup(token));push (s,data);}
     }
} 
