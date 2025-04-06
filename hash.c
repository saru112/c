#include<stdio.h>
#include<malloc.h>
#include"hash.h"  // Assuming hash.h contains necessary declarations

void insert();
void search();
void display();

void main()
{
    int ch, q = 0;
    
    do {
        printf("\n1. Insert\n2. Search\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch(ch)  // Fixed the semicolon issue
        {
            case 1:
                insert();  // Function for insertion
                break;
            case 2:
                search();  // Function to search elements
                break;
            case 3:
                display();  // Function to display elements
                break;
            case 4:
                q = 1;  // Exit condition
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    while (q == 0);
}
