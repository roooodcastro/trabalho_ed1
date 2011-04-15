#include <string.h>
#include "simplectest/tests.h"
#include "types.h"
#include "ed1.c"


int comparar_elemento(Elemento ret, Elemento esp){
    if (ret.tipo != esp.tipo) 
        return 0;
    if ((ret.tipo == 'N') && (ret.numero != esp.numero))
        return 0;
    if ((ret.operador != esp.operador))
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
        ASSERT(operador(&e, '+') != 0);
        ASSERT(e.tipo == '+');
        ASSERT_EQUALS_FLOAT(e.numero, 0);
        ASSERT_EQUALS_FLOAT(e.operador(1, 1), 2);
    }

    TEST("Elemento -. Com Operador aplicado a 1, 1 retorna 0");
    {
        Elemento e;
        ASSERT(operador(&e, '-') != 0);
        ASSERT(e.tipo == '-');
        ASSERT_EQUALS_FLOAT(e.numero, 0);
        ASSERT_EQUALS_FLOAT(e.operador(1, 1), 0);
    }

    TEST("Elemento *. Com Operador aplicado a 1, 1 retorna 1");
    {
        Elemento e;
        ASSERT(operador(&e, '*') != 0);
        ASSERT(e.tipo == '*');
        ASSERT_EQUALS_FLOAT(e.numero, 0);
        ASSERT_EQUALS_FLOAT(e.operador(1, 1), 1);
    }

    TEST("Elemento /. Com Operador aplicado a 1, 1 retorna 1");
    {
        Elemento e;
        ASSERT(operador(&e, '/') != 0);
        ASSERT(e.tipo == '/');
        ASSERT_EQUALS_FLOAT(e.numero, 0);
        ASSERT_EQUALS_FLOAT(e.operador(1, 1), 1);
    }

    TEST("Elemento $. Com Operador aplicado a 2, 3 retorna 8");
    {
        Elemento e;
        ASSERT(operador(&e, '$') != 0);
        ASSERT(e.tipo == '$');
        ASSERT_EQUALS_FLOAT(e.numero, 0);
        ASSERT_EQUALS_FLOAT(e.operador(2, 3), 8);
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


START_TEST("Converter Notação Infixa para Posfixa")

    TEST("1 deve retornar e(1)")
    {
        Lista retorno;
        Lista esperado;
        Elemento e;

        construir_lista(&esperado);
        push(&esperado, *numero(&e, 1));
        
        infix_to_posfix(&retorno, "1");
        ASSERT(comparar_lista(retorno, esperado) == 1);
    }

    TEST("1.5 deve retornar e(1.5)")
    {
        Lista retorno;
        Lista esperado;
        Elemento e;

        construir_lista(&esperado);
        push(&esperado, *numero(&e, 1.5));
        
        infix_to_posfix(&retorno, "1.5");
        ASSERT(comparar_lista(retorno, esperado) == 1);
    }

    TEST("2 deve retornar e(2)")
    {
        Lista retorno;
        Lista esperado;
        Elemento e;

        construir_lista(&esperado);
        push(&esperado, *numero(&e, 2));
        
        infix_to_posfix(&retorno, "2");
        ASSERT(comparar_lista(retorno, esperado) == 1);
    }

    TEST("11 deve retornar e(11)")
    {
        Lista retorno;
        Lista esperado;
        Elemento e;

        construir_lista(&esperado);
        push(&esperado, *numero(&e, 11));
        
        infix_to_posfix(&retorno, "11");
        ASSERT(comparar_lista(retorno, esperado) == 1);
    }

    TEST("(1+1) deve retornar e(1), e(1), e('+')")
    {
        Lista retorno;
        Lista esperado;
        Elemento e;

        construir_lista(&esperado);
        push(&esperado, *numero(&e, 1));
        push(&esperado, *numero(&e, 1));
        push(&esperado, *operador(&e, '+'));
        
        infix_to_posfix(&retorno, "(1+1)");
        ASSERT(comparar_lista(retorno, esperado) == 1);
    }

    TEST("((1+1)+2) deve retornar e(1), e(1), e('+'), e(2), e('+')")
    {
        Lista retorno;
        Lista esperado;
        Elemento e;

        construir_lista(&esperado);
        push(&esperado, *numero(&e, 1));
        push(&esperado, *numero(&e, 1));
        push(&esperado, *operador(&e, '+'));
        push(&esperado, *numero(&e, 2));
        push(&esperado, *operador(&e, '+'));
        
        infix_to_posfix(&retorno, "((1+1)+2)");
        ASSERT(comparar_lista(retorno, esperado) == 1);
    }

    TEST("(1+(1+2)) deve retornar e(1), e(1), e(2), e('+'), e('+')")
    {
        Lista retorno;
        Lista esperado;
        Elemento e;

        construir_lista(&esperado);
        push(&esperado, *numero(&e, 1));
        push(&esperado, *numero(&e, 1));
        push(&esperado, *numero(&e, 2));
        push(&esperado, *operador(&e, '+'));
        push(&esperado, *operador(&e, '+'));
        
        infix_to_posfix(&retorno, "(1+(1+2))");
        ASSERT(comparar_lista(retorno, esperado) == 1);
    }

    TEST("((4-((1*(1+2))/3))$2) deve retornar e(4), e(1), e(1), e(2), e('+'), e('*'), e(3), e('/'), e(2), e($)")
    {
        Lista retorno;
        Lista esperado;
        Elemento e;

        construir_lista(&esperado);
        push(&esperado, *numero(&e, 4));
        push(&esperado, *numero(&e, 1));
        push(&esperado, *numero(&e, 1));
        push(&esperado, *numero(&e, 2));
        push(&esperado, *operador(&e, '+'));
        push(&esperado, *operador(&e, '*'));
        push(&esperado, *numero(&e, 3));
        push(&esperado, *operador(&e, '/'));
        push(&esperado, *operador(&e, '-'));
        push(&esperado, *numero(&e, 2));
        push(&esperado, *operador(&e, '$'));
        
        infix_to_posfix(&retorno, "((4-((1*(1+2))/3))$2)");
        ASSERT(comparar_lista(retorno, esperado) == 1);
    }


    TEST("'(1 + 1)', '     (1+1)    ', '     (    1    +    1    )   '  devem retornar e(1), e(1), e('+')")
    {
        Lista retorno;
        Lista esperado;
        Elemento e;

        construir_lista(&esperado);
        push(&esperado, *numero(&e, 1));
        push(&esperado, *numero(&e, 1));
        push(&esperado, *operador(&e, '+'));
        
        infix_to_posfix(&retorno, "(1 + 1)");
        ASSERT(comparar_lista(retorno, esperado) == 1);
        infix_to_posfix(&retorno, "     (1+1)    ");
        ASSERT(comparar_lista(retorno, esperado) == 1);
        infix_to_posfix(&retorno, "     (    1    +    1    )   ");
        ASSERT(comparar_lista(retorno, esperado) == 1);
    }

END_TEST()

START_TEST("Eval Posfix")
    
    TEST("e(1) deve retornar 1")
    {
        Lista posfix;
        Elemento e;

        construir_lista(&posfix);
        push(&posfix, *numero(&e, 1));
        
        ASSERT_EQUALS_FLOAT(eval_posfix(posfix), 1);
    }

    TEST("e(1), e(1), e('+') deve retornar 2")
    {
        Lista posfix;
        Elemento e;


        construir_lista(&posfix);
        push(&posfix, *numero(&e, 1));
        push(&posfix, *numero(&e, 1));
        push(&posfix, *operador(&e, '+'));
        
        ASSERT_EQUALS_FLOAT(eval_posfix(posfix), 2);
    }

    TEST("e(1), e(1), e(2), e('+'), e('+') deve retornar 4")
    {
        Lista posfix;
        Elemento e;


        construir_lista(&posfix);
        push(&posfix, *numero(&e, 1));
        push(&posfix, *numero(&e, 1));
        push(&posfix, *numero(&e, 2));
        push(&posfix, *operador(&e, '+'));
        push(&posfix, *operador(&e, '+'));
        
        ASSERT_EQUALS_FLOAT(eval_posfix(posfix), 4);
    }

    TEST("((4-((1*(1+2))/3))$2) deve retornar 9")
    {
        Lista posfix;
        infix_to_posfix(&posfix, "((4-((1*(1+2))/3))$2)");
        ASSERT_EQUALS_FLOAT(eval_posfix(posfix), 9);
    }

    TEST("(1.5+1.5) deve retornar 3")
    {
        Lista posfix;
        infix_to_posfix(&posfix, "(1.5+1.5)");
        ASSERT_EQUALS_FLOAT(eval_posfix(posfix), 3);
    }

    TEST("(6/2) deve retornar 3")
    {
        Lista posfix;
        infix_to_posfix(&posfix, "(6/2)");
        ASSERT_EQUALS_FLOAT(eval_posfix(posfix), 3);
    }
END_TEST()

END_TESTS()
