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


