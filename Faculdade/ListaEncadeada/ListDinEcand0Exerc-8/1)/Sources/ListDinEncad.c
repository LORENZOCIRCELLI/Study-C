#include "../Headers/ListDinEncad.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

Elemento* cria_agenda() {
    return NULL;
}

Elemento* insere_contato(Elemento* lista, Contato contato) {
    Elemento* novo = (Elemento*) malloc(sizeof(Elemento));
    if (novo == NULL) {
        printf("Erro: falha na alocacao de memoria\n");
        exit(1);
    }
    novo->info = contato;
    novo->prox = NULL;
    if (lista == NULL || strcmp(contato.nome, lista->info.nome) < 0) {
        novo->prox = lista;
        return novo;
    }
    Elemento* atual = lista;
    while (atual->prox != NULL && strcmp(contato.nome, atual->prox->info.nome) > 0) {
        atual = atual->prox;
    }
    novo->prox = atual->prox;
    atual->prox = novo;
    return lista;
}

void lista_contatos(Elemento* lista) {
    if (lista == NULL) {
        printf("\nAgenda vazia\n");
        return;
    }
    printf("\n==== LISTA DE CONTATOS ====\n\n");
    Elemento* atual = lista;
    int contador = 1;
    while (atual != NULL) {
        printf("Contato %d:\n", contador);
        printf("Nome: %s\n", atual->info.nome);
        printf("Telefone: %s\n", atual->info.telefone);
        printf("Celular: %s\n", atual->info.celular);
        printf("Email: %s\n", atual->info.email);
        printf("Aniversario: %02d/%02d\n", atual->info.dataAniversario.dia, atual->info.dataAniversario.mes);
        printf("-------------------------\n");
        atual = atual->prox;
        contador++;
    }
}

Elemento* busca_contato(Elemento* lista, char* nome) {
    Elemento* atual = lista;
    while (atual != NULL) {
        if (strcmp(atual->info.nome, nome) == 0) {
            return atual;
        }
        atual = atual->prox;
    }
    return NULL;
}

Elemento* remove_contato(Elemento* lista) {
    if (lista == NULL) {
        printf("\nAgenda vazia! Não há contatos para remover\n");
        return lista;
    }
    char nome[41];
    printf("\nDigite o nome do contato que deseja remover: ");
    scanf(" %40[^\n]", nome);
    if (strcmp(lista->info.nome, nome) == 0) {
        Elemento* temp = lista;
        lista = lista->prox;
        free(temp);
        printf("Contato '%s' removido com sucesso!\n", nome);
        return lista;
    }
    Elemento* anterior = lista;
    Elemento* atual = lista->prox;
    while (atual != NULL && strcmp(atual->info.nome, nome) != 0) {
        anterior = atual;
        atual = atual->prox;
    }
    if (atual == NULL) {
        printf("Contato '%s' não encontrado na agenda\n", nome);
        return lista;
    }
    anterior->prox = atual->prox;
    free(atual);
    printf("Contato '%s' removido com sucesso!\n", nome);
    return lista;
}

void atualiza_contato(Elemento* lista) {
    if (lista == NULL) {
        printf("\nAgenda vazia. Não há contatos para atualizar\n");
        return;
    }
    char nome[41];
    printf("\nDigite o nome do contato que deseja atualizar: ");
    scanf(" %40[^\n]", nome);
    Elemento* contato = busca_contato(lista, nome);
    if (contato == NULL) {
        printf("Contato '%s' não localizado na agenda\n", nome);
        return;
    }
    printf("\nDados atuais do contato:\n");
    printf("Nome: %s\n", contato->info.nome);
    printf("Telefone: %s\n", contato->info.telefone);
    printf("Celular: %s\n", contato->info.celular);
    printf("Email: %s\n", contato->info.email);
    printf("Data de Aniversário: %02d/%02d\n", contato->info.dataAniversario.dia, contato->info.dataAniversario.mes);
    printf("\nDigite os novos dados do contato:\n");
    printf("Nome: ");
    scanf(" %40[^\n]", contato->info.nome);
    printf("Telefone: ");
    scanf(" %15[^\n]", contato->info.telefone);
    printf("Celular: ");
    scanf(" %15[^\n]", contato->info.celular);
    printf("Email: ");
    scanf(" %40[^\n]", contato->info.email);
    printf("Data do aniversario: ");
    scanf("%d", &contato->info.dataAniversario.dia);
    printf("Mês do aniversário: ");
    scanf("%d", &contato->info.dataAniversario.mes);
    printf("\nContato atualizado com sucesso!\n");
}

Elemento* remove_duplicados(Elemento* lista) {
    if (lista == NULL || lista->prox == NULL) {
        printf("\nNão foram encontrados contatos duplicados\n");
        return lista;
    }
    Elemento* atual = lista;
    int removidos = 0;
    while (atual != NULL) {
        Elemento* anterior = atual;
        Elemento* prox = atual->prox;
        while (prox != NULL) {
            if (strcmp(atual->info.nome, prox->info.nome) == 0) {
                anterior->prox = prox->prox;
                free(prox);
                prox = anterior->prox;
                removidos++;
            } else {
                anterior = prox;
                prox = prox->prox;
            }
        }
        atual = atual->prox;
    }
    if (removidos > 0) {
        printf("\nForam removidos %d contato(s) duplicado(s)\n", removidos);
    } else {
        printf("\nNão foram encontrados contatos duplicados\n");
    }
    return lista;
}

void libera_agenda(Elemento *lista){
    Elemento *atual = lista;
    Elemento *prox;
    while(atual != NULL){
        prox = atual->prox;
        free(atual);
        atual = prox;
    }
}

Contato le_contato(){
    Contato contato;
    printf("\nDigite os dados do contato: \n");
    printf("Nome: ");
    scanf(" %40[^\n]", contato.nome);
    printf("Telefone: ");
    scanf(" %15[^\n]", contato.telefone);
    printf("Celular: ");
    scanf(" %15[^\n]", contato.celular);
    printf("Email: ");
    scanf(" %40[^\n]", contato.email);
    printf("Data de aniversario: ");
    scanf("%d", &contato.dataAniversario.dia);
    printf("Mes de aniversario: ");
    scanf("%d", &contato.dataAniversario.mes);
    return contato;
}

void exibe_contato(Contato contato){
    printf("\n===== DETALHES DO CONTATO ======\n");
    printf("Nome: %s\n", contato.nome);
    printf("Telefone: %s\n", contato.telefone);
    printf("Celular: %s\n", contato.celular);
    printf("Email: %s\n", contato.email);
    printf("Data de Aniversário: %02d/%02d\n", contato.dataAniversario.dia, contato.dataAniversario.mes);
    printf("\n====================================\n");
}

