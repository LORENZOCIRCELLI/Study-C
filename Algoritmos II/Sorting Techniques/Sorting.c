#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>


void print_array(int array[], int n) {
    for(int i = 0 ; i < n ; i++) {
        printf("%d\n", array[i]);
    }
}

void selection_sort(int array[], int n) {
    clock_t start = clock();

    for(int i = 0 ; i < n - 1 ; i++) {
        int min_idx = i;
        for(int j = i+1 ; j < n ; j++) {
            if(array[j] < array[min_idx]) {
                min_idx = j;
            }
        }
        int temp = array[i];
        array[i] = array[min_idx];
        array[min_idx] = temp;
    }

    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    print_array(array, n);
    printf("Tempo de execucao (Selection Sort): %f segundos\n\n", time_spent);
}

void insertion_sort(int array[], int n) {
    clock_t start = clock();

    for(int i = 1; i < n; i++) {
        int key = array[i];
        int j = i - 1;
        while(j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }

    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    print_array(array, n);
    printf("Tempo de execucao (Insertion Sort): %f segundos\n\n", time_spent);
}

void bubble_sort(int array[], int n) {
    clock_t start = clock();

    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }

    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    print_array(array, n);
    printf("Tempo de execucao (Bubble Sort): %f segundos\n\n", time_spent);
}

void merge(int array[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int *L = malloc(n1 * sizeof(int));
    int *R = malloc(n2 * sizeof(int));

    for(int i = 0; i < n1; i++)
        L[i] = array[l + i];
    for(int j = 0; j < n2; j++)
        R[j] = array[m + 1 + j];

    int i = 0, j = 0, k = l;

    while(i < n1 && j < n2) {
        if(L[i] <= R[j]) {
            array[k++] = L[i++];
        } else {
            array[k++] = R[j++];
        }
    }

    while(i < n1) {
        array[k++] = L[i++];
    }

    while(j < n2) {
        array[k++] = R[j++];
    }

    free(L);
    free(R);
}

void merge_sort_recursive(int array[], int l, int r) {
    if(l < r) {
        int m = l + (r - l) / 2;
        merge_sort_recursive(array, l, m);
        merge_sort_recursive(array, m + 1, r);
        merge(array, l, m, r);
    }
}

void merge_sort(int array[], int n) {
    clock_t start = clock();

    merge_sort_recursive(array, 0, n - 1);

    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    print_array(array, n);
    printf("Tempo de execucao (Merge Sort): %f segundos\n\n", time_spent);
}

int file_loader(int array[]) {
    char buffer[2000];
    FILE *file = fopen("data.csv", "r"); 

    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        return 0;
    }

    fgets(buffer, 2000, file);
    fclose(file);

    int count = 0;
    char *token = strtok(buffer, ",");

    while (token != NULL) {
        array[count++] = atoi(token);
        token = strtok(NULL, ",");
    }

    return count;
}

void copy_array(int src[], int dest[], int n) {
    for(int i = 0; i < n; i++) {
        dest[i] = src[i];
    }
}

int main() {
    int original[2000];
    int temp[200];
    int n = file_loader(original);

    copy_array(original, temp, n);
    printf("SELECTION SORT\n");
    selection_sort(temp, n);

    copy_array(original, temp, n);
    printf("INSERTION SORT\n");
    insertion_sort(temp, n);

    copy_array(original, temp, n);
    printf("BUBBLE SORT\n");
    bubble_sort(temp, n);

    copy_array(original, temp, n);
    printf("MERGE SORT\n");
    merge_sort(temp, n);

    return 0;
    
}
