#include<stdio.h>

void main() {
    int a[10][10], i, n, x,k, j,sumi,sumo;
    for(i = 0; i < 10; i++) {
        for(j = 0; j < 10; j++) 
        {
            a[i][j] = 0;
        }
    }

    // Taking the size of the matrix
    printf("\nHow many vertices in the graph? ");
    scanf("%d", &n);

    printf("\nEnter the adjacency matrix (enter 1 if there is an edge, 0 otherwise):\n");
    
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if(i != j) { 
                printf("Enter the value between vertex %d and vertex %d: ", i, j);
                scanf("%d", &x);
                if(x > 0)
                    a[i][j] = 1; 
            }
        }
    }

    printf("\nThe adjacency matrix is:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
    for(k=0;k<n;k++)
    {
        sumi=0;
        for(i=0;i<n;i++)
        sumi=sumi+a[i][k];
        sumo=0;
        for(j=0;j<n;j++)
        sumo=sumo+a[k][j];
        printf("indegree,outdegree,totaldegree of %d vertex is %d %d %d",k,sumi,sumo,sumi+sumo);

    }

}
