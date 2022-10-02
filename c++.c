#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <time.h>
#define lotacao 25


typedef struct card{
	int   num;
	char  nome [100];
	char  mora [100];
	float sal;
	float totalga;
	int   entreda=0;
	int   nentre=0;
	float nent;
	float val=0;
}CARD;




float  dados(card cards[],int total){
	

	
	printf("\n|qual o seu numero: ");
	scanf("%i",&cards[total].num);
	
	printf("\n|qual o seu nome: ");
	fflush(stdin);
	gets(cards[total].nome);
	
	printf("\n|qual a sua morada: ");
	fflush(stdin);
	gets(cards[total].mora);
	
	printf("\n|quanto dinheiro pretende inserir: ");
	scanf("%f",&cards[total].sal);
	
	
}

int Listar(card cards[],int total){
	int q=1;
	
	for(q=1;q<total;q++){
		printf("\n        _______________________________");
		printf("\n        |          cliente Nº%i",q);
		printf("\n        |          numero=%i",cards[q].num);
		printf("\n  	|          nome=%s",cards[q].nome);
		printf("\n  	|          morada=%s",cards[q].mora);
		printf("\n   	|          saldo=%.2f",cards[q].sal);
		printf("\n        |_____________________________\n");
	}
	
}

int umcli(card cards[],int total){
	int q=1,c;
	
	printf("\n|qual o numero do cliente: ");
	scanf("%i",&c);
	
	for(q=1;q<total;q++){
		if(cards[q].num==c){
			printf("\n  ______________");
			printf("\n  |cliente Nº%i",q);
			printf("\n  |numero=%i", cards[q].num);
			printf("\n  |nome=%s",   cards[q].nome);
			printf("\n  |morada=%s", cards[q].mora);
			printf("\n  |saldo=%.2f",cards[q].sal);	
			printf("\n  |____________\n");
		}
	}
}

float saldo(card cards[],int total){
	int q=1,c;
	float s;
	
	printf("\n|qual o numero do cliente:  ");
	scanf("%i",&c);
	printf("\n|qual a quantia que deseja carregar?:  ");
	scanf("%f",&s);
	
	for(q=1;q<total;q++){
		if(cards[q].num==c){
			cards[q].sal+=s;
		}
		else{
			printf("\n|esse utilizador nao existe|");
		}
	}
	
}

int entrada(card cards[],int total,char *datahora){
	int q=1,entradas,l,c,exi=0;
	
	printf("\n|qual o numero do cliente: ");
	scanf("%i",&c);
	
	for(q=1;q<total;q++){
		if(cards[q].num==c){
			exi=1;
			if(cards[q].entreda==0){
					if (cards[q].sal>0){
						
						cards[q].entreda+=1;
						cards[q].nentre=cards[q].nentre+1;
						printf( "entrou Data/Hora: %s\n", datahora );
						
						printf("\n|entrada registrada|\n");
					}
					else{
						printf("\n|saldo insuficiente|\n");
					}
			}
			else {
			 	printf("\n|impossivel de entrar duas vezes|\n");	
			}
		}
	
	}
	if(exi==0){
		printf("esse utilizador nao existe");
		
	}
	return entradas;
	
}

int Datahora_minutos(char *datahora){
	int hora, min;
	
	strtok(datahora," ");
	strtok(NULL," ");
	hora=atoi(strtok(NULL,":"));
	min=atoi(strtok(NULL,":"));
	
	
	return (hora*60+min)/30,min ;					
}

float saida (card cards[],int total,char *d,char *datahora){
	int q=1,c=0,h,exi;
	float t,p;
	printf("\n|qual o numero do cliente: ");
	scanf("%i",&c);
		for(q=1;q<total;q++){
		if(cards[q].num==c){
		exi=1;
			if(cards[q].entreda==1){
				cards[q].entreda-=1;
				printf("\n____________________________________");
				printf("\n|carro registrado------------------|\n");
				printf( "|Data/Hora: %s|\n", d );
				h=Datahora_minutos(d)-Datahora_minutos(datahora);
				cards[q].nent+=h;
				printf("|tempo gasto-----=%.2f-------------|",h);
				if(h%30!=0){
					p=(h*0.20)+0.20;
				}
				else{
					p=(h*0.20);	
				}
				if(h==0){
					p=0.20;
				}
				cards[q].sal-=p;
				printf("\n|valor cobrado---=%.2f-------------|",p);
				printf("\n|novo saldo------=%.2f------------|",cards[q].sal);
				printf("\n|__________________________________|\n");
				cards[q].val+=p;
				
			}
			else{
			 	printf("\n|o carro ja saiu|\n");	
			}
		}
		if(exi==0){
		printf("esse utilizador nao existe");
		
		}
	}
	return h;
}

