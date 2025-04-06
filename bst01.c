//c evelprogram//
#include<stdio.h>
#include<malloc.h>
#include"bst.h"  
void main()
{struct node *root=NULL;
struct node *create();
void inorder();
void printlevelwise();
int printclevel();
    int ch, q=0,l,k;
    
    do {
        printf("\n1. create\n2. inordet\n3. leveiwise tree\n4. count totalno of node of tree\n5.exit");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch(ch) 
        {
            case 1:
                root=create(root);  
                break;
            case 2:
                inorder(root);  
                break;
            case 3:
                printlevelwise(root);  
                break;
                case 4: printf("ener level coun total no of node");
                scanf("%d",&l);
                k=printclevel(root,l);
                printf("the total no of node at %d level are %d",l,k);
                break;
            case 5:
                q = 1;  
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    while (q == 0);
}