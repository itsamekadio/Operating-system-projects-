#include <stdio.h>
#include "greenFinal.h"

int flag = 0;
int loop = 4;
green_cond_t cond;
green_mutex_t mutex;

// Initialize count to 0 before thread creation
int count = 0;

void* test(void* arg) {
    int id = *(int*)arg;
    while (loop > 0) {
        green_mutex_lock(&mutex);
        count++; // Increment count (might not need lock here depending on usage)
        printf("thread %d: %d\n", id, count); // Print thread ID and count
        while (flag != id) {
            green_cond_wait(&cond, &mutex);
        }
        flag = (id + 1) % 2;
        green_cond_signal(&cond);
        green_mutex_unlock(&mutex);
        loop--;
    }
}

int main() {

    green_t g0, g1;
    int a0 = 0;
    int a1 = 1;
    green_create(&g0, test, &a0);
    green_create(&g1, test, &a1);
    green_join(&g0, NULL);
    green_join(&g1, NULL);
    printf("Final count: %d\n", count);
    return 0;
}
