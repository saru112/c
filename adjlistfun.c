//create display list display list adjacency matrix//
#include<stdio.h>
#include<malloc.h>
struct node 
{
    int data;
    struct node *next;
} *v[10];
struct node *p=NULL,*temp=NULL,*ptr=NULL;
int a[10][10];int n;
//create matrix//
void createmat(int a[][n],int n)
{
    int i,j,x;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i!=j)
            {
                printf("enter the value between %d and %d vertex",i,j);
                scanf("%d",&x);
                if(x>0)
                a[i][j]=1;
            }
            a[i][j]=0;
        }
    }
}
//display matrix//
void displaymat(int a[][n],int n)
{ int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d\t",a[i][j]);

        }
        printf("\n");
    }
}
//calculate degree//
void calculatedegree(int a[][n],int n)
{ int i,j,k,sumi,sumo;
 for(k=0;k<n;k++)//start indegree,out and total degree
    {
        sumi=0;
        for(i=0;i<n;i++)
        sumi=sumi+a[i][k];
        sumo=0;
        for(j=0;j<n;j++)
        sumo=sumo+a[k][j];
        printf("indegree,outdegree,totaldegree of %d vertex is %d\t %d\t %d\t",k,sumi,sumo,sumi+sumo);

    }}
    //create list//
    
    void createlist(struct node *v[], int n) {
    struct node *p, *temp;
    int i, j;

    
    for (i = 0; i < n; i++) {
        v[i] = NULL;
    }

    
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i != j) {
                p = (struct node *)malloc(sizeof(struct node));
                p->data = j;
                p->next = NULL;

                
                if (v[i] == NULL) {
                    v[i] = p;
                } else {
                    
                    temp->next = p;
                }
                temp = p;
            }
        }
    }
}
//display list
void displaylist(int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        ptr=v[i];
        while(ptr!=NULL)
        {
            printf("%d\t",i);
            printf("%d\t",ptr->data);
            ptr=ptr->next;
        }
    }
}
int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    createmat(a, n); 
    displaymat(a, n); 

    createlist(v, n); 
    printf("Adjacency List:\n");
    displaylist(n); 
    printf("Degree of vertices:\n");
    calculatedegree(a, n);

    return 0;
}