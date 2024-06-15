#include<stdio.h>
#include<stdlib.h>

typedef struct no{
    int dado;
    struct no *prox;
} no;

no* alocaNo(int dado){
    no* novoNo = (no*)malloc(sizeof(no));
    if(novoNo == NULL){
        printf("Erro ao alocar memoria para o no.\n");
        return NULL;
    }
    novoNo->dado = dado;
    novoNo->prox = NULL;
    return novoNo;
}

void empilhar(no **topo, int dado){
    no* novoNo = alocaNo(dado);
    if(novoNo == NULL){
        return;
    }
    novoNo->prox = *topo;
    *topo = novoNo;
    printf("Elemento %d empilhado com sucesso.\n", dado);
}

void desempilhar(no **topo){
    if(*topo == NULL){
        printf("Impossivel desempilhar. A pilha esta vazia.\n");
        return;
    }
    no *remover = *topo;
    int removido = remover->dado;
    *topo = remover->prox;
    free(remover);
    printf("Elemento %d desempilhado.", removido);
}

int main(){
    no *topo = NULL;
    int resp, valor;

    do{
        printf("Digite o que deseja fazer:\n[1] Empilhar\n[2] Desempilhar\n");
        printf("[3] Consultar topo\n[4] Sair\nSua resposta = ");
        scanf("%d", &resp);
        switch(resp){
            case 1:
                printf("Digite o valor que deseja empilhar:\n");
                scanf("%d", &valor);
                empilhar(&topo, valor);
                break;
            case 2:
                desempilhar(&topo);
                break;
            case 3:
                if(topo!=NULL){
                    printf("Topo da pilha = %d\n", topo->dado);
                } else{
                    printf("Nao ha topo. pilha vazia.\n");
                }
                break;
            case 4:
                printf("Ate mais!\n");
                break;
            default:
                printf("Opcao invalida. Digite um numero de 1 a 4\n");
        }
    }while(resp != 4);
    system("pause");
    return 0;
}
