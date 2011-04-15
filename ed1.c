#include <math.h>
#include <string.h>

#define IS_NUMERO(c) ((c >= '0' && c <= '9') || c == ',' || c == '.')
#define IS_OPERADOR(c) (c == '+' || c == '-' || c == '*' || c == '/' || c == '$')

typedef float (Operacao)(float, float);


//elemento.h
typedef struct {
    float numero;
    Operacao *operador;
    char tipo;
} Elemento;

//elemento.c
float soma(float a, float b) {
    return a + b;
}
 
float subtracao(float a, float b) {
    return a - b;
} 

float multiplicacao(float a, float b) {
    return a * b;
} 

float divisao(float a, float b) {
    return a / b;
} 

float exponencial(float a, float b) {
    return powf(a, b);
} 

Elemento *numero(Elemento *e, float valor)
{
    e->numero = valor;
    e->tipo = 'N';
    e->operador = '\0';
    return e;
}

Elemento *operador(Elemento *e, char valor)
{
    e->numero = 0;
    e->tipo = valor;
    switch (valor){
        case '+':
            e->operador = soma; 
            break;
        case '-':
            e->operador = subtracao; 
            break;
        case '*':
            e->operador = multiplicacao; 
            break;
        case '/':
            e->operador = divisao; 
            break;
        case '$':
            e->operador = exponencial; 
            break;
        default:
            e->tipo = '?';
            return 0;
    }
    return e;
    

}

//lista.h
typedef struct{
    Elemento elementos[1000];
    int topo ;
} Lista;

typedef Lista Pilha;

//lista.c
void construir_lista(Lista *l)
{
    l->topo = -1;
}

int push(Pilha *l, Elemento e)
{
    if (l->topo < 999) {
        l->elementos[++(l->topo)] = e;
        return 1;
    }
    return 0;
}


int pop(Pilha *l, Elemento *e)
{
    if (l->topo > -1) {
        *e = l->elementos[(l->topo)--];
        return 1;
    } 
    return 0;
   
}


int append(Lista *l, Elemento e)
{
    if (l->topo < 999) {
        l->elementos[++(l->topo)] = e;
        return 1;
    }
    return 0;
}

//void mostrar_lista(Lista *l){
//    int i = 0;
//    for (i = 0; i <= l->topo; i++){
//        if (l->elementos[i].tipo == 'N')
//            printf("%.2f ", l->elementos[i].numero);
//        else
//            printf("%c ", l->elementos[i].tipo);
//    }
//}

float popv(Pilha *temp){
    Elemento e;
    pop(temp, &e);
    return e.numero;
}

float pushv(Pilha *temp, float valor){
    Elemento e;
    
    push(temp, *numero(&e, valor));
    return e.numero;
}

//posfix.c
float stof(char *text)
{
    float valor;
    sscanf(text, "%f", &valor); 
    return valor;
}

Lista *infix_to_posfix(Lista *l, char *infixa)
{
    char aux[255];
    sprintf(aux, "");

    Pilha temp;    
    construir_lista(l);
    construir_lista(&temp);
    
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
                push(&temp, e);
    	    else if (infixa[i] == ')' && pop(&temp, &e))
                append(l, e);
	    }

	    i++;
	} while (infixa[i-1] != '\0');
    return l;
}

float eval_posfix(Lista l)
{
    Pilha temp; 
    construir_lista(&temp);
    
    int i = 0;
    for (i = 0; i <= l.topo; i++){
        Elemento e;
        if (l.elementos[i].tipo == 'N')
            push(&temp, l.elementos[i]);
        else
            pushv(&temp, l.elementos[i].operador(popv(&temp), popv(&temp)));
    } 
    return popv(&temp);
}

