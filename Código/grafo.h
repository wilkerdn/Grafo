#include <stdio.h>
#include <stdlib.h>

typedef struct vertice{
	int num;
	struct vertice *proximo;
}Vertice;

typedef struct lista{
	Vertice *comeco;
}Lista;

void matriz_adjacente(int aux[],int x);
void matriz_incidente(int aux_v[],int aux_a[],int x,int y);
Lista* criar_lista();
int Vazia(Lista* l);
int inserir_num(Lista* l,int y,int z);
void exibir_l(Lista* l,int z);
void excluir_lista(Lista* l);	
