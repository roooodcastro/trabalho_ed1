#include <string.h>
#include "simplectest/tests.h"
#include "elemento.c"
#include "lista.c"
#include "posfix.c"

int main(int argc, char *argv[]){
    if (argc < 3)
        return 1;

    int valida = isValid(argv[2]);
    if (valida != 0){
        printf("A expressão não é válida!\n");
        return valida;
    }

    if (strcmp(argv[1], "c") == 0 || strcmp(argv[1], "a") == 0){
        char temp[255];
        toStringPosfixExpression(temp, argv[2]);
        printf("Posfixa: %s\n", temp);
    }

    if (strcmp(argv[1], "e") == 0 || strcmp(argv[1], "a") == 0){
        Lista l;
    	convert( &l, argv[2]);
        printf("Resultado: %f\n", eval_posfix(l));
    }
        
    return 0;

}
