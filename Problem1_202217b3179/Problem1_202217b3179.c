#include <stdio.h>
#include <stdlib.h>
#define MAX 20

void create();
void insert();
void deletion();
void search();
void display();

int b[MAX], n = 0;

void main() {
    int ch;
    char g = 'y';
    do {
        printf("\nMain Menu");
        printf("\n1. Create\n2. Delete\n3. Search\n4. Insert\n5. Display\n6. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                create();
                break;
            case 2:
                deletion();
                break;
            case 3:
                search();
                break;
            case 4:
                insert();
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
                break;
            default:
                printf("\nEnter the correct choice:");
        }
        printf("\nDo you want to continue (y/n)?: ");
        scanf(" %c", &g); // Note the space before %c to consume the newline character
    } while (g == 'y' || g == 'Y');
}

void create() {
    printf("\nEnter the number of elements: ");
    scanf("%d", &n);
    if (n > MAX) {
        printf("\nExceeds maximum allowed size of %d\n", MAX);
        n = 0;
        return;
    }
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &b[i]);
    }
}

void deletion() {
    int pos;
    printf("\nEnter the position you want to delete: ");
    scanf("%d", &pos);
    if (pos < 0 || pos >= n) {
        printf("\nInvalid position\n");
    } else {
        for (int i = pos; i < n - 1; i++) {
            b[i] = b[i + 1];
        }
        n--;
        printf("\nThe elements after deletion:");
        display();
    }
}

void search() {
    int e, found = 0;
    printf("\nEnter the element to be searched: ");
    scanf("%d", &e);
    for (int i = 0; i < n; i++) {
        if (b[i] == e) {
            printf("Value is in position %d\n", i);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Value %d is not in the list\n", e);
    }
}

void insert() {
    int pos, p;
    printf("\nEnter the position to insert: ");
    scanf("%d", &pos);
    if (pos < 0 || pos > n || n >= MAX) {
        printf("\nInvalid position or list is full\n");
    } else {
        for (int i = n; i > pos; i--) {
            b[i] = b[i - 1];
        }
        printf("\nEnter the element to insert: ");
        scanf("%d", &p);
        b[pos] = p;
        n++;
        printf("\nThe list after insertion:");
        display();
    }
}

void display() {
    printf("\nThe elements of the list are:");
    for (int i = 0; i < n; i++) {
        printf("\n%d", b[i]);
    }
}
