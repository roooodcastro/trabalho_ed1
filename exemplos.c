#include <stdio.h>
#include <string.h>


char OP_FECHAR = ')';
char OP_SOMA = '+';
char OP_SUBTRACAO = '-';
char OP_MULTIPLICACAO = '*';
char OP_DIVISAO = '/';
char OP_RESTO = '%';
char OP_EXPONENCIAL = '^';
char buffer[1000];
int topo = -1;

void push(char elem) {
	if(topo < 1000) {
		buffer[++topo] = elem;
	}
}

char pop() {
	if (topo >= 0) {
		char elem = buffer[topo--];
		return elem;
	}
}

int is_numero(char c) {
	return (c >= 48 && c <= 57);
}

int is_letra(char c) {
	return ((c >= 65 && c <= 90) || (c >= 97 && c < 122) || c == ',');
}

int is_operador(char c) {
	return (c == OP_SOMA || c == OP_SUBTRACAO || c == OP_MULTIPLICACAO || c == OP_DIVISAO);
}

void converter_notacao(char* expressao, char* string) {
	char aux[255];
	int tamanho = 0;
	int i = 0;
	while (expressao[i] != '\0') {
	    if (expressao[i] == OP_FECHAR) {
		    char op;
		    op = pop();
	        if (op != '\0') {
	            string[tamanho++] = op;
	        }
	    }
	    else if(is_numero(expressao[i]) == 1 || is_letra(expressao[i]) == 1) {
	        string[tamanho++] = expressao[i];
	    }
	    else if (is_operador(expressao[i]) == 1) {
	        push(expressao[i]);
	        string[tamanho++] = ' ';
	    }
	    i++;
	}
	string[tamanho] = '\0';
}

int eval(char* expressao) {
	char posfixa[1000];
	if (expressao[0] == '(')
		converter_notacao(expressao, posfixa);
	else
		strcpy(posfixa, expressao);
	printf("%s\n", posfixa);
	int i = 0;
	char temp[1000];
	while(posfixa[i] != '\0') {
		if (is_numero(posfixa[i])) {
			sprintf(temp, "%s%c", temp, posfixa[i]);
		}
		else {
			push(temp);
			//if (is_operador
		}
	}
	
	
	
}

void main() {
	char string[1000];
	//converterNotacao("((33+46)+52)", string);
	//printf("%s\n", string);
	eval("((33+46)+52)");
	eval("1 1+");
}

