#include "lista.h"


//Funcoes de Lista
void construir_lista(Lista *l) {
    l->topo = -1;
}

int append(Lista *l, Elemento e) {
    return insert(l, e, -1);  
}

int insert(Lista *l, Elemento e, int pos){
    int i;
    if (pos > l->topo+1 || pos > 999 || pos < -1 || l->topo == 999)
        return 0;
    if (pos == -1)
        l->elementos[++(l->topo)] = e;
    else {
        for (i = l->topo; i >= pos; i--){
            l->elementos[i + 1] = l->elementos[i];
        }
        l->elementos[pos] = e;
        l->topo++;
    }
    return 1;    
}

int insertv(Lista *l, float valor, int pos){
    Elemento e;    
    insert(l, *numero(&e, valor), pos);
    return e.numero;
}

int inserto(Lista *l, char valor, int pos){
    Elemento e;    
    insert(l, *operador(&e, valor), pos);
    return e.tipo;
}


//Funcoes de Pilha
void construir_pilha(Pilha *p) {
    p->topo = -1;
}

int push(Pilha *p, Elemento e) {
    if (p->topo < 999) {
        p->elementos[++(p->topo)] = e;
        return 1;
    }
    return 0;
}

float pushv(Pilha *temp, float valor){
    Elemento e;    
    push(temp, *numero(&e, valor));
    return e.numero;
}

int pop(Pilha *p, Elemento *e) {
    if (p->topo > -1) {
        *e = p->elementos[(p->topo)--];
        return 1;
    } 
    return 0;
}

float popv(Pilha *temp){
    Elemento e;
    pop(temp, &e);
    return e.numero;
}
