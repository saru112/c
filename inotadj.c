#include<stdio.h>

void main() {
    int a[10][10], i, n, x, j, k, sumi, sumo;

    // Ask for number of vertices
    printf("\nEnter the number of vertices: ");
    scanf("%d", &n);

    // Input the adjacency matrix
    printf("\nEnter the adjacency matrix (use 0 for no edge and 1 for an edge):\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if(i != j) {
                printf("\nEnter the value between %d and %d (0 or 1): ", i, j);
                scanf("%d", &x);
                if(x > 0) {
                    a[i][j] = 1;
                } else {
                    a[i][j] = 0;
                }
            } else {
                a[i][j] = 0;  // No self-loops
            }
        }
    }

    // Display the adjacency matrix
    printf("\nThe adjacency matrix is:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }

    // Ask for the vertex k
    printf("\nEnter the vertex number (0 to %d) to calculate in-degree and out-degree: ", n-1);
    scanf("%d", &k);

    if(k < 0 || k >= n) {
        printf("\nInvalid vertex number.\n");
        return;
    }

    // Calculate in-degree (sum of the k-th column)
    sumi = 0;
    for(i = 0; i < n; i++) {
        sumi += a[i][k];
    }

    // Calculate out-degree (sum of the k-th row)
    sumo = 0;
    for(j = 0; j < n; j++) {
        sumo += a[k][j];
    }

    // Display in-degree, out-degree, and total degree
    printf("\nIn-degree, out-degree, and total degree of vertex %d are:\n", k);
    printf("In-degree: %d\n", sumi);
    printf("Out-degree: %d\n", sumo);
    printf("Total degree: %d\n", sumi + sumo);
}
