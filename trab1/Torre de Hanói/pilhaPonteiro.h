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
};

void inicPilha(struct stack *s);

int pilhaVazia(struct stack *s);

int push(struct stack *s, int x);

int pop(struct stack *s);

int elemTopo(struct stack *s);

void printStack(struct stack *s, const char name[]);

int moveDisc(struct stack *dest, struct stack *src);

void waitMove(struct stack *P1, struct stack *P2, struct stack *P3);

#endif
