#include<stdio.h>
#include<stdlib.h>

typedef struct no {
    int dado;
    struct no *prox;
} no;

no* alocaNo(int dado){
    no* novoNo = (no*)malloc(sizeof(no));
    if(novoNo == NULL){
        printf("Nao foi possivel alocar memoria para o no.\n");
        return NULL;
    }
    novoNo->dado = dado;
    novoNo->prox = NULL;
}

void adicionaElemento(no **cabeca, int dado){
    no* novoNo = alocaNo(dado);
    if(novoNo == NULL){
        return;
    }
    novoNo->prox = *cabeca;
    *cabeca = novoNo;
    printf("Elemento %d adicionado a lista.\n", dado);
}

void removeElemento(no **cabeca){
    if(*cabeca == NULL){
        printf("Nao e possivel remover. Lista vazia.\n");
        return;
    }
    no *remover = *cabeca;
    int removido = remover->dado;
    *cabeca = remover->prox;
    free(remover);
    printf("Elemento %d removido da lista.\n", removido);
}

void lista(no* elemento){
    if(elemento != NULL){
        printf("========================\n");
        printf("Elementos da lista:\n");
        while(elemento != NULL){
            printf("%d ", elemento->dado);
            elemento = elemento->prox;
        }
        printf("\n========================\n");
    } else{
        printf("Lista vazia.\n");
    }
}

void consultaElemento(no *lista, int num){
    while(lista!=NULL){
        if(lista->dado == num){
            printf("O elemento %d esta na lista.\n", num);
            return;
        }
        lista = lista->prox;
    }
    printf("O elemento %d nao esta na lista.\n", num);
    return;
}

void excluiTudo(no **elemento){
    no* seguinte;
    while(*elemento != NULL){
        seguinte = (*elemento)->prox;
        free(*elemento);
        *elemento = seguinte;
    }
    printf("Todos os elementos foram excluidos da lista");
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
