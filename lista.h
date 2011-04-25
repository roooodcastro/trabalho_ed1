#ifndef _LISTA_H
#define _LISTA_H


typedef struct {

    Elemento elementos[1000];
    int topo;
    
} Lista;

void construir_lista(Lista *l);

int append(Lista *l, Elemento e);
int insert(Lista *l, Elemento e, int pos);
int insertv(Lista *l, float valor, int pos);
int inserto(Lista *l, char valor, int pos);

typedef Lista Pilha;

int push(Pilha *p, Elemento e);
float pushv(Pilha *temp, float valor);
int pop(Pilha *p, Elemento *e);
float popv(Pilha *temp);


#endif 
