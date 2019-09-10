#include <stdio.h>
#include <stdlib.h>
#include "pilhaPonteiro.h"

void inicPilha(struct stack *s, int t)
{
	s->top = NULL;
	s->tam = t;
}

int pilhaVazia(struct stack *s)
{
	if(s->top == NULL)
		return 1;
	else
		return 0;
}

int push(struct stack *s, int x)
{
	struct elemento *novo = malloc(sizeof(struct elemento));
	novo->valor = x;
	if(pilhaVazia(s)){
		s->top = novo;
		s->top->prev = NULL;
	}
	else{
		novo->prev = s->top;
		s->top = novo;
	}
	return s->top->valor;
}

int pop(struct stack *s)
{
	struct elemento *aux = NULL;
	int valor;
	if(!pilhaVazia(s)){
		aux = s->top;
		s->top = s->top->prev;
	}
	valor = aux->valor;
	free(aux);
	return valor;
}

int elemTopo(struct stack *s)
{
	int valor;
	if(pilhaVazia(s)){
		printf("OPERAÇãO INVÁLIDA !!!\n Pilha Vazia\n");
		exit(1);
	}
	else
		valor = s->top->valor;
	return valor;
}

void printStack(struct stack *s, const char name[])
{
	struct elemento *aux = s->top;
	printf("\n%s", name);
	printf("\n\n");
	while(aux != NULL){
		printf("\t-%d-\n", aux->valor);
		aux = aux->prev;
	}
	printf("\n\n");
}

int moveStack(struct stack *dest, struct stack *src)
{
	if(pilhaVazia(src))
		return 0;
	else if(pilhaVazia(dest) || (src->top->valor < dest->top->valor)){
		push(dest, pop(src));
		return 1;
	}
	else return 0;	
}
