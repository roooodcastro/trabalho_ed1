#ifndef _ELEMENTO_H
#define _ELEMENTO_H

typedef float (Operacao)(float, float);

typedef struct {

    float numero;
    Operacao *operador;
    char tipo;
    
} Elemento;

Elemento *numero(Elemento*, float);
Elemento *operador(Elemento*, char);

float soma(float, float);
float subtracao(float, float);
float multiplicacao(float, float);
float divisao(float, float);
float exponencial(float, float);

#endif 
