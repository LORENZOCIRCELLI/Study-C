#include <stdio.h>
#include <pthread.h>

void* imprimirMensagem(void* arg) {
    printf("Executando thread!\n");
    return NULL;
}

int main() {
    pthread_t tid;
    pthread_create(&tid, NULL, imprimirMensagem, NULL);
    pthread_join(tid, NULL);
    return 0;
}
