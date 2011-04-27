#include <string.h>
#include "simplectest/tests.h"
#include "elemento.c"
#include "lista.c"
#include "posfix.c"



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
{
    Elemento e;
    TEST("Elemento 1");
    {
        numero(&e, 1);
        ASSERT(e.tipo == 'N');
        ASSERT_EQUALS_FLOAT(e.numero, 1);
    }

    TEST("Elemento +. Com Operador aplicado a 1, 1 retorna 2");
    {
        ASSERT(operador(&e, '+') != 0);
        ASSERT(e.tipo == '+');
        ASSERT_EQUALS_FLOAT(e.numero, 0);
        ASSERT_EQUALS_FLOAT(e.operador(1, 1), 2);
    }

    TEST("Elemento -. Com Operador aplicado a 1, 1 retorna 0");
    {
        ASSERT(operador(&e, '-') != 0);
        ASSERT(e.tipo == '-');
        ASSERT_EQUALS_FLOAT(e.numero, 0);
        ASSERT_EQUALS_FLOAT(e.operador(1, 1), 0);
    }

    TEST("Elemento *. Com Operador aplicado a 1, 1 retorna 1");
    {
        ASSERT(operador(&e, '*') != 0);
        ASSERT(e.tipo == '*');
        ASSERT_EQUALS_FLOAT(e.numero, 0);
        ASSERT_EQUALS_FLOAT(e.operador(1, 1), 1);
    }

    TEST("Elemento /. Com Operador aplicado a 1, 1 retorna 1");
    {
        ASSERT(operador(&e, '/') != 0);
        ASSERT(e.tipo == '/');
        ASSERT_EQUALS_FLOAT(e.numero, 0);
        ASSERT_EQUALS_FLOAT(e.operador(1, 1), 1);
    }

    TEST("Elemento $. Com Operador aplicado a 2, 3 retorna 8");
    {
        ASSERT(operador(&e, '$') != 0);
        ASSERT(e.tipo == '$');
        ASSERT_EQUALS_FLOAT(e.numero, 0);
        ASSERT_EQUALS_FLOAT(e.operador(2, 3), 8);
    }

    TEST("Elemento Operador 1 retorna 0");
    {
        ASSERT(operador(&e, '1') == 0);
        ASSERT(e.tipo == '?');
        ASSERT_EQUALS_FLOAT(e.numero, 0);
    }
}
END_TEST()

START_TEST("Lista e Pilha")
{
    
    Elemento e;

    TEST("Lista Vazia");
    {
        Lista l;
        construir_lista(&l);
        ASSERT(l.topo == -1);
    }

    TEST("Push e Pop");
    {
        Pilha p; 
        construir_lista(&p);
        int passa = 1;
        int i = 0;

        TEST("Adicionar 1000 elementos a pilha");
        passa = 1;        
        for (i = 1; i <= 1000; i++){
            passa &= (push(&p, *numero(&e, i)) == 1) && (p.topo == i-1);
        }       
        ASSERT(passa == 1);

        TEST("Remover 1000 elementos da pilha");
        passa = 1;        
        for (i = 1000; i >= 1; i--){
            passa &= (pop(&p, &e) == 1) && (p.topo == i-2) && (e.numero == i);
        }       
        ASSERT(passa == 1);

        TEST("Pop em lista vazia retorna 0");
        ASSERT(pop(&p, &e) == 0);
    }

    TEST("add");
    {
        Lista l;
        Elemento e;
        int i = 0;
        int passa = 1;

        construir_lista(&l);
        TEST("Adicionar 1000 elementos a lista");
        passa = 1;
        for (i = 1; i <= 1000; i++){
            passa &= (add(&l, *numero(&e, i), -1) == 1) && (l.topo == i-1) && (l.elementos[i-1].numero == i);
        }       
        ASSERT(passa == 1);
       
        TEST("Adicionar elemento em lista lotada");
        ASSERT(add(&l, *numero(&e, 1001), -1) == 0);

        construir_lista(&l);

        TEST("Adicionar elementos na ordem -1 -1 0 0 1 4 6")
        int posicoes[] = {-1, -1, 0, 0, 1, 4, 6};
        passa = 1;
        for (i = 0; i < 7; i++){
            passa &= (add(&l, *numero(&e, i+1), posicoes[i]) == 1) && (l.topo == i);
        }        
        ASSERT(passa == 1);
        ASSERT(l.topo == 6);
        ASSERT(l.elementos[0].numero == 4);
        ASSERT(l.elementos[1].numero == 5);
        ASSERT(l.elementos[2].numero == 3);
        ASSERT(l.elementos[3].numero == 1);
        ASSERT(l.elementos[4].numero == 6);
        ASSERT(l.elementos[5].numero == 2);
        ASSERT(l.elementos[6].numero == 7);

        TEST("Append elemento 8 na posicao 8 da lista deve falhar")
        ASSERT(add(&l, *numero(&e, 8), 8) == 0);
        ASSERT(l.topo == 6);
        
        TEST("Append elemento 9 na posicao -2 da lista deve falhar")
        ASSERT(add(&l, *numero(&e, 9), -2) == 0);
        ASSERT(l.topo == 6);
    }
}
END_TEST()

