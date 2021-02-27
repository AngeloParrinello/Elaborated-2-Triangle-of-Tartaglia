/********************************************************************************
*                                                                              *
*                   Architetture dei sistemi di Elaborazione                   *
*                                                                              *
********************************************************************************

Elaborato 2
Descrizione: Dato in input il livello massimo richiesto, restituire il rispettivo
triangolo di Tartaglia memorizzando consecutivamente i vari livelli
all'interno di un array monodimensionale.

********************************************************************************/

#include <stdio.h>

void main()
{
	// Input
	unsigned int livello = 14;		// livello massimo del triangolo di tartaglia da generare

									// Output
	unsigned int triangolo[1024];	// risultato: il vettore contiene i numeri del 
									// triangolo dal livello 0 al più alto richiesto

	unsigned int i;
	unsigned int k = 0;

	__asm
	{
		XOR EAX, EAX //contatore all'interno del triangolo
		XOR EBX, EBX //sarà il num.livelli
		XOR ECX, ECX //sarà i
		XOR EDX, EDX //sarà k
		XOR EDI, EDI
		XOR ESI, ESI

		MOV EBX,livello //INIZIO LV0
		//MOV i, ECX
		MOV triangolo[EAX*4], 1
		INC EAX
		CMP ECX, EBX
		JE FINE //FINE LV0

		INC ECX //INIZIO LV1
		MOV triangolo[EAX*4], 1
		INC EAX
		MOV triangolo[EAX*4], 1
		INC EAX
		CMP ECX, EBX
		JE FINE
		INC ECX//FINE LV1

		PRE : //INIZIO LV.2 E SUCC.
			//MOV EDX, k

			//CICLO :
		CMP EDX, 0 //CONTROLLO SE SIAMO AL PRIMO ELEMENTO DEL LIVELLO
			JE UGUALI
			JMP CICLO1

			UGUALI :
		MOV triangolo[EAX*4], 1 //SIAMO AL PRIMO ELEMENTO DEL LIVELLO
			INC EAX
			INC EDX
			JMP CICLO1

			CICLO1 :
		CMP EDX, ECX //CONTROLLO SE SIAMO ALL'ULTIMO ELEMENTO DEL LIVELLO 
			JE UGUALI1
			JMP CICLO2

			UGUALI1 :
		MOV triangolo[EAX*4], 1 //SIAMO ALL'ULTIMO ELEMENTO DEL LIVELLO
			INC EAX
			INC ECX //INCREMENTO IL CONTATORE DEL LIVELLO
			XOR EDX, EDX //AZZERO IL CONTATORE DEGLI ELEMENTI DEL LIVELLO
			CMP ECX, EBX //IL CONTATORE è ARRIVATO AL NUMERO DI LIVELLI?
			JA  FINE //SE MAGGIORE DEL NUMERO DI LIVELLI ALLORE FINIAMO
			JMP PRE

			CICLO2 :
		    MOV ESI,EAX
			SUB ESI,ECX
			MOV ESI,triangolo[ESI*4]
		    MOV triangolo[EAX*4], ESI//triangolo[ESI]
			XOR ESI,ESI//DEC ESI
 			MOV ESI,EAX//MOV EDI,ESI
			SUB ESI,ECX
			DEC ESI
			MOV ESI,triangolo[ESI*4]
			ADD triangolo[EAX*4], ESI //triangolo[EDI]
			INC EAX
			INC EDX
			CMP EDX,ECX 
			//XOR ESI,ESI
			//XOR EDI,EDI
			JE UGUALI1
			JMP CICLO2
			
				FINE:






	}

	// Stampa su video
	printf("Triangolo di Tartaglia fino al livello %d\n", livello);
	for (i = 0; i <= livello; i++)
	{
		unsigned int j;
		for (j = 0; j <= i; j++)
			printf("%d ", triangolo[k++]);
		printf("\n");
		
	}
	system("pause");
}


