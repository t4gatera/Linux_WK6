#include <stdio.h>
#include <stdlib.h>

void allocate_memory() {
    int *leaky_array = (int *)malloc(5 * sizeof(int));
}

int main() {
    allocate_memory();
    printf("Memory leak demo.\n");
    return 0;
}

/* Compile it with -g flag for better analysis
gcc -g -o memleak mem_leak.c

Run the program using valgrind
valgrind --leak-check=full ./memleak    

if you don't have valgrind, install it using
sudo apt install valgrind */

