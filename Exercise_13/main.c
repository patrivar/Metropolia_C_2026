#include <stdio.h>
#include <stdlib.h>



int main(void) {
    char filename[100];
    FILE *fp;
    int number;
    int count = 0;
    int min, max;
    printf("Enter the file name: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");

    if (fp == NULL) {
        fprintf(stderr, "Error: Cannot open file %s\n", filename);
    }

    while (fscanf(fp, "%d", &number) == 1) {
        if (count == 0) {
            min = max = number;
        } else {
            if (number < min) {
                min = number;
            }
            if (number > max) {
                max = number;
            }
        }
        count++;
    }

    if (count > 0) {
        printf("count: %d\n", count);
        printf("Lowest number: %d\n", min);
        printf("Highest number: %d\n", max);
    } else {
        printf("No integers found in file\n");
    }
    fclose(fp);
}
