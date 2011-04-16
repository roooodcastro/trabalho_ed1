#ifndef _LISTA_H
#define _LISTA_H


typedef struct{
    Elemento elementos[1000];
    int topo ;
} Lista;

void construir_lista(Lista *l);
int append(Lista *l, Elemento e, int pos);

typedef Lista Pilha;
int push(Pilha *p, Elemento e);
int pop(Pilha *p, Elemento *e);

float popv(Pilha *temp);
float pushv(Pilha *temp, float valor);


#endif 
