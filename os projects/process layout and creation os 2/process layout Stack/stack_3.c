#include <stdio.h>

void zot(unsigned long *stop) {
    unsigned long r = 0x3;
    unsigned long *i;
    for (i = &r; i <= stop; i++) {
        printf("%p 0x%lx\n", (void *)i, *i);
    }
}

void foo(unsigned long *stop) {
    unsigned long q = 0x2;
    zot(stop);
}

int main() {
    int pid = getpid();
    unsigned long p = 0x1;
    foo(&p);
    printf("\n\n/proc/%d/maps\n\n", pid);
    char command[50];
    sprintf(command, "cat /proc/%d/maps", pid);
    system(command);
    return 0;
}