START_TEST("IS_NUMERO");
{
    TEST("Caracteres 0..9 são numeros")    
    char i;
    for (i = '0'; i <= '9'; i++){     
        ASSERT(IS_NUMERO(i) == 1);
    }

    TEST("Caracter A NÃO é número")
    ASSERT(IS_NUMERO('A') == 0);
}
END_TEST()

START_TEST("IS_OPERADOR")
{
    TEST("Caracteres +-*/$ são operadores")    
    int i;
    char op[] = "+-*/$";
    for (i = 0; op[i] != '\0'; i++){     
        ASSERT(IS_OPERADOR(op[i]) == 1);
    }
 
    TEST("Caracter A não é operador")
    ASSERT(IS_OPERADOR('A') == 0);
}
END_TEST()


START_TEST("Converter Notação Infixa para Posfixa")
{    
    Lista retorno;
    Lista esperado;
    Elemento e;
    int func;

    TEST("1 deve retornar e(1)")
    {
        construir_lista(&esperado);
        addv(&esperado, 1, -1);
        func = 0;
        infix_to_posfix(&retorno, "1", &func);
        ASSERT(comparar_lista(retorno, esperado) == 1);
    }

    TEST("1.5 deve retornar e(1.5)")
    {
        construir_lista(&esperado);
        addv(&esperado, 1.5, -1);
        func = 0;
        infix_to_posfix(&retorno, "1.5", &func);
        ASSERT(comparar_lista(retorno, esperado) == 1);
    }

    TEST("2 deve retornar e(2)")
    {
        construir_lista(&esperado);
        addv(&esperado, 2, -1);
        func = 0;
        infix_to_posfix(&retorno, "2", &func);
        ASSERT(comparar_lista(retorno, esperado) == 1);
    }

    TEST("11 deve retornar e(11)")
    {
        construir_lista(&esperado);
        addv(&esperado, 11, -1);
        func = 0;
        infix_to_posfix(&retorno, "11", &func);
        ASSERT(comparar_lista(retorno, esperado) == 1);
    }

    TEST("(1+1) deve retornar e(1), e(1), e('+')")
    {
        construir_lista(&esperado);
        addv(&esperado, 1, -1);
        addv(&esperado, 1, -1);
        addo(&esperado, '+', -1);
        func = 0;
        infix_to_posfix(&retorno, "(1+1)", &func);
        ASSERT(comparar_lista(retorno, esperado) == 1);
    }

    TEST("((1+1)+2) deve retornar e(1), e(1), e('+'), e(2), e('+')")
    {
        construir_lista(&esperado);
        addv(&esperado, 1, -1);
        addv(&esperado, 1, -1);
        addo(&esperado, '+', -1);
        addv(&esperado, 2, -1);
        addo(&esperado, '+', -1);
        func = 0;
        infix_to_posfix(&retorno, "((1+1)+2)", &func);
        ASSERT(comparar_lista(retorno, esperado) == 1);
    }

    TEST("(1+(1+2)) deve retornar e(1), e(1), e(2), e('+'), e('+')")
    {
        construir_lista(&esperado);
        addv(&esperado, 1, -1);
        addv(&esperado, 1, -1);
        addv(&esperado, 2, -1);
        addo(&esperado, '+', -1);
        addo(&esperado, '+', -1);
        func = 0;
        infix_to_posfix(&retorno, "(1+(1+2))", &func);
        ASSERT(comparar_lista(retorno, esperado) == 1);
    }

    TEST("((4-((1*(1+2))/3))$2) deve retornar e(4), e(1), e(1), e(2), e('+'), e('*'), e(3), e('/'), e(2), e($)")
    {
        construir_lista(&esperado);
        addv(&esperado, 4, -1);
        addv(&esperado, 1, -1);
        addv(&esperado, 1, -1);
        addv(&esperado, 2, -1);
        addo(&esperado, '+', -1);
        addo(&esperado, '*', -1);
        addv(&esperado, 3, -1);
        addo(&esperado, '/', -1);
        addo(&esperado, '-', -1);
        addv(&esperado, 2, -1);
        addo(&esperado, '$', -1);
        func = 0;
        infix_to_posfix(&retorno, "((4-((1*(1+2))/3))$2)", &func);
        ASSERT(comparar_lista(retorno, esperado) == 1);
    }


    TEST("'(1 + 1)', '     (1+1)    ', '     (    1    +    1    )   '  devem retornar e(1), e(1), e('+')")
    {
        construir_lista(&esperado);
        addv(&esperado, 1, -1);
        addv(&esperado, 1, -1);
        addo(&esperado, '+', -1);
        func = 0;
        infix_to_posfix(&retorno, "(1 + 1)",&func);
        ASSERT(comparar_lista(retorno, esperado) == 1);
        func = 0;
        infix_to_posfix(&retorno, "     (1+1)    ", &func);
        ASSERT(comparar_lista(retorno, esperado) == 1);
        func = 0;
        infix_to_posfix(&retorno, "     (    1    +    1    )   ", &func);
        ASSERT(comparar_lista(retorno, esperado) == 1);
    }
}
END_TEST()

