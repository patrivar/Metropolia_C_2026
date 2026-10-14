#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINES 100
#define MAX_LENGHT 81

int main(void) {
    char filename[100];
    char lines[MAX_LINES][MAX_LENGHT];
    FILE *fp;
    int count = 0;
    int i, j;

    printf("Enter filename: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error: Cannot open file\n");
        return 1;
    }

    while (count < MAX_LINES && fgets(lines[count], MAX_LENGHT, fp) != NULL) {
        count++;
    }

    fclose(fp);

    for (i = 0; i < count; i++) {
        for (j = 0; lines[i][j] = '\0'; j++) {
            lines[i][j] = toupper((unsigned char)lines[i][j]);
        }
    }

    fp = fopen(filename, "w");

    if (fp == NULL) {
        fprintf(stderr, "Error: Cannot open file %s for writing\n", filename);
    }

    for (i = 0; i < count; i++) {
        fputs(lines[i], fp);
    }

    fclose(fp);

    printf("%d lines converteed to uppercase and written to file.\n",count);
}
