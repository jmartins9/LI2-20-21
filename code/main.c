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

/**
 * \brief Esta é a função principal do programa.
 *
 * A função lê uma linha que é o nosso input e, em seguida, chama a função parse.  
 * 
 * @returns 0 valor 0.
 */

int main () {
    char line [10240];
    assert( fgets (line,10240,stdin) != NULL);
    assert( line  [strlen (line)-1] == '\n');
    parse(line);
    return 0;
}