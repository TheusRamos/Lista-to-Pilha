#include <locale.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct ElementoLista
{
    int value;
    struct ElementoLista *prox;
} Item;

void imprime(Item *top)
{
    Item *atual = top->prox;
    int i = 0;
    while(atual!=NULL)
    {
        printf("[%d] Posicao do item: %d - valor do item: %d\n",i+1,atual, atual->value);
        i++;
        atual = atual->prox;
    }
    printf("\nTotal de itens na lista: %d\n", i);
}

void InsereFim(Item *top, int value)
{
    Item *novo = (Item*)malloc(sizeof(Item));
    novo->prox = NULL;
    novo->value = value;
    printf("Item de value %d alocado no espaço de memória %d\n", novo->value, novo);
    Item *atual = top;
    while(atual->prox!=NULL)
    {
        atual = atual->prox;
    }
    atual->prox = novo;
}

void libera(Item *top)
{
    Item *atual = top->prox;
    Item *liberado;
    while(atual->prox != NULL)
    {
        liberado = atual;
        atual = atual->prox;
        printf("Liberando item de value %d na posição de memória: %d\n", liberado->value, liberado);
        free(liberado);
    }
}

void RetirarFim(Item *top)
{
    Item *atual = top;
    Item *anterior = NULL;
    while (atual->prox != NULL)
    {
        anterior = atual;
        atual = atual->prox;
    }
    printf("Retirando item %d na posição de memória %p\n", atual->value, (void*)atual);
    free(atual);

    if (anterior != NULL)
    {
        anterior->prox = NULL;
    }
    else
    {
        top->prox = NULL;
    }
}

void RetirarInicio(Item *top)
{
    Item *atual = top->prox;
    Item *proximo = NULL;
    if(top->prox == NULL)
    {
        printf("Fila vazia..\n");
        return;
    }
    if(atual->prox != NULL)
    {
        top->prox = atual->prox;
        free(atual);
        return;
    }
    if(atual->prox == NULL && top->prox != NULL)
    {
        top->prox = NULL;
    }
    return;
}


int main()
{
    setlocale(LC_ALL,"portuguese");
    Item top;
    top.prox = NULL;
    int opc, valor;
    int fim = 0;

    while(fim != 1)
    {
        system("cls");
        printf("Bem vindo ao menu da Lista!\n\n");
        printf("Escolha uma opção:\n\n[1]Adicionar item ao final da fila\n[2]Retirar item ao final da fila\n[3]Retirar item no inicio da fila\n[4]Mostrar fila\n[5]Sair do programa\n");
        printf("\nDigite aqui: ");
        scanf("%d", &opc);

        switch (opc)
        {
        case 1:
            system("cls");
            printf("MENU PARA ADIÇÃO DE ITEM AO FIM DA FILA...\n");
            printf("Digite o valor que deseja adicionar: ");
            scanf("%d", &valor);
            InsereFim(&top, valor);
            system("pause");
            break;
        case 2:
            system("cls");
            printf("Retirando item ao fim da fila...");
            RetirarFim(&top);
            system("pause");
            printf("Segue nova fila:\n");
            imprime(&top);
            system("pause");
            break;
        case 3:
            system("cls");
            printf("Retirando item no incio da fila...");
            RetirarInicio(&top);
            system("pause");
            printf("Segue nova fila:\n");
            imprime(&top);
            system("pause");
            break;
        case 4:
            printf("Esses são os itens da fila:\n\n");
            imprime(&top);
            system("pause");
            break;
        case 5:
            system("cls");
            printf("Saindo...");
            fim++;
        default:
            printf("Alternativa inválida, digite novamente!\n");
            break;
        }
    }
    libera(&top);
    return 0;
}
