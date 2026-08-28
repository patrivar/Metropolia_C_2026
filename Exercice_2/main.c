#include <stdio.h>

float tax_rate (void) {
    float taxrate;
    printf("Enter the tax rate: ");
    scanf("%f", &taxrate);
    return taxrate;
}

float limit (void) {
    float limit;
    printf("Enter the income limit: ");
    scanf("%f", &limit);
    return limit;
}

float tax_over (void) {
    float taxover;
    printf("Enter the tax for income over the limit: ");
    scanf("%f", &taxover);
    return taxover;
}

void months (float months[12]) {
    for (int i = 0; i < 12; i++) {
        printf("Enter income for month %d: ", i + 1);
        scanf("%f", &months[i]);
    }
}

int main(void) {
    float taxrate = tax_rate();
    float taxlimit = limit();
    float taxover = tax_over();
    float total;
    float sallary[12];
    months(sallary);
    float tax[12];

    printf("%10s %10s %10s\n", "month", "Income", "Tax");

    for (int i = 0; i < 12; i++) {
        total = total + sallary[i];
        if (total <= taxlimit) {
            tax[i] = sallary[i] * (taxrate / 100);
        }
        else {
            tax[i] = sallary[i] * (taxover / 100);
        }
        printf("%10d %10.2f %10.2f\n", i + 1, sallary[i], tax[i]);
    }
}
