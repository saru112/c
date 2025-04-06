#include <stdio.h>

int a[10][10], vis[10], stack[10], top = -1;

void dfs(int s, int n);
void push(int item);
int pop();

int main() {
    int i, j, n, s;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            printf("Enter the value if there is an edge between vertex %d and vertex %d: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    printf("The adjacency matrix is:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    
    printf("Enter the starting vertex for DFS: ");
    scanf("%d", &s);

   
    for (i = 1; i <= n; i++) {
        vis[i] = 0;
    }

    
    dfs(s, n);

    return 0;
}

void dfs(int s, int n) {
    int k, i;
    
    push(s);  
    vis[s] = 1; 
    
    while ((k = pop()) != 0) {  
        printf("%d ", k); 
        
       
        for (i = 1; i <= n; i++) {
            if (a[k][i] != 0 && vis[i] == 0) {
                push(i); 
                vis[i] = 1;  
            }
        }
    }
}

void push(int item) {
    if (top == 9) {
        printf("Stack overflow\n");
    } else {
        stack[++top] = item;
    }
}

int pop() {
    if (top == -1) {
        return 0;  
    } else {
        return stack[top--]; 
    }
}
