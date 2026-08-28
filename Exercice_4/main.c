#include <stdio.h>

int read_integer(void) {
    int number;
    printf("Enter positive number or negative to stop: ");
    scanf("%d", &number);
    return number;
}


int main(void) {
    float number = read_integer();
    float total = 0;
    int counter = 0;
    while (number > 0) {
        total += number;
        counter += 1;
        number = read_integer();
        }
    total = total / counter;
    printf("You entered %d positive numbers. The average is: %.3f\n", counter, total);
}
