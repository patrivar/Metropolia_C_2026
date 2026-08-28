#include <stdio.h>
#include <stdlib.h>

int menu() {
    int choice = 0;
    printf("Do you want to roll a die or quit?\n");
    printf("1. D6\n");
    printf("2. D10\n");
    printf("3. Quit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

int D6() {
    int throw = 7;
    while (throw > 6) {
        throw = 1 + rand() / ((RAND_MAX + 1u) / 6);
    }
    printf("You rolled %d\n", throw);
}
1
int D10() {
    int throw = 11;
    while (throw > 10) {
        throw = 1 + rand() / ((RAND_MAX + 1u) / 10);
    }
    printf("You rolled %d\n", throw);
}

int main(void) {
    int choice = menu();

    while (choice != 3) {
        if (choice == 1) {
            D6();
            choice = menu();
        }
        else if (choice == 2) {
            D10();
            choice = menu();
        }
        else if (choice < 1 || choice > 3) {
            choice = menu();
        }
    }
    printf("Goodbye!\n");
}
