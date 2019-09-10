#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include "pilhaVetor.h"

int main()
{
    setlocale(LC_ALL, "Portuguese");
    
    // declara��o de vari�veis
    
	int num, t, i;
	
	struct stack s;
	// loop principal que sai quando um n�mero <=0 � digitado
	
	do{

		printf("\nDigite um n�mero: ");
		scanf("%d", &num);
		
		// uso de uma vari�vel i para empilhar os restos enquanto o num � usado para condi��o de sa�da
		
		i = num;
		
		// inicializando a pilha com o tamanho certo usando log2(n) + 1
		
		t = ((int) log2((float) num)) + 1;
		inicPilha(&s, t);
		
		// loop para empilhar os restos
		
		while(i > 0)
		{
			push(&s, (i%2));
			i /= 2;
		}
		printf("\n");
		
		// desempilhando e printando os restos
		
		while(!pilhaVazia(&s))
		{
			printf("%d", pop(&s));
		}
	}while(num > 0);
    return 0;
}
