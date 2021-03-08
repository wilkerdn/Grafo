#include "grafo.h"

void matriz_adjacente(int aux[],int x){
	int m_adj[x][x],i=0,j=0,aux2;

	printf("\nSe as arestas possuirem relacao = 1\nSe as arestas nao possuirem relacao = 0\n");

	for(i=0;i<x;i++){
		for(j=0;j<x;j++){
		printf("[%d][%d] = ",aux[i],aux[j]);
		scanf("%d",&aux2);
		m_adj[i][j] = aux2;
		}
	}

	printf("\nMATRIZ ADJACENTE\n");
	printf("  ");
	for(i=0;i<x;i++){
		printf("%d ",aux[i]);
	}
	printf("\n");

	for(i=0;i<x;i++){
		printf("%d ",aux[i]);
		for(j=0;j<x;j++){
		printf("%d ",m_adj[i][j]);
		}
		printf("\n");
	}
}

void matriz_incidente(int aux_v[],int aux_a[],int x,int y){
	int m_inc[x][y],i=0,j=0,aux2;

	printf("\nSe os vertices possuirem possuirem relacao com as arestas = 1\n");
	printf("Se os vertices nao possuirem relacao com as arestas = 0\n");

	for(i=0;i<x;i++){
		for(j=0;j<y;j++){
		printf("[%d][%d] = ",aux_v[i],aux_a[j]);
		scanf("%d",&aux2);
		m_inc[i][j] = aux2;
		}
	}

	printf("\nMATRIZ INCIDENTE\n");
	printf("  ");
	for(i=0;i<y;i++){
		printf("%d ",aux_a[i]);
	}
	printf("\n");

	for(i=0;i<x;i++){
		printf("%d ",aux_v[i]);
		for(j=0;j<y;j++){
		printf("%d ",m_inc[i][j]);
		}
		printf("\n");
	}
}

Lista *criar_lista(){
	Lista* l;
	l = malloc(sizeof(Lista));
	l->comeco = NULL;
	return l;
}

int Vazia(Lista* l){
	if(l->comeco==NULL){
		return 1;
	}else
		return 0;
}

int inserir_num(Lista* l,int y,int z){
	Vertice *novo = malloc(sizeof(Vertice));
	Vertice *temp;
	int i;
	novo->num = y;
	if(Vazia(l)==1){
		novo->proximo = l->comeco;
		l->comeco = novo;
	}else if(Vazia(l)!=1){
		temp = l->comeco;
		for(i=1;i<z;i++){
			if(temp->proximo==NULL){
				break;
			}else
				temp = temp->proximo;
		}
	}
	novo->proximo = temp->proximo;
	temp->proximo = novo;
	return 1;
}

void exibir_l(Lista *l,int z){
	int i=0;
	Vertice *temp;
	if(l->comeco!=NULL){
	temp=l->comeco;
	printf("%d ",temp->num);
		for(i=1;i<z;i++){
			if(temp->proximo==NULL){
			break;
			}
			temp=temp->proximo;
			printf("%d ",temp->num);
		}
	}
}

void excluir_lista(Lista *l){
	Vertice *temp=l->comeco;
	Vertice *aux;

	if(temp!=NULL){
		while(temp!=NULL){
		aux = temp;
		temp = temp->proximo;
		free(aux);
		}
	}
	l->comeco = NULL;
}