START_TEST("Eval Posfix")
{    
    Lista posfix;
    int func;

    TEST("e(1) deve retornar 1")
    {
        func = 0;
        posfix = *posfix_to_posfix(&posfix, "1", &func);
        ASSERT_EQUALS_FLOAT(eval_posfix(posfix, &func), 1);
    }

    
    TEST("e(1), e(1), e('+') deve retornar 2")
    {
        func = 0;
        posfix = *posfix_to_posfix(&posfix, "1 1 +", &func);
        ASSERT_EQUALS_FLOAT(eval_posfix(posfix, &func), 2);
    }

    TEST("e(1), e(1), e(2), e('+'), e('+') deve retornar 4")
    {    
        func = 0;
        posfix = *posfix_to_posfix(&posfix, "1 1 2 + +", &func);
        ASSERT_EQUALS_FLOAT(eval_posfix(posfix, &func), 4);
    }

    TEST("((4-((1*(1+2))/3))$2) deve retornar 9")
    {
        func = 0;
        posfix = *infix_to_posfix(&posfix, "((4-((1*(1+2))/3))$2)", &func);
        ASSERT_EQUALS_FLOAT(eval_posfix(posfix, &func), 9);
    }

    TEST("(1.5+1.5) deve retornar 3")
    {
        func = 0;
        posfix = *infix_to_posfix(&posfix, "(1.5+1.5)", &func);
        ASSERT_EQUALS_FLOAT(eval_posfix(posfix, &func), 3);
    }
    
    TEST("(6/2) deve retornar 3")
    {
        func = 0;
        posfix = *infix_to_posfix(&posfix, "(6/2)", &func);
        ASSERT_EQUALS_FLOAT(eval_posfix(posfix, &func), 3);
    }

    TEST("(1. + .1) deve retornar 1.1")
    {
        func = 0;
        posfix = *infix_to_posfix(&posfix, "(1. + .1)", &func);
        ASSERT_EQUALS_FLOAT(eval_posfix(posfix, &func), 1.1);
    }

    TEST("(.1 + .1) deve retornar 0.2")
    {
        func = 0;
        posfix = *infix_to_posfix(&posfix, "(.1 + .1)", &func);
        ASSERT_EQUALS_FLOAT(eval_posfix(posfix, &func), 0.2);
    }
}
END_TEST()

