#include<stdio.h>
#include<stdlib.h>

typedef struct no{
    int dado;
    struct no *prox;
} no;

no* alocaNo(int dado){
    no *novoNo = (no*)malloc(sizeof(no));
    if(novoNo == NULL){
        printf("Nao foi possivel alocar no.\n");
        return NULL;
    }
    novoNo->dado = dado;
    novoNo->prox = NULL;
    return novoNo;
}

void enfileirar(int dado, no **inicio, no **fim){
    no *novoNo = alocaNo(dado);
    if(novoNo == NULL){
        return;
    }
    if(*inicio == NULL){
        *inicio = novoNo;
    } else{
        (*fim)->prox = novoNo;
    }
    *fim = novoNo;
    printf("Elemento %d enfileirado.\n", dado);
}

void desenfileirar(no **inicio, no **fim){
    if(*inicio == NULL){
        printf("Nao foi possivel desenfileirar. Fila vazia.\n");
        return;
    }
    no *remover = *inicio;
    int removido = remover->dado;
    if(*fim == remover){
        *fim = NULL;
    }
    *inicio = (*inicio)->prox;
    free(remover);
    printf("Elemento %d removido com sucesso.\n", removido);
}

int main(){
    no *inicio = NULL, *fim = NULL;
    int valor, resp;

    do{
        printf("Digite o que deseja fazer:\n[1] Enfileirar\n");
        printf("[2] Desenfileirar\n[3] Consultar inicio\n");
        printf("[4] Consultar fim\n[5] Sair\n");
        printf("Sua resposta = ");
        scanf("%d", &resp);
        switch(resp){
            case 1:
                printf("Digite o valor que deseja enfileirar:\n");
                scanf("%d", &valor);
                enfileirar(valor, &inicio, &fim);
                break;
            case 2:
                desenfileirar(&inicio, &fim);
                break;
            case 3:
                if(inicio != NULL){
                    printf("Primeiro elemento: %d\n", inicio->dado);
                }else{
                    printf("A fila esta vazia.\n");
                }
                break;
            case 4:
                if(fim != NULL){
                    printf("Ultimo elemento: %d\n", fim->dado);
                }else{
                    printf("A fila esta vazia.\n");
                }
                break;
            case 5:
                printf("Ate mais!\n");
                break;
            default:
                printf("Opcao invalida. Digite um numero de 1 a 5\n");
        }
    }while(resp != 5);

    system("pause");
    return 0;
}
