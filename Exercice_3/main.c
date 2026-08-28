#include <stdio.h>

int attending_students (void) {
    int attending_students;
    printf("How many students: ");
    scanf("%d", &attending_students);
    return attending_students;
}

int main(void) {
    int amount = attending_students();
    int choise_1 = -1;
    int choise_2;
    int grades[amount];

    for (int i = 0; i < amount; i++) {
        grades[i] = -1;
    }

    while (choise_1 != 0) {
        printf("Enter student number (1 - %d) or 0 to stop: ", amount);
        scanf("%d", &choise_1);

        if (choise_1 > 0 && choise_1 <= amount) {
            choise_2 = 0;
            while ((choise_2 < 1 || choise_2 > 5) && choise_2 != -1) {
                printf("Enter grade (0 - 5) for student %d or -1 to cancel: ", choise_1);
                scanf("%d", &choise_2);

                if (choise_2 > 0 && choise_2 < 6) {
                    grades[choise_1 - 1] = choise_2;
                }
                else if (choise_2 < 1 || choise_2 > 5)  {
                    printf("Invalid grade!\n");
                }
            }
        }
        else if (0 > choise_1 || choise_1 > amount) {
            printf("Invalid student number!\n");
        }
    }

    if (choise_1 == 0) {
        printf("%-10s %s\n", "Student", "Grade");
        for (int i = 0; i < amount; i++) {
            if (grades[i] == -1) {
                printf("%5d %10s\n", i + 1, "N/A");
            } else {
                printf("%5d %10d\n", i + 1, grades[i]);
            }
        }
    }
}