int totals (card cards[],int total){
	int c,q=1;
	
	printf("\n|qual o numero do cliente=´: ");
	scanf("%i",&c);
		for(q=1;q<total;q++){
		if(cards[q].num==c){
			printf("\n|total gasto=%.2f-----|",cards[q].val);
			printf("\n|Nº de entradas=%i|",cards[q].nentre);
		}
	}
}
int maior(card cards[],int total){
	int q=1;
	float maior=1;
	
	for(q=1;q<total;q++){
		if(cards[q].nentre>maior){
			maior=cards[q].nentre;
		}
	}
	for(q=1;q<total;q++){
		if(cards[q].nentre==maior){
			printf("\n|carro com maior numero de acessos=%i|",cards[q].num);
			printf("\n|maior numero de acessos=%i|",cards[q].nentre);
		}
	}	
}
int maiort(card cards[],int total,char *d,char *datahora){
	int q=1;
	float maior=0,t;
	t=saida(cards,total,d,datahora);
	
	for(q=1;q<total;q++){
		if(cards[q].nent>maior){
			maior=cards[q].nent;
		}
	}
	for(q=1;q<total;q++){
		if(cards[q].nent==maior){
			printf("\ncarro com maior tempo gasto=%i",cards[q].num);
			printf("\ntempo gastos=%i",cards[q].nent);
		}
	}	
}

int media(card cards[],int total){
    int q=1;
    float somatorio=0;
    for(q=1;q<total;q++){
        somatorio+=cards[q].val;
 	}
    printf("Media=total paga / numero de entradas");
    printf(" =%.2f",somatorio/(total-1));
}

int main (){
	setlocale(LC_ALL,"portuguese");
	card cards[lotacao];
	
	int q,total=1,entradas=0,tempo=0,c;

	char menu,menu2,menu3;

	
	while(1){
				time_t said;
			    time_t agora;
			    said=time(NULL);
			    agora = time(NULL);
			    char datahora[100];
			    char d[100];
			    strftime( datahora, sizeof(datahora), "%d.%m.%Y - %H:%M:%S", localtime( &agora ) );
			    strftime( d, sizeof(d), "%d.%m.%Y - %H:%M:%S", localtime( &said ) );
					
		
		
		
				printf("\n        _________________________________________________\n");
				printf("        |---------------intruduza a opçao:--------------|\n");
			    printf("        |-----------------------------------------------|\n");	
				printf("        |-----------1-gestor de clientes:---------------|\n");
				printf("        |-----------2-gestor de entradas e saidas:------|\n");
				printf("        |-----------------------------------------------|\n");
				printf("        |--------------------0-sair:--------------------|\n");
				printf("        |_______________________________________________|\n");
				scanf(" %c",&menu);
				system("cls");
		
		switch(menu){
			case '0':
				return 0;
			break;
			case '1':
				printf("\n        _______________________________________________________\n");
				printf("        |---------------intruduza a opçao:--------------------|\n");
	   			printf("        |-----------------------------------------------------|\n");
				printf("        |-----------1-novo cliente:---------------------------|\n");
				printf("        |-----------2-Listar clientes:------------------------|\n");
				printf("        |-----------3-Visualizar informação de um cliente:----|\n");
				printf("        |-----------4-carregar saldo--------------------------|\n");
			    printf("        |-----------5-maior numero de acessos-----------------|\n");
			    printf("        |-----------6-media do total gasto--------------------|\n");
				printf("        |-----------------------------------------------------|\n");
				printf("        |--------------------0-sair:--------------------------|\n");
				printf("        |_____________________________________________________|\n");
				scanf(" %c",&menu2);
				system("cls");
				
				switch(menu2){
					case '1':
					dados(cards,total);
					total++;
					break;
					case '2':
					Listar(cards,total);
					break;
					case '3':
					umcli(cards,total);
					break;
					case '4':
						saldo(cards,total);
					break;
					case '5':
						maior(cards,total);
					break;
					case '6':
						media(cards, total);
					break;
					case '7':
						maiort(cards,total,d,datahora);
					break;
					case '0':
						return 0;
					break;
				}
			break;	
			case '2':	
				printf("\n        _________________________________________________________\n");
				printf("        |---------------intruduza a opçao:----------------------|\n");
	    		printf("        |-------------------------------------------------------|\n");
				printf("        |------------1-Registar uma entrada no parque:----------|\n");
				printf("        |------------2-Registar a saída do parque:--------------|\n");
				printf("        |------------3-quantidade de acessos e total gasto:-----|\n");
				printf("        |-------------------------------------------------------|\n");
				printf("        |--------------------0-sair:----------------------------|\n");
				printf("        |_______________________________________________________|\n");
				scanf(" %c",&menu3);
				system("cls");
				switch(menu3){	
					case '1':
						entradas=entrada(cards,total,datahora);
					break;
					case '2':
						saida(cards,total,d,datahora);
					break;
					case '3':
						totals(cards,total);
					break;
					case '0':
						return 0;
					break;
						}
			break;	
		}
	}

}
