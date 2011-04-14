#include "simplectest/tests.h"
#include "ed1.c"
#include "string.h"

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


END_TESTS()
