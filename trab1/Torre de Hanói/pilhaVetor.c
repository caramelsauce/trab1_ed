#include <stdio.h>
#include <stdlib.h>
#include "pilhaVetor.h"

void inicPilha(struct stack *s)
{
	s->tam = 5;
	s->top = -1;
	s->dados = malloc(sizeof(int) * 5);
}

struct stack *criarPilha(int t)
{
//aloca a pilha e o vetor de dados dentro dela
	struct stack *s = malloc(sizeof (struct stack));
	s->tam = t;
	s->top = -1;
	s->dados = malloc(sizeof(int) * t);
	return s;
}

int pilhaVazia(struct stack *s)
{
//checa se a pilha está vazia retornando 1 se ela estiver vazia e retornando 0 caso não esteja
	if(s->top == -1)
		return 1;
	else
		return 0;
}

int pilhaCheia(struct stack *s)
{
//checa se a pilha está cheia retornando 1 se ela estiver cheia e retornando 0 caso não esteja
	if(s->top == (s->tam - 1))
		return 1;
	else
		return 0;
}

int push(struct stack *s, int x)
{
//empilha um dado na pilha ou para a execução se ocorrer overflow
	if(pilhaCheia(s)){
		printf("\n OVERFLOW \n");
		exit(1);
	}
	else
		return (s->dados[++(s->top)] = x);
}

int pop(struct stack *s)
{
//desempilha o dado no topo da pilha ou para a execução se ocorrer underflow
	if(pilhaVazia(s)){
		printf("\n UNDERFLOW \n");
		exit(1);
	}
	else
		return (s->dados[(s->top) --]);
}

int elemTopo(struct stack *s)
{
//retorna o dado no topo da pilha ou para a execução se ocorrer underflow
	if(pilhaVazia(s)){
		printf("\n UNDERFLOW \n");
		exit(1);
	}
	else
		return (s->dados[s->top]);
}

void printStack(struct stack *s, const char name[])
{
	int i;
	printf("\n%s", name);
	printf("\n\n");
	for(i=s->top; i>=0; i--)
		printf("\t-%d-\n", s->dados[i]);
	printf("\n\n");	
}

int moveStack(struct stack *dest, struct stack *src)
{
	if(pilhaVazia(src))
		return 0;
	else if(pilhaVazia(dest) || (src->dados[src->top] < dest->dados[dest->top])){
		push(dest, pop(src));
		return 1;
	}
	else return 0;	
}


