#include <string.h>
#include "posfix.h"

float stof(char *str)
{
    float rfloat;
    sscanf(str, "%f", &rfloat); 
    return rfloat;
}

Lista* infix_to_posfix(Lista *l, char *infixa)
{
    char aux[255];
    sprintf(aux, "");

    Pilha pilha; 

    construir_lista(l);
    construir_pilha(&pilha);
    
	int i = 0;
	do {
	    if (IS_NUMERO(infixa[i]))                
            sprintf(aux, "%s%c", aux, infixa[i]);
	    else {
            Elemento e;	  
            if (strlen(aux)){
                push(l, *numero(&e, stof(aux))); 
                sprintf(aux, "");
            }
            if (operador(&e, infixa[i])) 
                push(&pilha, e);
    	    else if (infixa[i] == ')' && pop(&pilha, &e))
                append(l, e);
	    }

	    i++;
	} while (infixa[i-1] != '\0');
    return l;
}

float eval_posfix(Lista l)
{
    Pilha pilha; 
    construir_lista(&pilha);
    
    int i = 0;
    for (i = 0; i <= l.topo; i++){
        Elemento e;
        if (l.elementos[i].tipo == 'N')
            push(&pilha, l.elementos[i]);
        else
            pushv(&pilha, l.elementos[i].operador(popv(&pilha), popv(&pilha)));
    } 
    return popv(&pilha);
}

Lista* posfix_to_posfix(Lista *l, char *posfixa)
{
    char aux[255];
    sprintf(aux, "");

    construir_lista(l);
	int i = 0;
	do {
	    if (IS_NUMERO(posfixa[i]))                
            sprintf(aux, "%s%c", aux, posfixa[i]);
	    else {
            Elemento e;	  
            if (strlen(aux)){
                push(l, *numero(&e, stof(aux))); 
                sprintf(aux, "");
            }
            if (operador(&e, posfixa[i])) 
                append(l, e);
	    }
	    i++;
	} while (posfixa[i-1] != '\0');
    return l;
}
