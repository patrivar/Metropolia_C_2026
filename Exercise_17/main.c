#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

bool generate_password(char *password, int size, const char *word) {
    int wordlen = strlen(word);
    int passwordlen = wordlen * 2 + 1;

    if (passwordlen + 1 > size) {
        return false;
    }

    int pos = 0;

    password[pos++] = (char)(rand() % 95 + 32);

    for (int i = 0; i < wordlen; i++) {
        password[pos++] = word[i];
        password[pos++] = (char)(rand() % 95 + 32);
    }

    password[pos] = '\0';
    return true;
}

int main(void) {
    char word[32];
    char password[100];

    srand((unsigned int)time(NULL));

    while (1) {
        printf("Enter a word or 'stop': ");

        if (fgets(word, sizeof(word), stdin) == NULL) {
            break;
        }

        word[strcspn(word, "\n")] = '\0';

        if (strcmp(word, "stop") == 0) {
            break;
        }

        if (generate_password(password, sizeof(password), word)) {
            printf("Password: %s\n", password);
        } else {
            printf("Error: Password is too long.\n");
        }
    }
}
