#ifndef PILHA_VETOR
#define PILHA_VETOR

#include <stdio.h>
#include <stdlib.h>

struct stack{
	int tam, top;
	int *dados;
};

void inicPilha(struct stack *s);

struct stack *criarPilha(int t);

int pilhaVazia(struct stack *s);

int pilhaCheia(struct stack *s);

int push(struct stack *s, int x);

int pop(struct stack *s);

int elemTopo(struct stack *s);

void printStack(struct stack *s, const char name[]);

int moveDisc(struct stack *dest, struct stack *src);

void waitMove(struct stack *P1, struct stack *P2, struct stack *P3);

#endif
