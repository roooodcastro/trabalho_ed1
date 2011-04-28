#ifndef _LISTA_H
#define _LISTA_H
#include "elemento.h"

typedef struct{
    Elemento elementos[1000];
    int ultimo;
} Lista;

typedef struct{
	Elemento elementos[1000];
    int topo;
} Pilha;

void construir_lista(Lista *l);
int append(Lista *l, Elemento e);
int add(Lista *l, Elemento e, int pos);
int addv(Lista *l, float valor, int pos);
int addo(Lista *l, char valor, int pos);

void construir_pilha(Pilha *p);
int push(Pilha *p, Elemento e);
int pop(Pilha *p, Elemento *e);
float popv(Pilha *temp);
float pushv(Pilha *temp, float valor);


#endif 