#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int number;
    struct node *next;
} node_;

int main(void) {
    node_ *head = NULL;
    node_ *tail = NULL;
    char input[100];
    int value;

    while (1) {
        printf("Enter a number or 'end' to stop: ");

        if (fgets(input, sizeof(input), stdin) == NULL) {
            break;
        }
        input[strcspn(input, "\n")] = '\0';
        if (strcmp(input, "end") == 0) {
            break;
        }
        if (sscanf(input, "%d", &value) != 1) {
            printf("Error: Invalid input.\n");
        }

        if (sscanf(input, "%d", &value) != 1) {
            printf("Error: Invalid input.\n");
            continue;
        }

        node_ *new_node = malloc(sizeof(node_));

        if (new_node == NULL) {
            printf("Error: Out of memory.\n");
            return 1;
        }

        new_node->number = value;
        new_node->next = NULL;

        if (head == NULL) {
            head = new_node;
            tail = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }
    }
    printf("Entered numbers:\n");

    node_ *current = head;
    while (current != NULL) {
        printf("%d\n", current->number);
        current = current->next;
    }

    current = head;
    while (current != NULL) {
        node_ *temp = current;
        current = current->next;
        free(temp);
    }
}
