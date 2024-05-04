#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define tamf 50

typedef struct sBarraca{
    char nome[200];
    char cpf[15];
    char situacaoAluguel;
    int tipoProduto;
} BARRACA;

typedef struct sListaBarraca{
    BARRACA barraca[tamf];
    int n;
} BARRACAS;

void inicializar_lista(BARRACAS *B){
    B -> n = -1;
}

int lista_cheia(BARRACAS *B){
    if (B -> n+1 == tamf) 
        return 1;
    return 0;
}

int lista_vazia(BARRACAS *B){
    if (B -> n == -1) 
        return 1;
    return 0;
}

void lerTipoProduto(int *tipo){
    printf("Digite o tipo de produto vendido (1: bebida, 2: lanches, 3: artigos em geral): ");
    scanf("%d", tipo);
}

void lerSituacao(char *situ){
    fflush(stdin);
    printf("Digite a situacao do alugel ('P' para pago e 'N' para nao pago): ");
    scanf("%c", situ);
}

void cadastrar_barraca(BARRACAS *B) {
    if (lista_cheia(B)){
        printf("\nErro - Lista Cheia. \n");
        return;
    }

    B->n = B-> n+1;

    fflush(stdin);
    printf("\nDigite o nome do locatario da barraca: ");
    fgets(B->barraca[B->n].nome, 200, stdin);
    B->barraca[B->n].nome[strlen(B->barraca[B->n].nome)-1] = '\0';

    fflush(stdin);
    printf("Digite o CPF do locatario da barraca (apenas numeros sem espacos): ");
    fgets(B->barraca[B->n].cpf, 200, stdin);
    B->barraca[B->n].cpf[strlen(B->barraca[B->n].cpf)-1] = '\0';

    lerTipoProduto(&(B->barraca[B->n].tipoProduto));
    lerSituacao(&(B->barraca[B->n].situacaoAluguel));
}

void mostrar_barraca(BARRACA *B, int i){
    printf("\n------------------------------------------------");
    printf("\n      Posicao:.............%d", i+1);
    printf("\n      Nome:................%s", B->nome);
    printf("\n      CPF:.................%s", B->cpf);
    
    printf("\n      Tipo de Produto:.....");
    switch (B->tipoProduto) {
        case 1:
            printf("Bebidas");
            break;
        case 2:
            printf("Lanches");
            break;
        case 3:
            printf("Artigos em geral");
            break;
    }

    printf("\n      Situacao do Aluguel:.");

    switch (B->situacaoAluguel) {
        case 'N':
            printf("Nao Pago");
            break;
        case 'P':
            printf("Pago");
            break;
    }
}

void mostrar_barracas(BARRACAS *B){
    int i;

    for (i = 0; i < B->n+1; i++)
        mostrar_barraca(&(B->barraca[i]), i);

    printf("\n------------------------------------------------\n");
}

void listar_inadimplentes(BARRACAS *B){
    int i;
    int cont = 0;

    for (i = 0; i < B->n+1; i++){
        if (B->barraca[i].situacaoAluguel == 'N'){
            mostrar_barraca(&(B->barraca[i]), i);
            cont++;
        }
    }

    if (cont == 0)
        printf("\nNao ha nenhum locatario inadimplente. \n");
    else
        printf("\n------------------------------------------------\n");
}

void listar_barracas_livres(BARRACAS *B){
    int i, livres = 0, ocupadas = 0;

    for (i = 0; i < 50; i++) {
        if (i <= B->n){
            if (ocupadas == 0)
                printf("\nBarracas Ocupadas: %d", i+1);
            else
                if (i+1 <= B->n)
                    printf(", %d", i+1);
                else
                    printf(" e %d. \n", i+1);
            
            ocupadas++;
        } else {
            if (livres == 0) 
                printf("\nBarracas Livres: %d", i+1);
            else
                if (i+1 < 50)
                    printf(", %d", i+1);
                else
                    printf(" e %d. \n", i+1);
            
            livres++;
        }
    }

    printf("\nTotal de barracas ocupadas: ");
    
    if (ocupadas != 0)
        printf("%d. ", ocupadas);
    else
        printf("\nNao ha nenhuma barraca ocupada.");

    printf("\nTotal de barracas livres: ");
    if (livres != 0)
        printf("%d.\n", livres);
    else
        printf("\nNao ha nenhuma barraca livre. \n");
        
}

int menu(){
    int opt;

    printf("\nMenu de Opcoes:\n");
    printf("1 - Cadastrar barraca.\n");
    printf("2 - Listar todos os locatarios inadimplentes. \n");
    printf("3 - Listar barras livres e ocupadas. \n");
    printf("4 - Listar todas as barracas. \n");
    printf("0 - Sair. \n");

    printf("\nInforme a opcao desejada: ");
    scanf("%d", &opt);

    return opt;
}

int main(){
    BARRACAS B;

    int opt;

    inicializar_lista(&B);

    do {
        opt = menu();

        switch (opt) {
            case 0:
                break;

            case 1:
                cadastrar_barraca(&B);
                break;

            case 2:
                if (lista_vazia(&B))
                    printf("\n2Erro - nao ha nenhuma barraca cadastrada.");
                else
                    listar_inadimplentes(&B);
                break;

            case 3:
                if (lista_vazia(&B))
                    printf("\nErro - nao ha nenhuma barraca cadastrada.");
                else
                    listar_barracas_livres(&B);
                break;

            case 4: 
                mostrar_barracas(&B);
                break;

            default:
                printf("\nErro - opcao fora dos limites. \n");
                break;
        }
    } while (opt != 0);
    
    return 0;
}
