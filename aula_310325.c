#include <locale.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct ElementoLista{
    int value;
    struct ElementoLista *prox;
} Item;

void imprime(Item *top){
    Item *atual = top->prox;
    int i = 0;
    while(atual!=NULL){
        printf("Posicao do item: %d - valor do item: %d\n",atual , atual->value);
        i++;
        atual = atual->prox;
    }
    printf("\nTotal de itens na lista: %d\n", i);
}

void InsereFim(Item *top, int value){
    Item *novo = (Item*)malloc(sizeof(Item));
    novo->prox = NULL;
    novo->value = value;
    printf("Item de value %d alocado no espaço de memória %d\n", novo->value, novo);
    Item *atual = top;
    while(atual->prox!=NULL){
        atual = atual->prox;
    }
    atual->prox = novo;
}

void libera(Item *top){
    Item *atual = top->prox;
    Item *liberado;
    while(atual->prox != NULL){
        liberado = atual;
        atual = atual->prox;
        printf("Liberando item de value %d na posição de memória: %d\n", liberado->value, liberado);
        free(liberado);
    }
}

void RetirarFim(Item *top){

    Item *atual = top;
    Item *anterior = NULL;
    while (atual->prox != NULL) {
        anterior = atual;
        atual = atual->prox;
    }
    printf("Retirando item %d na posição de memória %p\n", atual->value, (void*)atual);
    free(atual);

    if (anterior != NULL) {
        anterior->prox = NULL;
    } else {
        top->prox = NULL;
    }
}


int main(){
    setlocale(LC_ALL ,"portuguese");
    Item top;
    top.prox = NULL;

    InsereFim(&top, 125);
    InsereFim(&top, 189);
    imprime(&top);

    system("pause");
    RetirarFim(&top);
    system("pause");
    imprime(&top);
    RetirarFim(&top);
    imprime(&top);

    libera(&top);


    return 0;
}
