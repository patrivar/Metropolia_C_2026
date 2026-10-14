#include <stdio.h>
#include<string.h>


int replace_char(char *str, const char *repl) {
    int count = 0;
    char oldchar, newchar;

    if (strlen(repl) != 2) {
        return 0;
    }

    oldchar = repl[0];
    newchar = repl[1];

    while (*str != '\0') {
        if (*str == oldchar) {
            *str = newchar;
            count++;
        }
        str++;
    }
    return count;
}

int main(void) {
    char text[100];
    char repl[10];
    int count;

    printf("Enter string:");
    fgets(text, 100, stdin);
    text[strcspn(text, "\n")] = '\0';

    printf("Enter a string to replace char: ");
    fgets(repl, 10, stdin);
    repl[strcspn(repl, "\n")] = '\0';

    count = replace_char(text, repl);

    if (count > 0) {
        printf("Characters replaced: %d\n", count);
        printf("Modified string: %s\n", text);
    } else {
        printf("String was not modified.\n");
    }
}
