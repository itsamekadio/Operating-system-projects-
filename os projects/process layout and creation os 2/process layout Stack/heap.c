#include <stdio.h>
#include <stdlib.h>

int main() {
    char *heap = malloc(20);
    printf("the heap variable at: %p\n", (void *)&heap);
    printf("pointing to: %p\n", (void *)heap);
    return 0;
}

