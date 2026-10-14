#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 40

typedef struct menu_items_{
    char name[50];
    double price;
} menu_items;

int main(void) {
    char filename[100];
    char line[100];
    menu_items items[MAX_ITEMS];
    FILE *fp;
    int count = 0;
    char *ptr;

    printf("Enter the file name: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error: Cannot open file %s\n", filename);
        return 1;
    }

    while (count < MAX_ITEMS && fgets(line, sizeof(line), fp) != NULL) {
        ptr = strchr(line, ';');

        if (ptr != NULL) {
            *ptr = '\0';

            strcpy(items[count].name, line);
            items[count].price = atof(ptr + 1);

            count++;
        }
    }

    fclose(fp);

    printf("\n%-8s %s\n", "Price", "Name");
    printf("--------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%8.2f %s\n", items[i].price, items[i].name);
    }
}
