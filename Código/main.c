#include "grafo.h"

int main(){
	int numv=0,i=0,numa=0,opcao=0,repeat=1,p=0,j=0,controle=0,repeat2=1;

	printf("Digite a quantidade de vertices do grafo:\n");
	scanf("%d",&numv);
	int vertices[numv];
	printf("Digite os vertices do grafo:\n");
	for(i=0;i<numv;i++){
		scanf("%d",&vertices[i]);
	}

	printf("Digite a quantidade de arestas do grafo:\n");
	scanf("%d",&numa);
	int arestas[numa];
	printf("Digite as arestas do grafo:\n");
	for(i=0;i<numa;i++){
		scanf("%d",&arestas[i]);
	}

	Lista* vertices_l[numv];
	int posicao[numv];

	while(repeat==1){

		printf("\nCriar matriz adjacente = 1\n");
		printf("Criar matriz incidente = 2\n");
		printf("Criar lista = 3\n");
		printf("Imprimir lista = 4\n");
		printf("Encerrar programa = 5\n");
		printf("Opcao = ");
		scanf("%d",&opcao);

		if(opcao==1){
			matriz_adjacente(vertices,numv);
			repeat = 1;
		}else if(opcao==2){
			matriz_incidente(vertices,arestas,numv,numa);
			repeat = 1;
		}else if(opcao==3){
			printf("\n");
			for(i=0;i<numv;i++){
				vertices_l[i] = criar_lista();
				posicao[i] = 0;
			}
			for(i=0;i<numv;i++){
			printf("Insira os vertices que tem relacao com o vertice %d\n",vertices[i]);
			printf("Para parar de inserir = -10\n");
			while(repeat2==1){
				scanf("%d",&p);
				if(p==-10){
				break;
				}else{
				inserir_num(vertices_l[i],p,posicao[i]);
				posicao[i]++;
				repeat2=1;
				}
			}
			}
			controle = 1;
			repeat = 1;
		}else if(opcao==4){
			for(i=0;i<numv;i++){
				printf("\n%d-> ",vertices[i]);
				exibir_l(vertices_l[i],posicao[i]);
			}
			printf("\n");        
			repeat = 1;
		}else if(opcao==5){
			if(controle==1){
			printf("blz\n");
				for(j=0;j<numv;j++){
					excluir_lista(vertices_l[j]);
				}
			}
			repeat = 0;
			break;
		}else{
			printf("Opcao invalida, digite novamente\n");
			repeat = 1;
		}
	}
	printf("Grafo deletado\n");
	return 0;
}
