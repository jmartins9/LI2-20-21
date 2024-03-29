/**
 * @file main.c
 *
 * Ficheiro que contêm a função principal do programa,que lê uma linha
 * e no fim de executar as operações necesárias imprime o conteúdo da stack.
 *
 */
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "pushpop.h"
#include "variables.h"

/**
 * \brief Esta é a função principal do programa.
 *
 * A função lê uma linha que é o nosso input e, em seguida, chama a função parse.  
 * 
 * @returns 0 valor 0.
 */
int main () {
    STACK *s=NULL;
    VARIABLES *vars = create_varlist();
    char line [15000];
    assert( fgets (line,15000,stdin) != NULL);
    assert( line  [strlen (line)-1] == '\n');
    s = parse(line,s,vars);
    print_stack (s);
    printf("\n");
    return 0;
}
