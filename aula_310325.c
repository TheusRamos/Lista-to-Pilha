#include <locale.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct ElementoLista
{
    int value;
    struct ElementoLista *prox;
    struct ElementoLista *ant;
} Item;

void imprime(Item *top)
{
    Item *atual = top->prox;
    Item *ant = NULL;
    int i = 0;
    while(atual!=NULL)
    {
        printf("[%d] Posicao do item: %d - valor do item: %d - Valor anterior %d\n",i+1,atual, atual->value, ant);
        i++;
        ant = atual;
        atual = atual->prox;
    }
    printf("\nTotal de itens na lista: %d\n", i);
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
void InsereFim(Item *top, int value)
{
    Item *novo = (Item*)malloc(sizeof(Item));
    novo->prox = NULL;
    novo->value = value;
    printf("Item de value %d alocado no espaço de memória %d\n", novo->value, novo);
    Item *atual = top;
    Item *ant = NULL;
    while(atual->prox!=NULL)
    {
        ant = atual->prox;
        atual = atual->prox;
    }
    atual->prox = novo;

}
void InsereInicio( Item *top, int valor)
{
    Item *novo = (Item *)malloc(sizeof(Item));

    if (novo == NULL)
    {
        printf("Erro ao alocar memória!\n");
        return;
    }

    novo->value = valor;
    novo->prox = top->prox;
    top->prox = novo;

    printf("O valor %d foi adicionado ao início da fila!\n", valor);
    return;
}
void RetirarFim(Item *top)
{
    Item *atual = top;
    Item *ant = NULL;
    while (atual->prox != NULL)
    {
        ant = atual;
        atual = atual->prox;
    }
    printf("Retirando item %d na posição de memória %p\n", atual->value, (void*)atual);
    free(atual);

    if (ant != NULL)
    {
        ant->prox = NULL;
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

    printf("Endereço da memória, %p", (void*)atual);
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
    top.ant = NULL;
    int opc, valor;
    int fim = 0;

    while(fim != 1)
    {
        system("cls");
        printf("Bem vindo ao menu da Lista!\n\n");
        printf("Escolha uma opção:\n\n[1]Adicionar item ao final da fila\n[2]Retirar item ao final da fila\n[3]Adicionar item no inicio da fila\n[4]Retirar item no inicio da fila\n[5]Mostrar fila\n[6]Sair");
        printf("\n\nDigite aqui: ");
        scanf("%d", &opc);

        switch (opc)
        {
        case 1:
            system("cls");
            printf("MENU PARA ADIÇÃO DE ITEM AO FIM DA FILA...\n\n");
            printf("Digite o valor que deseja adicionar: ");
            scanf("%d", &valor);
            InsereFim(&top, valor);
            printf("Segue nova fila:\n");
            imprime(&top);
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
            printf("MENU PARA ADIÇÃO DE ITEM AO INICIO DA FILA...\n\n");
            printf("Digite o valor que deseja inserir: ");
            scanf("%d", &valor);
            InsereInicio(&top, valor);
            printf("\nSegue nova fila:\n");
            imprime(&top);
            system("pause");
            break;
        case 4:
            system("cls");

            printf("Retirando item no incio da fila...");
            RetirarInicio(&top);
            system("pause");
            printf("Segue nova fila:\n");
            imprime(&top);
            system("pause");
            break;
        case 5:
            printf("SEGUE OS ITENS EM FILA:\n\n");
            imprime(&top);
            system("pause");
            break;
        case 6:
            system("cls");
            printf("Saindo...");
            fim++;
            break;

        default:
            printf("Alternativa inválida, digite novamente!\n");
            fflush(stdin);
            system("Pause");
            break;
        }
    }
    libera(&top);
    return 0;
}
