#ifndef _POSFIX_H
#define _POSFIX_H

#define IS_NUMERO(c) ((c >= '0' && c <= '9') || c == ',' || c == '.')
#define IS_OPERADOR(c) (c == '+' || c == '-' || c == '*' || c == '/' || c == '$')

float stof(char *text);
Lista *infix_to_posfix(Lista *l, char *infixa);
float eval_posfix(Lista l);
Lista *posfix_to_posfix(Lista *l, char *posfixa);

#endif 
