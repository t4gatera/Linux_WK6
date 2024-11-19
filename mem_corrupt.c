#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int size;
} str;

str* create_array(int size) {
    str *arr = (str *)malloc(sizeof(str));
    if (arr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    arr->size = size;
    arr->data = (int *)malloc(size * sizeof(int));
    if (arr->data == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    return arr;
}

void fill_array(str *arr) {
    for (int i = 0; i <= arr->size; i++) {
        arr->data[i] = i * 10;
    }
}

void free_array(str *arr) {
    free(arr->data);
    free(arr);
}

int main() {
    str *arr = create_array(5);
    fill_array(arr);
    printf("Array filled\n");

    free_array(arr);
    return 0;
}

/* to compile it
gcc -g -o memcorr - mem_corrupt.c

in order to inspect the momory corruption
valgrind --tool=memcheck --leak-check=full ./memcorr */

