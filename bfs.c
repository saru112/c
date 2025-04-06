#include <stdio.h>

int a[10][10], q[10], vis[10], rear = -1, front = -1;

void bfs(int s, int n);
void add(int item);
int delet();

void main() {
    int i, j, n, s;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Input adjacency matrix
    printf("Enter the adjacency matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            printf("Enter the value if there is an edge between %d and %d: ", i + 1, j + 1);
            scanf("%d", &a[i][j]);                
        }
    }

    // Display adjacency matrix
    printf("The adjacency matrix is:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }

    // Get the starting vertex for BFS
    printf("Enter the starting vertex: ");
    scanf("%d", &s);
    s--;  // Adjust to 0-based index

    // Initialize visited array
    for(i = 0; i < n; i++) {
        vis[i] = 0;
    }

    // Start BFS
    bfs(s, n);
}

void bfs(int s, int n) {
    int i, p;
    
    add(s);
    vis[s] = 1;

    while((p = delet()) != -1) {
        printf("%d\t", p + 1);  
        for(i = 0; i < n; i++) {
            if(a[p][i] != 0 && vis[i] == 0) {
                add(i);
                vis[i] = 1;
            }
        }
    }
}

void add(int item) {
    if(rear == 9) {
        printf("Queue overflow\n");
    } else {
        if(rear == -1) {
            front = rear = 0;
        } else {
            rear++;
        }
        q[rear] = item;
    }
}

int delet() {
    if(front == -1 || front > rear) {
        return -1;  
    } else {
        return q[front++];  
    }
}
