#include <stdio.h>
#include<string.h>

int count_words(char *str, const char *word) {
    int count = 0;
    const char *ptr = str;
    const char *match;

    if (strlen(word) == 0) {
        return 0;
    }

    while ((match = strstr(ptr, word)) != NULL) {
        count++;
        ptr = match + strlen(word);
    }
    return count;
}


int main(void) {
    char text[100];
    char word[100];
    int count;
    int breaker = 0;

    while (breaker == 0) {
        printf("Enter a string: ");
        fgets(text, 100, stdin);
        text[strcspn(text, "\n")] = '\0';

        printf("Enter a word: ");
        fgets(word, 100, stdin);
        word[strcspn(word, "\n")] = '\0';

        if (strcmp(text, "stop") == 0) {
            breaker = 1;
        }

        count = count_words(text, word);
        printf("The word \"%s\" occurs %d times.\n\n", word, count);
    }
}
