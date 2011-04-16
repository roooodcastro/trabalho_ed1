#include <math.h>
#include "elemento.h"

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
