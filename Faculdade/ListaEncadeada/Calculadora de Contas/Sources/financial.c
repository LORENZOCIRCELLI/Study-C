#include "../Headers/financial.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Node* inicializar_lista() {
    return NULL;
}

Node* criar_conta(Node* node, Conta conta) {
/*
    Conta conta;

    printf("Insira o nome da conta: ");
    scanf(" %100[^\n]", conta.nome);

    printf("Insira o valor da conta: ");
    scanf("%f", &conta.valor);
*/
    Node* novo = (Node*) malloc(sizeof(Node));
    if (novo == NULL) {
        printf("Falha ao alocar memória para o node.\n");
        exit(1);
    }

    novo->conta = conta;
    novo->prox = NULL;

    // Caso seja a primeira conta
    if (node == NULL) {
        return novo;
    }

    // Senão, adiciona ao final
    Node* atual = node;
    while (atual->prox != NULL) {
        atual = atual->prox;
    }

    atual->prox = novo;
    return node;
}

void listar_contas(Node* node) {
    if (node == NULL) {
        printf("A lista está vazia.\n");
        return;
    }

    int counter = 1;
        for(Node* atual = node ; atual != NULL ; atual=atual->prox){
        printf("-----------------------------------\n");
        printf("Conta %d:\n", counter++);
        printf("Nome da conta:  %s\n", atual->conta.nome);
        printf("Valor da conta: %.2f\n", atual->conta.valor);
        printf("-----------------------------------\n");
        }
}

void calcular_media(Node* node){

    float media = 0;
    int counter = 0;
    for(Node* atual = node ; atual != NULL ; atual=atual->prox){
        media+=atual->conta.valor;
        counter++;
    }
    
    media/=counter;
    printf("A media de todas as contas e: %.2f\n", media);
}

void serialize(Node* node){
    FILE* file = fopen("LinkedList.txt", "w");
    if(file == NULL){
        printf("Failed to open the file!");
        return;
    }
    fprintf(file, "nome,valor\n");
    for(Node* atual = node; atual !=NULL; atual=atual->prox){
        fprintf(file, "%s,%.2f\n", atual->conta.nome, atual->conta.valor);
    }
    fclose(file);
}

Node* desserialize(Node* node, char* path) {
    FILE* file = fopen(path, "r");
    if (!file) {
        printf("Arquivo %s não encontrado. Continuando com lista vazia...\n", path);
        return node; // apenas retorna a lista atual (que pode estar vazia)
    }

    char line[256];

    // Ler e descartar o cabeçalho
    if (fgets(line, sizeof(line), file) == NULL) {
        printf("Arquivo %s está vazio.\n", path);
        fclose(file);
        return node;
    }

    // Ler cada linha do arquivo
    while (fgets(line, sizeof(line), file) != NULL) {
        line[strcspn(line, "\n")] = 0; // remove \n

        Conta conta;

        if (sscanf(line, "%99[^,],%f", conta.nome, &conta.valor) == 2) {
            node = criar_conta(node, conta); // adiciona à lista
        } else {
            printf("Linha inválida ignorada: %s\n", line);
        }
    }

    fclose(file);
    return node;
}

