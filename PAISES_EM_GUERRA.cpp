		
#include <cstdio>
#include <iostream>
		
using namespace std;

#define INFINITO 0x7FFFFFFF
	
#define MAXCIDADES  501
#define DESCONECTADO -1

int grafo[MAXCIDADES][MAXCIDADES];


int paisesEmGuerra (int cidadeDeOrigem, int cidadeDeDestino, int numeroDeVertices){

	int minimo, cidadeAtual;
    int custo[MAXCIDADES];
    int visitados[MAXCIDADES];
	
	// inicia o vetor de custo e visitados
    for(int i = 0; i < numeroDeVertices; i++){
        visitados[i] = false;
        custo[i] = INFINITO;
    }

    // atribui o custo zero a cidade de origem 	
     custo[cidadeDeOrigem] = 0;	
  	 cidadeAtual = cidadeDeOrigem;

	// enquanto nao chegar na cidade de destino busca o menor custo
  	 while (cidadeAtual != cidadeDeDestino){
  	 		// preenche vetor de custos
  	 		for (int i = 0; i < numeroDeVertices; i++){
  	 			if(grafo[cidadeAtual][i] != DESCONECTADO){
  	 				if ( custo[cidadeAtual] + grafo[cidadeAtual][i] < custo[i]){
  	 					custo[i] = custo[cidadeAtual] + grafo[cidadeAtual][i];
  	 				}
  	 			}
  	 		}	
  	 		
        visitados[cidadeAtual] = true;
  	 	minimo = INFINITO;

  	 		for ( int i = 0; i < numeroDeVertices; i++){
  	 			if( !visitados[i] && custo[i] < minimo ) {
	                minimo = custo[i];
	                cidadeAtual = i;
	            }
  	 		}
  	 		// se for igual a infinito nao é possivel entregar a carta
  	 		if ( minimo == INFINITO ){
         		 return INFINITO;
  	 		}		           
	}
  // se nao retorna o custo necessario pra entregar a carta
  return custo[cidadeDeDestino];

}

int main(){
		
    int cidades, acordos;
		
    while (scanf("%d  %d", &cidades, &acordos) && cidades) {
          for (int i = 0; i < cidades; i++){
            for (int j = 0; j < cidades; j++){
              grafo[i][j] = -1;
      }
          }

        for (int i = 0; i < acordos; i++){
            int origem, destino, horas;
            scanf("%d %d %d", &origem, &destino, &horas);
	
            grafo[origem-1][destino-1] = horas;
	            if (grafo[destino-1][origem-1] != -1){ // mesma cidade
	                grafo[origem-1][destino-1] = 0;
	                grafo[destino-1][origem-1] = 0;
			      }
	    }
		
        int consultas;
        
        scanf("%d", &consultas);
		
        for (int i=0; i<consultas; i++){
		
            int orig, dest;
            scanf("%d %d", &orig, &dest);
            int dist = paisesEmGuerra(orig-1, dest-1, cidades);
	
            if (dist == INFINITO)
                printf("Nao e possivel entregar a carta \n");
            else
                printf("%d\n", dist);
        }
		
        putchar('\n');
		
    }
			
   return 0;
		
}