#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <locale.h>

#define MAX_PARTIDAS 9000

typedef struct {
    int ano_campeonato;
    char data[11]; // formato "AAAA-MM-DD"
    int rodada;
    char estadio[100];
    char arbitro[100];
    int publico;
    int publico_max;
    char time_mandante[50];
    char time_visitante[50];
    char tecnico_mandante[100];
    char tecnico_visitante[100];
    int colocacao_mandante;
    int colocacao_visitante;
    int valor_equipe_titular_mandante;
    int valor_equipe_titular_visitante;
    float idade_media_titular_mandante;
    float idade_media_titular_visitante;
    int gols_mandante;
    int gols_visitante;
    int gols_1_tempo_mandante;
    int gols_1_tempo_visitante;
    int escanteios_mandante;
    int escanteios_visitante;
    int faltas_mandante;
    int faltas_visitante;
    int chutes_bola_parada_mandante;
    int chutes_bola_parada_visitante;
    int defesas_mandante;
    int defesas_visitante;
    int impedimentos_mandante;
    int impedimentos_visitante;
    int chutes_mandante;
    int chutes_visitante;
    int chutes_fora_mandante;
    int chutes_fora_visitante;
} Metadados;

Metadados metadados[MAX_PARTIDAS];

int carregar_arquivo() {
    FILE *file = fopen("brasileirao_serie_a.csv", "r");
    if (!file) {
        printf("Erro ao abrir o arquivo.\n");
        return 0;
    }

    char linha[2000];
    int i = 0;

    // Ignora o cabeçalho
    fgets(linha, sizeof(linha), file);

    while (fgets(linha, sizeof(linha), file)) {
        Metadados p;
        char *token;
        int campo = 0;

        // Inicializa valores padrão
        memset(&p, 0, sizeof(Metadados));
        p.publico = p.publico_max = -1;
        p.colocacao_mandante = p.colocacao_visitante = -1;
        p.valor_equipe_titular_mandante = p.valor_equipe_titular_visitante = -1;
        p.idade_media_titular_mandante = p.idade_media_titular_visitante = -1;
        p.gols_mandante = p.gols_visitante = -1;
        p.gols_1_tempo_mandante = p.gols_1_tempo_visitante = -1;
        p.escanteios_mandante = p.escanteios_visitante = -1;
        p.faltas_mandante = p.faltas_visitante = -1;
        p.chutes_bola_parada_mandante = p.chutes_bola_parada_visitante = -1;
        p.defesas_mandante = p.defesas_visitante = -1;
        p.impedimentos_mandante = p.impedimentos_visitante = -1;
        p.chutes_mandante = p.chutes_visitante = -1;
        p.chutes_fora_mandante = p.chutes_fora_visitante = -1;
        strcpy(p.arbitro, "N/A");
        strcpy(p.tecnico_mandante, "N/A");
        strcpy(p.tecnico_visitante, "N/A");

        token = strtok(linha, ",");

        while (token != NULL) {
            // Remove quebras de linha
            token[strcspn(token, "\n")] = '\0';

            // Preenche campo por campo
            switch (campo) {
                case 0: p.ano_campeonato = atoi(token); break;
                case 1: strncpy(p.data, token, 10); break;
                case 2: p.rodada = atoi(token); break;
                case 3: strncpy(p.estadio, token, 99); break;
                case 4: strncpy(p.arbitro, token, 99); break;
                case 5: if (*token) p.publico = atoi(token); break;
                case 6: if (*token) p.publico_max = atoi(token); break;
                case 7: strncpy(p.time_mandante, token, 49); break;
                case 8: strncpy(p.time_visitante, token, 49); break;
                case 9: strncpy(p.tecnico_mandante, token, 99); break;
                case 10: strncpy(p.tecnico_visitante, token, 99); break;
                case 11: if (*token) p.colocacao_mandante = atoi(token); break;
                case 12: if (*token) p.colocacao_visitante = atoi(token); break;
                case 13: if (*token) p.valor_equipe_titular_mandante = atoi(token); break;
                case 14: if (*token) p.valor_equipe_titular_visitante = atoi(token); break;
                case 15: if (*token) p.idade_media_titular_mandante = atof(token); break;
                case 16: if (*token) p.idade_media_titular_visitante = atof(token); break;
                case 17: if (*token) p.gols_mandante = atoi(token); break;
                case 18: if (*token) p.gols_visitante = atoi(token); break;
                case 19: if (*token) p.gols_1_tempo_mandante = atoi(token); break;
                case 20: if (*token) p.gols_1_tempo_visitante = atoi(token); break;
                case 21: if (*token) p.escanteios_mandante = atoi(token); break;
                case 22: if (*token) p.escanteios_visitante = atoi(token); break;
                case 23: if (*token) p.faltas_mandante = atoi(token); break;
                case 24: if (*token) p.faltas_visitante = atoi(token); break;
                case 25: if (*token) p.chutes_bola_parada_mandante = atoi(token); break;
                case 26: if (*token) p.chutes_bola_parada_visitante = atoi(token); break;
                case 27: if (*token) p.defesas_mandante = atoi(token); break;
                case 28: if (*token) p.defesas_visitante = atoi(token); break;
                case 29: if (*token) p.impedimentos_mandante = atoi(token); break;
                case 30: if (*token) p.impedimentos_visitante = atoi(token); break;
                case 31: if (*token) p.chutes_mandante = atoi(token); break;
                case 32: if (*token) p.chutes_visitante = atoi(token); break;
                case 33: if (*token) p.chutes_fora_mandante = atoi(token); break;
                case 34: if (*token) p.chutes_fora_visitante = atoi(token); break;
            }

            token = strtok(NULL, ",");
            campo++;
        }

        metadados[i++] = p;
    }

    fclose(file);
    return i;
}



int main() {
    int total = carregar_arquivo();
    printf("Total de partidas carregadas: %d\n\n", total);

    for (int i = 0; i < 5 && i < total; i++) {
        printf("Rodada %d - %s x %s (%d x %d)\n",
               metadados[i].rodada,
               metadados[i].time_mandante,
               metadados[i].time_visitante,
               metadados[i].gols_mandante,
               metadados[i].gols_visitante);
    }

    return 0;
}

