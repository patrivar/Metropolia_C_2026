#include <stdio.h>

float bus_ticket_price(void) {
    float ticket_price;
    printf("Enter the price of bus ticket: ");
    scanf("%f", &ticket_price);
    return ticket_price;
}

float taxi_drive_price(void) {
    float taxi_price;
    printf("Enter the price of taxi drive: ");
    scanf("%f", &taxi_price);
    return taxi_price;
}

float vallet(void) {
    float cash;
    printf("How much money do you have: ");
    scanf("%f", &cash);
    return cash;
}

int main(void) {
    float bus = bus_ticket_price();
    float taxi = taxi_drive_price();
    float cash = vallet();
    int selected;
    int breaker = 1;
    while (breaker == 1 && (cash >= bus || cash >= taxi)) {
        printf("You have total of %.2f euros.\n", cash);
        printf("Do you want to take\n");
        printf("1) Bus (%.2f)\n", bus);
        printf("2) Taxi (%.2f)\n", taxi);
        printf("Enter your selection: ");
        scanf("%d", &selected);
        if (selected == 1 && cash >= bus) {
            printf("You selected the bus1.\n");
            cash = cash - bus;
        }
        else if (selected == 2 && cash >= taxi) {
            printf("You selected the taxi2.\n");
            cash = cash - taxi;
        }
        else if (cash >= bus && cash < taxi) {
            int YNbus;
            printf("You dont have enought money for taxi.\n");
            printf("Do you want to take bus?\n");
            printf("1) Yes\n");
            printf("2) No\n");
            scanf("%d", &YNbus);
            if (YNbus == 1) {
                printf("You selected the bus2.\n");
                cash = cash - bus;
            } else if (YNbus == 2) {
                printf("Have a great walk. Bye!\n");
                breaker = 0;
            }
        }
        else if (cash >= taxi && cash < bus) {
            int YNtaxi;
            printf("You dont have enought money for taxi.\n");
            printf("Do you want to take taxi?\n");
            printf("1) Yes\n");
            printf("2) No\n");
            scanf("%d", &YNtaxi);
            if (YNtaxi == 1) {
                printf("You selected the taxi2.\n");
                    cash = cash - taxi;
            } else if (YNtaxi == 2) {
                printf("Have a great walk. Bye!\n");
                breaker = 0;
            }
        }
    }
    if (breaker == 1) {
        printf("you have only %.2f euros left\n", cash);
        printf("Have a nice walk. Bye!\n");
    }
}