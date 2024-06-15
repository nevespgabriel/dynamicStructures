#include<stdio.h>
#include<stdlib.h>

typedef struct no{
    int dado;
    struct no *anterior, *proximo;
}no;

no* alocaNo(int dado){
    no* novoNo = (no*)malloc(sizeof(no));
    if(novoNo == NULL){
        printf("Nao foi possivel alocar memoria.\n");
        return NULL;
    }
    novoNo->dado = dado;
    novoNo->proximo = NULL;
    novoNo->anterior = NULL;
    return novoNo;
}

void adicionaElemento(no **cabeca, int dado){
    no *novoNo = alocaNo(dado);
    if(novoNo == NULL){
        return;
    }
    if(*cabeca != NULL){
        (*cabeca)->anterior = novoNo;
    }
    novoNo->proximo = *cabeca;
    *cabeca = novoNo;
    printf("Elemento %d adicionado a lista.\n", dado);
}

void removeElemento(no **cabeca){
    if(*cabeca == NULL){
        printf("Nao foi possivel remover. A lista esta vazia.\n");
        return;
    }
    no *remover = *cabeca;
    int removido = remover->dado;
    *cabeca = remover->proximo;
    if(*cabeca != NULL){
        (*cabeca)->anterior = NULL;
    }
    free(remover);
    printf("Elemento %d removido com sucesso.\n", removido);
}

void lista(no *cabeca){
    printf("======================\n");
    printf("Elementos da lista:\n");
    while(cabeca != NULL){
        printf("%d ", cabeca->dado);
        cabeca = cabeca->proximo;
    }
    printf("\n======================\n");
}

void consultaElemento(no *cabeca, int valor){
    while(cabeca != NULL){
        if(cabeca->dado == valor){
            printf("O elemento %d esta na lista.\n", valor);
            return;
        }
        cabeca = cabeca->proximo;
    }
    printf("O elemento %d nao esta na lista.\n", valor);
}

void excluiTudo(no **cabeca){
    no *proxElemento;
    while(*cabeca != NULL){
        proxElemento = (*cabeca)->proximo;
        free(*cabeca);
        *cabeca = proxElemento;
    }
    printf("A lista inteira foi excluida.\n");
}

int main(){
    no *cabeca = NULL;
    int resp, valor;

    do{
        printf("Digite o que deseja fazer:\n[1] Adicionar elemento a lista\n");
        printf("[2] Retirar elemento da lista\n[3] Listar elementos\n");
        printf("[4] Verificar presenca de elemento\n[5] Excluir todos os elementos\n");
        printf("[6] Sair\nSua resposta = ");
        scanf("%d", &resp);
        switch(resp){
            case 1:
                printf("Digite o valor que deseja adicionar a lista:\n");
                scanf("%d", &valor);
                adicionaElemento(&cabeca, valor);
                break;
            case 2:
                removeElemento(&cabeca);
                break;
            case 3:
                lista(cabeca);
                break;
            case 4:
                printf("Digite o elemento que deseja verificar se esta na lista:\n");
                scanf("%d", &valor);
                consultaElemento(cabeca, valor);
                break;
            case 5:
                excluiTudo(&cabeca);
                break;
            case 6:
                printf("Ate mais!\n");
                break;
            default:
                printf("Opcao invalida. Digite um numero de 1 a 6\n");
        }
    }while(resp != 6);

    system("pause");
    return 0;
}
