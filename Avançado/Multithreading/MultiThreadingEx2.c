#include <stdio.h>
#include <pthread.h>

struct Dados {
    int a, b;
};

void* somar(void* arg) {
    struct Dados* dados = arg;
    int* resultado = malloc(sizeof(int));
    *resultado = dados->a + dados->b;
    return resultado;
}

int main() {
    pthread_t tid;
    struct Dados d = {3, 7};
    int* resultado;

    pthread_create(&tid, NULL, somar, &d);
    pthread_join(tid, (void**)&resultado);

    printf("Soma = %d\n", *resultado);
    free(resultado);

    return 0;
}
