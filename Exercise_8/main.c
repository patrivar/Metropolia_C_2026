#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define RAND_MAX 99999999

void print_numbers(const int *array, int count) {
    for (int i = 0; i < count; i++) {
        printf("%8d", array[i]);
    }
}

int main(void) {
    int array[15];
    srand(time(NULL));
    for (int i = 0; i < 15; i++) {
        array[i] = rand() % (RAND_MAX + 1);
    }
    print_numbers(array, 15);
}
