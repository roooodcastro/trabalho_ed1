#ifndef _POSFIX_H
#define _POSFIX_H

#include "lista.h"

//#ifdef __cplusplus
//extern "C" {
//              
//#endif
//
//__declspec( dllimport ) int isValid(char* exp);
//__declspec( dllimport ) Lista* convert(Lista *l, char* exp, int* func);
//__declspec( dllimport ) float eval_posfix(Lista l, int* func);
//__declspec( dllimport ) void toStringPosfixExpression(char* str, char* exp);
//
//#ifdef __cplusplus
//}
//#endif

Lista* convert(Lista *l, char* exp, int *func);
float eval_posfix(Lista l, int* func);
int isValid(char* exp);

#define IS_NUMERO(c) ((c >= '0' && c <= '9') || c == ',' || c == '.')
#define IS_OPERADOR(c) (c == '+' || c == '-' || c == '*' || c == '/' || c == '$')

float stof(char *text);
char* rtrim(char *s);
Lista* infix_to_posfix(Lista *l, char *infixa, int* func);
Lista* posfix_to_posfix(Lista *l, char *posfixa, int* func);
Lista* infix_to_infix(Lista *l, char *posfixa, int* func);


#endif 
