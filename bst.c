
#include<stdio.h>
#include<malloc.h>
#include"bst.h"
void main()
{
    struct node *root=NULL,*root1=NULL;
    struct node *create();
    struct node *insert();
    void inorder();
    void preorder();
    void postorder();
    int totalnode();
    int leafnode();
    int nonleafnode();
    struct node *treecopy();
    void mirror();
    int ch,q=0,k,n,x;
    do{
printf("\n1.create\n2.insert\n3.inorder\n4.preorder\n5.postorder\n6.count total no ofnode\n7.count total no of leafnode\n8.count total no.of nonleaf node\n9.copy a tree\n10.mirror of image\n11.exit");
printf("enter your choice");
scanf("%d",&ch);
switch(ch)
{
    case 1:root=create(root);
    break;
    case 2:root=insert(root);
    break;
    case 3:inorder(root);
    break;
    case 4:preorder(root);
    break;
    case 5:postorder(root);
    break;
    case 6: k=totalnodes(root);
    printf("total no of node are %d",k);
    break;
    case 7:x=leafcount(root);
    printf("the total no of leaf cont are %d",x);
    break;
    case 8:n=nonleafcount(root);
    printf("totalno of nonleaf count are %d",n);
    break;
    case 9:root1=treecopy(root);
    inorder(root1);
    break;
    case 10:mirror(root);
    inorder(root);
    break;
    case 11:q=1;
    break;
}
    }
    while (q==0);
    
}


