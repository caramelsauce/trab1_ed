#ifndef PILHA_PONTEIROS
#define PILHA_PONTEIROS

#include <stdio.h>
#include <stdlib.h>

struct elemento{
	int valor;
	struct elemento *prev;
};

struct stack{
	struct elemento *top;
	int tam;
};

void inicPilha(struct stack *s, int t);

int pilhaVazia(struct stack *s);

int push(struct stack *s, int x);

int pop(struct stack *s);

int elemTopo(struct stack *s);

void printStack(struct stack *s, const char name[]);

int moveStack(struct stack *dest, struct stack *src);

#endif
