#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "pilhaPonteiro.h"


// macro para usar o system(clear) no windows e em sistemas posix
#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

void menu(); // printa na tela as opções do usuário

void waitMove(struct stack *P1, struct stack *P2, struct stack *P3);

int main()
{
	setlocale(LC_ALL, "Portuguese");
	
	// declaração de variáveis
	
    struct stack P1, P2, P3; // as 3 Pilhas
    
    int op, quit = 0, cont = 0; // variáveis de controle e um contador de movimentos
    
    // inicialização das Pilhas
    
    inicPilha(&P1);
    inicPilha(&P2);
    inicPilha(&P3);
    
    
    // Empilhando os "discos" no primeiro "pino"
    
    push(&P1, 5);
    push(&P1, 4);
    push(&P1, 3);
    push(&P1, 2);
    push(&P1, 1);
    
    // loop principal do programa
    
    while(!quit){
    	
    	// mostrar as opções e recolher a escolha do usuário
		menu(); 
    	scanf("%d", &op);
    	printf("\n");
    	
    	//escolha de handler para a opção escolhida
    	switch(op){
    		case 1:
    			waitMove(&P1, &P2, &P3); // fica em loop até um movimento válido
    			cont++; // incrementando o contador após cada movimento
    			break;
    		case 2:
    			// printa no console como estão as pilhas
    			printStack(&P1, "Pino 1");
    			printStack(&P2, "Pino 2");
    			printStack(&P3, "Pino 3");
    			break;
    		case 3:
    			// limpa o console
    			system(CLEAR);
    			break;
    		default:
    			printf("\nOpção Inválida\n");
    			break;
		}
		// testando se as pilhas 1 e 2 estão vazias para saber quando o jogo termina
		if(pilhaVazia(&P1) && pilhaVazia(&P2)){
			printStack(&P1, "Pino 1");
    		printStack(&P2, "Pino 2");
    		printStack(&P3, "Pino 3");
    		printf("Você resolveu em %d movimentos", cont);
    		quit = 1;
    	}
	}
    return 0;
}

void menu()
{
	printf("\n\n");
	printf("1 - Mover Disco\n");
	printf("2 - Visualizar Pinos\n");
	printf("3 - Limpar a tela\n");
	printf("Opção: ");
}

void waitMove(struct stack *P1, struct stack *P2, struct stack *P3)
{
	while(1){
		int src, dest;
   		printf("\nMover de Pino: ");
   		scanf("%d", &src);
   		printf("\nPara Pino: ");
   		scanf("%d", &dest);
   		if(src == 1 && dest == 2){
			if(moveStack(P2, P1)){
				printf("\nMovido Com Sucesso");
				return;
			}
			else{
				printf("\nMovimento Inválido\n");
				printStack(P1, "Pino 1");
    			printStack(P2, "Pino 2");
    			printStack(P3, "Pino 3");
    		}
		}
   		else if(src == 1 && dest == 3){
			if(moveStack(P3, P1)){
				printf("\nMovido Com Sucesso");
				return;
			}
			else{
				printf("\nMovimento Inválido\n");
				printStack(P1, "Pino 1");
    			printStack(P2, "Pino 2");
    			printStack(P3, "Pino 3");
    		}
		}
   		else if(src == 2 && dest == 1){
			if(moveStack(P1, P2)){
				printf("\nMovido Com Sucesso");
				return;
			}
			else{
				printf("\nMovimento Inválido\n");
				printStack(P1, "Pino 1");
    			printStack(P2, "Pino 2");
    			printStack(P3, "Pino 3");
    		}
		}
   		else if(src == 2 && dest == 3){
			if(moveStack(P3, P2)){
				printf("\nMovido Com Sucesso");
				return;
			}
			else{
				printf("\nMovimento Inválido\n");
				printStack(P1, "Pino 1");
    			printStack(P2, "Pino 2");
    			printStack(P3, "Pino 3");
    		}
		}
   		else if(src == 3 && dest == 1){ 
			if(moveStack(P1, P3)){
				printf("\nMovido Com Sucesso");
				return;
			}
			else{
				printf("\nMovimento Inválido\n");
				printStack(P1, "Pino 1");
    			printStack(P2, "Pino 2");
    			printStack(P3, "Pino 3");
    		}
		}
   		else if(src == 3 && dest == 2){ 
			if(moveStack(P2, P3)){
				printf("\nMovido Com Sucesso");
				return;
			}
			else{
				printf("\nMovimento Inválido\n");
				printStack(P1, "Pino 1");
    			printStack(P2, "Pino 2");
    			printStack(P3, "Pino 3");
    		}
		}
		else
			printf("\nEscolha entre os Pinos 1 a 3\n");
	}
}
