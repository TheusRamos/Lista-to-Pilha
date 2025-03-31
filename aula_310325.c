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
        printf("value do item: %d\n", atual->value);
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
    Item *atual = top->prox;
    Item *retirar;
    while(atual != NULL){
        
        retirar = atual;
        atual = atual->prox;
       
    }
    printf("Retirando item %d na posição de memoria %d\n", retirar->value, retirar);
    retirar = NULL;
    free(atual);
    
}

int main(){
    setlocale(LC_ALL ,"portuguese");
    Item top;
    top.prox = NULL;
    printf("Tamanho do item: %d\n", sizeof(Item));
    printf("Chegou aqui");
    InsereFim(&top, 125);
    imprime(&top);


    system("pause");
    InsereFim(&top, 189);
    imprime(&top);

    system("pause");
    RetirarFim(&top);
    system("pause");
    imprime(&top);
    system("pause");
    
    system("pause");
    libera(&top);


    return 0;
}