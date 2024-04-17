#include <stdio.h>

int main(){
    int estadoI;
    int qtdEstado;
    int qtdEstadoF;
    int estadoF[];
    int qtdAlfa;
    char alfa[10];
    int estadoA;
    char palavra[20];

// Pedindo para o usuário inserie as entradas do programa.

    printf("Estado Inicial: ");     
    scanf("%d", &estadoI);

    printf("Quantidade de Estados: ");
    scanf("%d", &qtdEstado);

    printf("Quantidade de Estados Finais: ");
    scanf("%d", &qtdEstadoF);


for(int i = 0; i < qtdEstadoF; i++) {                   // For usado para repetir quantas vezes  de estados finais o usuário inserir
        printf("Digite o %d estado final: \n", i + 1);
        scanf("%d", &estadoF[]);
    }

    printf("Quantidade simbolos no alfabrto: ");
    scanf("%d", &qtdAlfa);

for(int i = 0; i < qtdAlfa; i++) {                      // For usado para repetir quantos simbolos o usuário inserir
        printf("Digite o %d simbolo: \n", i + 1);
        scanf(" %c", &alfa[i]);
    }

   
int tabela [qtdEstado][qtdAlfa];    // Criando matriz para a tabela

    printf("Preenchja a Tabela de Transicao: \n");
  
for (int i = 0; i < qtdEstado; i++) {           //For usado para preencher a matriz
        for (int j = 0; j < qtdAlfa; j++) {
            printf("(Q%d, %c): ", i + 1, alfa[j]);
            scanf("%d", &tabela[i][j]);
        }
    }

    // Printar a tabela
    printf("Estado   ");
for (int i = 0; i < qtdAlfa; i++) {
        printf(" %c ", alfa[i]);
    }
    printf("\n");

for(int i = 0; i < qtdEstado; i++){
    printf("K%d        ", i + 1 );
        for(int j = 0; j < qtdAlfa; j++){
            printf("%d  ",tabela[i][j]);
        }
        printf("\n");
    }



    // Verificação de palavras

    estadoA = estadoI;

    for (int i = 0; palavra[i] != '\0'; i++) {
        int indice = -1;
        for (int j = 0; j < qtdAlfa; j++) {
            if (palavra[i] == alfa[j]) {
                indice = j;
                break;
            }
        }
        if (indice == -1) {
            printf("Palavra contem símbolo inválido.\n");
            return 1; // Retorna 1 para indicar erro
        }
        
        estadoA = tabela[estadoA - 1][indice];
    }

    for (int i = 0; i < qtdEstadoF; i++) {
        if (estadoA == estadoF[i]) {
            printf("Palavra aceita pelo autômato.\n");
            return 0; // Retorna 0 para indicar sucesso
        }
    }

    printf("Palavra não é aceita pelo autômato.\n");
    return 0; // Retorna 0 para indicar sucesso
}
