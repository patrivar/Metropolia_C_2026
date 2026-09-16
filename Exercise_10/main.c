#include <stdio.h>
#include <string.h>

void remove_linefeed(char* string) {
    if (string[strlen(string) - 1] == '\n') {
        string[strlen(string) - 1] = '\0';
    }
}


int main(void) {
    int breaker = 1;
    char input[20];
    while (breaker == 1) {
        printf("Enter a string: ");
        fgets(input, sizeof(input), stdin);
        remove_linefeed(input);
        printf("Lenght of the string %s is %d.\n",input, strlen(input));

        if (strcmp(input, "stop") == 0) {
            printf("Goodbye!\n");
            breaker = 0;
        }
    }
}
