#include <stdio.h>
#include <string>

#include "dadosCSV.h"
#include "moduloListaCompras.h"
#include "moduloSimilaridade.h"
#include "moduloBusca.h"

int main() {
    Estruturas estrutura;

    if (!carregarBaseDados("dados_venda_cluster_0.csv", estrutura)) {
        return 1;
    }

    printf("Arquivo carregado!\n");

    // ATIVIDADE 1
    for (int i = 0; i < 3; i++) {
        
        char codigoInserido[10];
    
        printf("\nDigite o codigo do cliente: ");
        scanf("%s", codigoInserido);
        
        exibirComprasDoCliente(estrutura, string(codigoInserido));
    }

    //ATIVIDADE 2
    int tamanhoMatriz;
    printf("Insira tamanho da Matriz de Similaridade ---\n");
    scanf("%d", &tamanhoMatriz);

    vector<vector<double>> matrizSimilaridade = calcularMatrizSimilaridade(estrutura);

    for (int i = 0; i < tamanhoMatriz; i++) {
        for (int j = 0; j < tamanhoMatriz; j++) {
            printf("%.2f\t", matrizSimilaridade[i][j]); 
        }
        printf("\n");
    }

    return 0;

}