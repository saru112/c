#include<stdio.h>
#include<malloc.h>
#include"hash1.h"  

void folding();
void division();
void midsquare();

void main()
{
    int ch, q = 0;
    
    do {
        printf("\n1. division\n2. folding\n3. midsquare\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch(ch)  
        {
            case 1:
                division();  
                break;
            case 2:
                folding();  
                break;
            case 3:
                midsquare();  
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