START_TEST("Posfix para Posfix") 
{
    Lista retorno;
    Lista esperado;
    int func = 0;

    TEST("'1 1 +' deve retornar e(1), e(1), e('+')")
    {
        func = 0;
        retorno = *posfix_to_posfix(&retorno, "1 1 +", &func);
        esperado = *infix_to_posfix(&esperado, "(1+1)", &func);
        ASSERT(comparar_lista(retorno, esperado) == 1);
    }

    TEST("'1 1+' deve retornar e(1), e(1), e(+)")
    {
        func = 0;
        retorno = *posfix_to_posfix(&retorno, "1 1+", &func);
        esperado = *infix_to_posfix(&esperado, "(1+1)", &func);
        ASSERT(comparar_lista(retorno, esperado) == 1);
    }

    TEST("'    2    1    1+-' deve retornar e(2), e(1), e(1), e(+), e(-)")
    {
        func = 0;
        retorno = *posfix_to_posfix(&retorno, "     2    1    1+-", &func); 
        esperado = *infix_to_posfix(&esperado, "(2-(1+1))", &func);
        ASSERT(comparar_lista(retorno, esperado) == 1);
    }

}
END_TEST()

START_TEST("Is Valid") 
{
    TEST("'1' é valido")
    ASSERT(isValid("1") == 0);

    TEST("'+' não é valido")
    ASSERT(isValid("+") == 1);

    TEST("'(1)' não é valido")
    ASSERT(isValid("(1)") == 2);

    TEST("'(1+1)' é valido")
    ASSERT(isValid("(1+1)") == 0);

    TEST("'(1++)' não é valido")
    ASSERT(isValid("(1++)") == 6);

    TEST("'(1 1 1)' não é valido")
    ASSERT(isValid("(1 1 1)") == 4);

    TEST("'1 1 + 1)' não é valido")
    ASSERT(isValid("1 1 + 1)") == 5);

    TEST("'( 1 + 1 1' não é valido")
    ASSERT(isValid("( 1 + 1 1") == 5);

    TEST("'(1 + 1 + 1)' não é valido")
    ASSERT(isValid("(1 + 1 + 1)") == 6);

    TEST("'((1 + 1) + 1)' é valido")
    ASSERT(isValid("((1 + 1) + 1)") == 0);

    TEST("'(1 + 1( + 1)' não é valido")
    ASSERT(isValid("(1 + 1( + 1)") == 7);

    TEST("'(1 + 1) + 1)' não é valido")
    ASSERT(isValid("(1 + 1) + 1)") == 7);

    TEST("'((1+1) + (1+1))' é valido")
    ASSERT(isValid("((1 + 1) + (1+1))") == 0);

    TEST("'((1+(1+1)) + (1+1))' é valido")
    ASSERT(isValid("((1+(1+1)) + (1+1))") == 0);

    TEST("'((1+(1+(1))) + (1+1))' não é valido")
    ASSERT(isValid("((1+(1+(1))) + (1+1))") == 2);

    TEST("'((1+1))' não é valido")
    ASSERT(isValid("((1+1))") == 4);
 
    TEST("'(1+)' não é valido")
    ASSERT(isValid("(1+)") == 2);
 
    TEST("'(+(1+1))' não é valido")
    ASSERT(isValid("(+(1+1))") == 2);
  
    TEST("'+(1+1))' não é valido")
    ASSERT(isValid("+(1+1))") == 5);

    TEST("'()' não é valido")
    ASSERT(isValid("()") == 2);
    
    TEST("'(1+())' não é valido")
    ASSERT(isValid("(1+())") == 2);
    
    TEST("'(()+1)' não é valido")
    ASSERT(isValid("(()+1)") == 2);

    TEST("'1 1 +' é valido")
    ASSERT(isValid("1 1 +") == 0);

    TEST("'+ 1 1 1 +' não é valido")
    ASSERT(isValid("+ 1 1 1 +") != 0);
 
    TEST("'1 + 1 1 +' não é valido")
    ASSERT(isValid("1 + 1 1 +") != 0);

    TEST("'(1 1) +' não é valido")
    ASSERT(isValid("(1 1)+") != 0);

    TEST("'1 1 )' não é valido")
    ASSERT(isValid("1 1 )") != 0);

    TEST("'1 ( 1 1 +' não é valido")
    ASSERT(isValid("1 ( 1 1 +") != 0);

}
END_TEST()


END_TESTS()
