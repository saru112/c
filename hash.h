#include<stdio.h>
#include<malloc.h>
struct node{
    int data;
    struct node *next;
};
struct node *head[10],*p=NULL,*temp=NULL;
void insert()
{
    int i,key;
    printf("enter the value to insert");
    scanf("%d",&key);
    i=key%10;
    p=(struct node *)malloc(sizeof(struct node));
    p->data=key;
    p->next=NULL;
    if(head[i]==NULL)
    {
        head[i]=p;

    }
    else{
        temp=head[i];
        while(temp->next!=NULL)
    
    {
        temp=temp->next;
    }
    temp->next=p;
}}

void search()
{
    int i,key;
    printf("enter key value to search");
    scanf("%d",&key);
    i=key%10;
    if(head[i]=NULL)
    {
        printf("element not found");
    }
    else{
        temp=head[i];
        while(temp!=NULL)
        {
            printf("element found");
            return;
        }
        temp=temp->next;
    }
    printf("element not found");
}

void display()
{
    int i,n;
    for(i=0;i<n;i++)
    {
        printf("%d",i);
        if(head[i]==NULL)
        {
            printf("NULL");
        }
        else{
            temp=head[i];
            while(temp!=NULL)
            {
                printf("%d",temp->data);
                temp=temp->next;
            }
        }
    }
printf("n");
}