#include <string.h>
#include "posfix.h"

float stof(char *text)
{
    float valor;
    sscanf(text, "%f", &valor); 
    return valor;
}


int isValidInfix(Lista *l){
    Lista t1, t2;
    Lista *T[2] = {&t1, &t2};
    int i; int ordem; int parenteses; 
    if (l->topo == 0){
        if (l->elementos[l->topo].tipo != 'N')
            return 1;
        return 0;
    }
    construir_lista(&t1);
    construir_lista(&t2);
    
    ordem = 0;
    parenteses = 0;
    if (l->topo > 2){
        if (l->elementos[0].tipo != '(' || l->elementos[l->topo].tipo != ')')
            return 5;        
        for (i = 1; i <= l->topo-1; i++){
            if (IS_OPERADOR(l->elementos[i].tipo) && parenteses == 0){
                if (parenteses > 0)
                    return 3;
                ordem ++;
            }else
                append(T[ordem], l->elementos[i]);
            if (l->elementos[i].tipo == '(')
                parenteses++;
            if (l->elementos[i].tipo == ')')
                parenteses--;
            if (ordem > 1)
                return 6; 
            if (parenteses < 0)
                return 3;
    
        }
        if (parenteses > 0)
            return 3;
        if (ordem == 0)
            return 4;       

        return (isValidInfix(&t1) | isValidInfix(&t2)); // Como o valor valido é 0, só deixa de ser válido se um ou o outro for != 0
        
    }else
        return 2;
}

int isValidPosfix(Lista *l){
    int i;
    int nCount = 0; int opCount = 0;
    for (i = 0; i <= l->topo; i++){
        if (l->elementos[i].tipo == 'N')
            nCount++;
        else {
            opCount++;
            if (opCount != nCount - 1)
                return 8;
        }
        if (l->elementos[i].tipo == '(' || l->elementos[i].tipo == ')')
            return 7;
    }
    return 0;
}

int isValid(char* exp)
{
    Lista l;
    int func = 0;

    infix_to_infix(&l, exp, &func);
    if (func != 0)
        return func;
    
    if (!IS_OPERADOR(l.elementos[l.topo].tipo))    
        func = isValidInfix(&l); 
    else
        func = isValidPosfix(&l);

    return func;
}

void toStringPosfixExpression(char* str, char* exp)
{
	int i;
	Lista l;
	char buffer[255];

	sprintf(str, "");
	
	convert(&l, exp);

	for(i = 0; i <= l.topo; i++)
	{
		if (l.elementos[i].tipo == 'N')
			sprintf(buffer, "%s%.1f ", str, l.elementos[i].numero);
		else
			sprintf(buffer, "%s%c", str, l.elementos[i].tipo);
		strcpy(str, buffer);
	}
}

Lista* infix_to_posfix(Lista *l, char *infixa)
{
	int i = 0;
    char aux[255];
	Pilha pilha; 

    sprintf(aux, "");

    construir_lista(l);
    construir_pilha(&pilha);
    
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
			else if (infixa[i] == ')' && (pop(&pilha, &e) == 1)){
				append(l, e);
			}
	    }

	    i++;
	} while (infixa[i-1] != '\0');
    return l;
}

Lista* infix_to_infix(Lista *l, char *infixa, int *func)
{
	int i = 0;
    char aux[255];

    sprintf(aux, "");

    construir_lista(l);
    
	do {
	    if (IS_NUMERO(infixa[i]))                
            sprintf(aux, "%s%c", aux, infixa[i]);
	    else {
            Elemento e;	  
            if (strlen(aux)){
				if (push(l, *numero(&e, stof(aux))) == 0){
					*func = 9;
				}
                sprintf(aux, "");
            }
			if (operador(&e, infixa[i])){ 
				if (push(l, e) == 0)
					*func = 9;
			}
			else if (infixa[i] == '(' || infixa[i] == ')'){
				Elemento e;
				e.tipo = infixa[i];
				if (push(l, e) == 0)
					*func = 9;
			}
	    }

	    i++;
	} while (infixa[i-1] != '\0');
	
    return l;
}

Lista* posfix_to_posfix(Lista *l, char *posfixa)
{
	int i = 0;
    char aux[255];

    sprintf(aux, "");

    construir_lista(l);

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

Lista* convert(Lista *l, char* exp)
{
	if ( IS_OPERADOR(exp[strlen(exp)-1]) )
		return posfix_to_posfix(l, exp);
	else
		return infix_to_posfix(l, exp);
}


float eval_posfix(Lista l)
{
	int i = 0;

    Pilha pilha; 
    construir_pilha(&pilha);

    for (i = 0; i <= l.topo; i++){
        Elemento e;
		if (l.elementos[i].tipo == 'N'){
			push(&pilha, l.elementos[i]);
		}else{
            pushv(&pilha, l.elementos[i].operador(popv(&pilha), popv(&pilha)));
		}
    } 
    return popv(&pilha);
}

