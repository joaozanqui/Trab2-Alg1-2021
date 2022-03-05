#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

#define baixo 80
#define cima 72
#define esc 27
#define enter 13
#define F2 60


void gotoxy (int x, int y)
{
  COORD pos = {x, y};
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int color (char color)
{
  HANDLE h;
  h = GetStdHandle(STD_OUTPUT_HANDLE);
  return SetConsoleTextAttribute(h,color);
}

void aviso(int N, int x, int y, int cor)
{
	color(cor);
	gotoxy(x, y+2);
	printf("Para realizar novamente a mesma operacao aperte a tecla 'ENTER'");
	gotoxy(x, y+3);
	printf("Para realizar outra operacao com a mesma matriz utilize as setas para 'Baixo' ou para 'Cima'");
	gotoxy(x, y+4);
	printf("Para ler outra matriz aperte a tecla 'F2'");
	gotoxy(x, y+5);
	printf("Para finalizar o programa aperte a tecla 'ESC'");
}

void lermatriz(int N, float v[N][N]) 
{
	int i, j;	
	
	for(i=0; i<N; i++)
	{
		for(j=0; j<N; j++)
		{
			gotoxy(10, 5);
			printf("Elemento da posicao %dx%d da Matriz de dimensao %dx%d ->> ", i+1, j+1, N, N);
			scanf("%f", &v[i][j]);
			system("cls");
		}
	}
}

void mostrarmatriz(int N, float v[N][N])
{
	int i, j;

	for(i=0; i<N; i++)
	{
		for(j=0; j<N; j++)
		{
			gotoxy(5+7*j, i+1);
			printf("%.1f ", v[i][j]);
		}
	}	
}

void texto(int x, int y, char texto[], int cor)
{
	color(cor);
	gotoxy(y,x);
	printf("%s", texto);
}

void opcao(int x, int y, int n, int cor)
{
	color(cor);
	gotoxy(y,x);
	printf("%d", n);
}

void menu(int N, int opc)
{
	int i;
	char x[9][70] = {"Troque os elementos da linha X pela linha Y", "Troque os elementos da coluna X pela coluna Y", "Troque os elementos da diagonal principal com a diagonal secundaria", "Verifique se uma matriz eh simetrica", "Verifique se uma matriz eh um quadrado magico", "Verifique se uma matriz eh quadrado latino", "Verifique se uma matriz eh matriz de permutacao", "Para ler outra matriz aperte a tecla 'F2'", "Para finalizar o programa aperte a tecla 'ESC'"};
		
	for(i=0; i<9; i++)
	{
		if(i>=7)
			texto(N+2+i+1, 1, x[i], 4);
		else
			texto(N+2+i, 1, x[i], 15);
	}
	texto(N+1+opc, 1, x[opc-1], 11);
}

void lxy(int N, float v[N][N])
{
	int i, opc=1, x=0, y=0;
	float aux;
	char t;
		
	system("cls");
	color(15);
	mostrarmatriz(N, v);
	gotoxy(1, N+2);
	printf("Escolha as linhas que serao trocadas");
		
	for(i=0; i<N; i++)
		opcao(N+3+i, 20, i+1, 15);
	opcao(N+2+opc, 20, opc, 11);
	
	do{
		t=getch();
		if(t<=0)
		{
			t=getch();
			if(t==baixo)
			{
				opc++;
		    	if(opc>N)
		    		opc=1;
				
				for(i=0; i<N; i++)
					opcao(N+3+i, 20, i+1, 15);
				opcao(N+2+opc, 20, opc, 11);
			}
		else if(t==cima) 
			{
		  		opc--;
		  		if(opc<1)
		  			opc=N;
		  			
		  		for(i=0; i<N; i++)
					opcao(N+3+i, 20, i+1, 15);
				opcao(N+2+opc, 20, opc, 11);
		  	}	
			
		}
		
		else if(t==enter)
			if(x==0)
				x=opc;
			else
				y=opc;
	}while(y==0);
	
	system("cls");
	color(15);
	
	if(x>y)
	{
		aux=x; x=y; y=aux;
	}
	
	for(i=0; i<N; i++)
	{
		aux=v[x-1][i];
		v[x-1][i]=v[y-1][i];
		v[y-1][i]=aux;
	}
	
	mostrarmatriz(N, v);
	aviso(N, 1, N+2, 4);
}

void cxy(int N, float v[N][N])
{
	int i, opc=1, x=0, y=0;
	float aux;
	char t;
		
	system("cls");
	color(15);
	mostrarmatriz(N, v);
	gotoxy(1, N+2);
	printf("Escolha as colunas que serao trocadas");
	
	for(i=0; i<N; i++)
		opcao(N+3+i, 20, i+1, 15);
	opcao(N+2+opc, 20, opc, 11);
	
	do{
		t=getch();
		if(t<=0)
		{
			t=getch();
			if(t==baixo)
			{
				opc++;
		    	if(opc>N)
		    		opc=1;
				
				for(i=0; i<N; i++)
					opcao(N+3+i, 20, i+1, 15);
				opcao(N+2+opc, 20, opc, 11);
			}
		else if(t==cima) 
			{
		  		opc--;
		  		if(opc<1)
		  			opc=N;
		  			
		  		for(i=0; i<N; i++)
					opcao(N+3+i, 20, i+1, 15);
				opcao(N+2+opc, 20, opc, 11);
		  	}	
			
		}
		
		else if(t==enter)
			if(x==0)
				x=opc;
			else
				y=opc;
	}while(y==0);
	
	system("cls");
	color(15);
	
	if(x>y)
	{
		aux=x; x=y; y=aux;
	}
	
	for(i=0; i<N; i++)
	{
		aux=v[i][x-1];
		v[i][x-1]=v[i][y-1];
		v[i][y-1]=aux;
	}
	
	mostrarmatriz(N, v);
	aviso(N, 1, N+2, 4);
}

void diag(int N, float v[N][N])
{
	int i, j;
	float aux;
	
	for(i=0; i<N; i++)
	{
		for(j=0; j<N; j++)
		{
			if(i==j)
			{
				aux=v[i][j];
				v[i][j]=v[i][N-i-1];
				v[i][N-i-1]=aux;
			}
		}
	}
	
	system("cls");
	color(15);
	mostrarmatriz(N, v);
	aviso(N, 1, N+2, 4);
}

int sim(int N, float v[N][N])
{
	int i, j;
	
	for(i=0; i<N; i++)
		for(j=0; j<N; j++)
			if(v[i][j]!=v[j][i])
				return 0;
	
	return 1;
}

int qmagic(int N, float v[N][N])
{
	int i, j, teste, soma[N+N+2];
	
	for(i=0; i<N+N+2; i++)
		soma[i]=0;
		
	
	for(i=0; i<N; i++)
	{
		for(j=0; j<N; j++)
		{
			soma[i]+=v[i][j];	
		}
	}
	
	for(j=0; j<N; j++)
	{
		for(i=0; i<N; i++)
		{
			soma[j+N]+=v[i][j];
		}		
	}
	
	for(i=0; i<N; i++)
		for(j=0; j<N; j++)
			if(i==j)
				soma[N+N]+=v[i][j];
				
	for(i=0; i<N; i++)
		for(j=0; j<N; j++)
			if(i+j==N-1)
				soma[N+N+1]+=v[i][j];

	for(i=1; i<N+N+2; i++)
	{
		if(soma[i]==soma[i-1])
			teste=soma[i];
		else
		{
			teste=0;
			break;
		}
	}
	
	return teste;	
}

int qlat(int N, float v[N][N])
{
	int i, j, k;
	
	for(i=0; i<N; i++)
		for(j=0; j<N-1; j++)
			for(k=j+1; k<N; k++)
				if(v[i][k]==v[i][j])
					return 0;
					
	for(j=0; j<N; j++)
		for(i=0; i<N-1; i++)
			for(k=i+1; k<N; k++)
				if(v[k][j]==v[i][j])
					return 0;

	for(i=0; i<N; i++)
		for(j=0; j<N; j++)
			if(v[i][j]>N || v[i][j]<1)
				return 0;
				
	return 1;	
}

int perm(int N, float v[N][N])
{
	int i, j, k;
	
	for(i=0; i<N; i++)
		for(j=0; j<N; j++)
			if(v[i][j]!=0 && v[i][j]!=1)
				return 0;
	
	for(i=0; i<N; i++)
	{
		k=0;
		for(j=0; j<N; j++)
		{
			if(v[i][j]==1)
				k++;	
		}
		if(k!=1)
			return 0;
	}
	
	for(j=0; j<N; j++)
	{
		k=0;
		for(i=0; i<N; i++)
		{
			if(v[i][j]==1)
				k++;	
		}
		if(k!=1)
			return 0;
	}
	
	return 1;
}

int main()
{
	int opc=1, N;
	char t;
	
	do{		
		color(15);
		system("cls");
		printf("Digite a Ordem da matriz: ");
		scanf("%d", &N);
			if(N==1)
		do{
			color(4);
			printf("Digite um valor maior que 1: ");
			color(15);
			scanf("%d", &N);
			system("cls");
		}while(N==1);
		
		
		float v[N][N];
	
		lermatriz(N, v);	
		mostrarmatriz(N, v);
		menu(N, opc);
		
	    do{	
			t=getch();
			if(t<=0) 
			{
				t=getch();
				if (t==baixo)
				{
			    	opc++;
			    	if(opc>7)
			    		opc=1;
					
					system("cls");
					color(15);
					mostrarmatriz(N, v);				
					menu(N, opc);
			 	}
			  	
				else if(t==cima) 
				{
			  		opc--;
			  		if(opc<1)
			  			opc=7;
			  			
			  		system("cls");
					color(15);
					mostrarmatriz(N, v);	
					menu(N, opc);
			  	}
		    }
		    
		    else if(t==enter)
		    {
		    	switch(opc)
		    	{
		    		case 1: lxy(N, v);
		    				break;
		    		case 2: cxy(N, v);
		    				break;
		    		case 3: diag(N, v);
		    				break;
		    		case 4: if(sim(N, v)==1)
		    				{
		    					system("cls");
								color(15);
								mostrarmatriz(N, v);
								gotoxy(3, N+4);
		    					printf("A Matriz eh simetrica");
		    					aviso(N, 1, N+6, 4);
							}
		    				else
		    				{
		    					system("cls");
								color(15);
								mostrarmatriz(N, v);
								gotoxy(3, N+4);
		    					printf("A Matriz nao eh simetrica");
		    					aviso(N, 1, N+6, 4);
							}
		    				break;
		    		case 5: if(qmagic(N, v)==0)
		    				{
		    					system("cls");
								color(15);
								mostrarmatriz(N, v);
								gotoxy(3, N+4);
		    					printf("A Matriz nao eh um quadrado magico");
		    					aviso(N, 1, N+6, 4);
							}
							
							else
							{
								system("cls");
								color(15);
								mostrarmatriz(N, v);
								gotoxy(3, N+4);
		    					printf("A Matriz eh um quadrado magico de soma %d", qmagic(N, v));
		    					aviso(N, 1, N+6, 4);
							}
							break;
		    		case 6: if(qlat(N, v)==0)
		    				{
		    					system("cls");
								color(15);
								mostrarmatriz(N, v);
								gotoxy(3, N+4);
		    					printf("A Matriz nao eh um quadrado latino");
		    					aviso(N, 1, N+6, 4);
							}
							
							else
							{
								system("cls");
								color(15);
								mostrarmatriz(N, v);
								gotoxy(3, N+4);
		    					printf("A Matriz eh um quadrado latino de ordem %d", N);
		    					aviso(N, 1, N+6, 4);
							}
							break;
					case 7: if(perm(N, v)==0)
		    				{
		    					system("cls");
								color(15);
								mostrarmatriz(N, v);
								gotoxy(3, N+4);
		    					printf("A Matriz nao eh uma matriz de permutacao");
		    					aviso(N, 1, N+6, 4);
							}
							
							else
							{
								system("cls");
								color(15);
								mostrarmatriz(N, v);
								gotoxy(3, N+4);
		    					printf("A Matriz eh uma matriz de permutacao");
		    					aviso(N, 1, N+6, 4);
							}
							break;					    		
				}
			}
				
			else if(t==F2 || t==esc)
				break;
				
		}while(t!=F2);
		
		if(t==esc)
		{
			system("cls");
			break;
		}
	}while(t!=esc);
		
	return 0;	
}
