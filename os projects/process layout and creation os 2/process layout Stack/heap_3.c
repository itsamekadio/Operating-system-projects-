#include <stdio.h>
#include <stdlib.h>

int main() {
    long *heap = (unsigned long *)calloc(40, sizeof(unsigned long));
    printf("heap[2]: 0x%lx\n", heap[2]);
    printf("heap[1]: 0x%lx\n", heap[1]);
    printf("heap[0]: 0x%lx\n", heap[0]);
    printf("heap[-1]: 0x%lx\n", heap[-1]); // This will cause undefined behavior
    printf("heap[-2]: 0x%lx\n", heap[-2]); // This will cause undefined behavior
    return 0;
}

