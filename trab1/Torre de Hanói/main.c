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

void menu(); // printa na tela as op��es do usu�rio

int main()
{
	setlocale(LC_ALL, "Portuguese");
	
	// declara��o de vari�veis
	
    struct stack P1, P2, P3; // as 3 Pilhas
    
    int op, quit = 0, cont = 0; // vari�veis de controle e um contador de movimentos
    
    // inicializa��o das Pilhas
    
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
    	
    	// mostrar as op��es e recolher a escolha do usu�rio
		menu(); 
    	scanf("%d", &op);
    	printf("\n");
    	
    	//escolha de handler para a op��o escolhida
    	switch(op){
    		case 1:
    			waitMove(&P1, &P2, &P3); // fica em loop at� um movimento v�lido
    			cont++; // incrementando o contador ap�s cada movimento
    			break;
    		case 2:
    			// printa no console como est�o as pilhas
    			printStack(&P1, "Pino 1");
    			printStack(&P2, "Pino 2");
    			printStack(&P3, "Pino 3");
    			break;
    		case 3:
    			// limpa o console
    			system(CLEAR);
    			break;
    		default:
    			printf("\nOp��o Inv�lida\n");
    			break;
		}
		// testando se as pilhas 1 e 2 est�o vazias para saber quando o jogo termina
		if(pilhaVazia(&P1) && pilhaVazia(&P2)){
			printStack(&P1, "Pino 1");
    		printStack(&P2, "Pino 2");
    		printStack(&P3, "Pino 3");
    		printf("Voc� resolveu em %d movimentos", cont);
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
	printf("Op��o: ");
}
