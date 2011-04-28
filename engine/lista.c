#include "lista.h"

void construir_lista(Lista *l)
{
    l->ultimo = -1;
}

void construir_pilha(Pilha *p)
{
    p->topo = -1;
}

int push(Pilha *p, Elemento e)
{
    if (p->topo < 999) {
        p->elementos[++(p->topo)] = e;
        return 1;
    }
    return 0;
}


int pop(Pilha *p, Elemento *e)
{
    if (p->topo > -1) {
        *e = p->elementos[(p->topo)--];
        return 1;
    } 
    return 0;
}

int append(Lista *l, Elemento e)
{
    return add(l, e, -1);  
}

int add(Lista *l, Elemento e, int pos){
    int i;
    if (pos > l->ultimo+1 || pos > 999 || pos < -1 || l->ultimo == 999)
        return 0;
    if (pos == -1)
        l->elementos[++(l->ultimo)] = e;
    else {
        for (i = l->ultimo; i >= pos; i--){
            l->elementos[i + 1] = l->elementos[i];
        }
        l->elementos[pos] = e;
        l->ultimo++;
    }
    return 1;    
}

int addv(Lista *l, float valor, int pos){
    Elemento e;    
    add(l, *numero(&e, valor), pos);
    return e.numero;
}

int addo(Lista *l, char valor, int pos){
    Elemento e;    
    add(l, *operador(&e, valor), pos);
    return e.tipo;
}


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
