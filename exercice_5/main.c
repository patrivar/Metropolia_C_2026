#include <stdio.h>

int read_range(int low, int high) {
    int roll;
    printf("Roll a die and enter your result.\n");
    printf("Enter number between %d and %d: ", low, high);
    scanf("%d", &roll);
    return roll;
}


int main(void) {
    int low = 1;
    int high = 6;
    int cheat = 0;
    int roll = read_range(low, high);
    while (roll != high) {
        if (roll < high && roll >= low ) {
            cheat = roll + 1;
            printf("I got %d. I win!\n", cheat);
        }
        roll = read_range(low, high);
    }
    printf("I got %d. It is a tie!\n", high);
    printf("Better luck next time!\n");
}
