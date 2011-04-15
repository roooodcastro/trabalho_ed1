#include <math.h>
typedef float (Operacao)(float, float);

float soma(float b, float a) {
    return a + b;
}
 
float subtracao(float b, float a) {
    return a - b;
} 

float multiplicacao(float b, float a) {
    return a * b;
} 

float divisao(float b, float a) {
    return a / b;
} 

float exponencial(float b, float a) {
    return powf(a, b);
} 

typedef struct {
    float numero;
    Operacao *operador;
    char tipo;
} Elemento;

void numero(Elemento *e, float valor)
{
    e->numero = valor;
    e->tipo = 'N';
    e->operador = '\0';
}

int operador(Elemento *e, char valor)
{
    e->numero = 0;
    e->tipo = 'O';
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
    return 1;
    

}

typedef struct{
    Elemento elementos[1000];
    int topo;
} Lista;

void construir_lista(Lista *l)
{
    l->topo = -1;
}

int push(Lista *l, Elemento e)
{
    if (l->topo < 1000) {
        l->elementos[++(l->topo)] = e;
        return 1;
    }
    return 0;
}

int pop(Lista *l, Elemento *e)
{
    if (l->topo > -1) {
        *e = l->elementos[(l->topo)--];
        return 1;
    } 
    return 0;
   
}

#define IS_NUMERO(c) (c >= '0' && c <= '9')
#define IS_LETRA(c) ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == ',' || c == '.')
#define IS_OPERADOR(c) (c == '+' || c == '-' || c == '*' || c == '/' || c == '$')
