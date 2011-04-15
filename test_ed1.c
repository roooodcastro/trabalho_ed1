#include "simplectest/tests.h"
#include "ed1.c"
#include "string.h"

int comparar_elemento(Elemento ret, Elemento esp){
    if (ret.tipo != esp.tipo) 
        return 0;
    if ((ret.tipo == 'N') && (ret.numero != esp.numero))
        return 0;
    if ((ret.tipo == 'O') && (ret.operador != esp.operador))
        return 0;
    return 1;
}

int comparar_lista(Lista retorno, Lista esperado){
    int i = 0;
    if (retorno.topo != esperado.topo)
        return 0;
    for (i = 0; i<=retorno.topo; i++){
        if (!comparar_elemento(retorno.elementos[i], esperado.elementos[i])) 
            return 0;
        
    }
    return 1;
}

START_TESTS()

START_TEST("Struct Elemento")

    TEST("Elemento 1");
    {
        Elemento e;
        numero(&e, 1);
        ASSERT(e.tipo == 'N');
        ASSERT_EQUALS_FLOAT(e.numero, 1);
//        ASSERT_EQUALS_FLOAT(e.operador, '\0');
    }

    TEST("Elemento +. Com Operador aplicado a 1, 1 retorna 2");
    {
        Elemento e;
        ASSERT(operador(&e, '+') == 1);
        ASSERT(e.tipo == 'O');
        ASSERT_EQUALS_FLOAT(e.numero, 0);
        ASSERT_EQUALS_FLOAT(e.operador(1, 1), 2);
    }

    TEST("Elemento -. Com Operador aplicado a 1, 1 retorna 0");
    {
        Elemento e;
        ASSERT(operador(&e, '-') == 1);
        ASSERT(e.tipo == 'O');
        ASSERT_EQUALS_FLOAT(e.numero, 0);
        ASSERT_EQUALS_FLOAT(e.operador(1, 1), 0);
    }

    TEST("Elemento *. Com Operador aplicado a 1, 1 retorna 1");
    {
        Elemento e;
        ASSERT(operador(&e, '*') == 1);
        ASSERT(e.tipo == 'O');
        ASSERT_EQUALS_FLOAT(e.numero, 0);
        ASSERT_EQUALS_FLOAT(e.operador(1, 1), 1);
    }

    TEST("Elemento /. Com Operador aplicado a 1, 1 retorna 1");
    {
        Elemento e;
        ASSERT(operador(&e, '/') == 1);
        ASSERT(e.tipo == 'O');
        ASSERT_EQUALS_FLOAT(e.numero, 0);
        ASSERT_EQUALS_FLOAT(e.operador(1, 1), 1);
    }

    TEST("Elemento $. Com Operador aplicado a 2, 3 retorna 8");
    {
        Elemento e;
        ASSERT(operador(&e, '$') == 1);
        ASSERT(e.tipo == 'O');
        ASSERT_EQUALS_FLOAT(e.numero, 0);
        ASSERT_EQUALS_FLOAT(e.operador(3, 2), 8);
    }

    TEST("Elemento Operador 1 retorna 0");
    {
        Elemento e;
        ASSERT(operador(&e, '1') == 0);
        ASSERT(e.tipo == '?');
        ASSERT_EQUALS_FLOAT(e.numero, 0);
    }

END_TEST()

START_TEST("Lista")

    TEST("Lista Vazia");
    {
        Lista l;
        construir_lista(&l);
        ASSERT(l.topo == -1);
    }

    TEST("Push e Pop");
    {
        Lista l;
        Elemento e;
        construir_lista(&l);
        TEST("Push 1 em lista Vazia");
        numero(&e, 1);
        ASSERT(push(&l, e) == 1);
        ASSERT(l.topo == 0);
        ASSERT(l.elementos[0].numero == 1);
        
        TEST("Push 2 em lista que contem 1");
        numero(&e, 2);
        ASSERT(push(&l, e) == 1);
        ASSERT(l.topo == 1);
        ASSERT(l.elementos[0].numero == 1);
        ASSERT(l.elementos[1].numero == 2);

        TEST("Pop em lista que contem 1 2 retorna 2");
        pop(&l, &e);
        ASSERT(l.topo == 0);
        ASSERT(e.numero == 2);

        TEST("Pop em lista que contem 1 retorna 1");
        pop(&l, &e);
        ASSERT(l.topo == -1);
        ASSERT(e.numero == 1);

        TEST("Pop em lista vazia retorna 0");
        ASSERT(pop(&l, &e) == 0);
    }

END_TEST()

START_TEST("IS_NUMERO");

    TEST("Caracter 1 é número")
    ASSERT(IS_NUMERO('1') == 1);
    
    TEST("Caracter 2 é número")
    ASSERT(IS_NUMERO('2') == 1);
    
    TEST("Caracter 9 é número")
    ASSERT(IS_NUMERO('9') == 1);
  
    TEST("Caracter 0 é número")
    ASSERT(IS_NUMERO('0') == 1);
    
    TEST("Caracter A NÃO é número")
    ASSERT(IS_NUMERO('A') == 0);

END_TEST()

START_TEST("IS_LETRA");

    TEST("Caracter A é letra")
    ASSERT(IS_LETRA('A') == 1);
    
    TEST("Caracter B é letra")
    ASSERT(IS_LETRA('B') == 1);
    
    TEST("Caracter Z é letra")
    ASSERT(IS_LETRA('Z') == 1);
  
    TEST("Caracter a é letra")
    ASSERT(IS_LETRA('a') == 1);

    TEST("Caracter z é letra")
    ASSERT(IS_LETRA('z') == 1);

    TEST("Caracter y é letra")
    ASSERT(IS_LETRA('y') == 1);

    TEST("Caracter . é letra")
    ASSERT(IS_LETRA('.') == 1);
    
    TEST("Caracter , é letra")
    ASSERT(IS_LETRA(',') == 1);
    
    TEST("Caracter 1 NÃO é letra")
    ASSERT(IS_LETRA('1') == 0);

END_TEST()

START_TEST("IS_OPERADOR")

    TEST("Caracter + é operador")
    ASSERT(IS_OPERADOR('+') == 1);

    TEST("Caracter - é operador")
    ASSERT(IS_OPERADOR('-') == 1);

    TEST("Caracter * é operador")
    ASSERT(IS_OPERADOR('*') == 1);

    TEST("Caracter / é operador")
    ASSERT(IS_OPERADOR('/') == 1);

    TEST("Caracter $ é operador")
    ASSERT(IS_OPERADOR('$') == 1);

    TEST("Caracter A não é operador")
    ASSERT(IS_OPERADOR('A') == 0);

END_TEST()


START_TEST("Converter Notação")

    TEST("1 deve retornar elemento(1, 'N')")
    {
        Lista retorno;
        
        Elemento e;
        numero(&e, 1);
        Lista esperado;
        construir_lista(&esperado);
        push(&esperado, e);
        
//        converter_notacao(&retorno, "1");
//        ASSERT(comparar_lista(retorno, esperado) == 1);

    }

END_TEST()

END_TESTS()
