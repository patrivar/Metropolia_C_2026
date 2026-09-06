#include <stdbool.h>
#include <stdio.h>

bool read_positive(int *value) {
    int number;
    printf("Guess how much money i have!\n");
    printf("Enter positive number: ");
    if (scanf("%d", &number) != 1) {
        int t;
        while ((t = getchar()) != '\n') {
        }
        return false;
    }
    if (number > 0) {
        *value = number;
        return true;
    }
    return false;
}

int main(void) {
    int guess;
    int counter = 0;
    while (counter < 3) {
        if (read_positive(&guess)) {
            guess = guess * 2 + 20;
            printf("You didn't get it right. I have %d euros.\n", guess);
        }
        else {
            printf("Invalid input!\n");
            counter ++;
        }
    }
    printf("I give up! See you later!\n");
}
