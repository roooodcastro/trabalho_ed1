#ifndef _ELEMENTO_H
#define _ELEMENTO_H

typedef float (Operacao)(float, float);

typedef struct {
    float numero;
    Operacao *operador;
    char tipo;
} Elemento;

float soma(float a, float b);
float subtracao(float a, float b);
float multiplicacao(float a, float b);
float divisao(float a, float b);
float exponencial(float a, float b);
Elemento *numero(Elemento *e, float valor);
Elemento *operador(Elemento *e, char valor);

#endif