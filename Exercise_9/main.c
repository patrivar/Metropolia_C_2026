#include <stdio.h>
#include <stdlib.h>

int find_first(const unsigned int *array, unsigned int what) {
    for (int i = 0; array[i] != 0; i++) {
        if (array[i] == what) {
            return i;
        }
    }
    return -1;
}


int main(void) {
    int array[20];
    int what;
    int breaker = 1;
    for (int i = 0; i < 19; i++) {
        array[i] = (rand() % 20) + 1;
        printf("%d\n", array[i]);
    }
    array[19] = 0;

    while (breaker == 1) {
        printf("Enter number to see if it is in the array:");
        scanf("%d", &what);
        int index = find_first(array, what);
        if (what == 0) {
            printf("Goodbye!\n");
            breaker = 0;
        }
        if (index == -1) {
            printf("The number is not found in the array.\n");
        } else {
            printf("The number was found at index %d.\n", index);
            breaker = 0;
        }
    }
}