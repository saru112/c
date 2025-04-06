#include <stdio.h>

#define SIZE 10  // Fixed table size to avoid overflow

void division() {
    int a[SIZE], flag[SIZE], i, n, sum, key;
    printf("How many values: ");
    scanf("%d", &n);

    // Initialize arrays
    for (i = 0; i < SIZE; i++) {
        flag[i] = 0;
        a[i] = 0;
    }

    // Insert values into the hash table
    printf("Enter actual key values:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &key);
        sum = key % SIZE;
        printf("The hash address of %d is %d\n", key, sum);
        
        // Handle collision
        if (a[sum] == 0) {
            a[sum] = key;
        } else {
            flag[sum] = -1;  // Mark as collision
        }
    }

    // Print the hash table
    printf("The hash table is:\n");
    for (i = 0; i < SIZE; i++) {
        if (flag[i] == -1) {
            printf("%d = %d (collision)\n", i, a[i]);
        } else {
            printf("%d = %d\n", i, a[i]);
        }
    }
}

void folding() {
    int b[SIZE], flag[SIZE], f, l, x, key, n, i, sum;
    printf("How many values you want to enter into the table: ");
    scanf("%d", &n);

    // Initialize arrays
    for (i = 0; i < SIZE; i++) {
        b[i] = 0;
        flag[i] = 0;
    }

    // Insert values into the hash table
    printf("Enter key values:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &key);
        sum = 0;
        l = key;
        
        // Folding technique: split the digits of key and sum them up
        do {
            x = key % 10;
            sum += x;
            key = key / 10;
        } while (key > 0);

        // If the sum is more than a single digit, fold it again
        while (sum >= 10) {
            key = sum;
            sum = 0;
            do {
                x = key % 10;
                sum += x;
                key = key / 10;
            } while (key > 0);
        }

        // Now sum is a single digit
        printf("Hash address of %d is %d\n", l, sum);

        // Linear probing for collision resolution
        f = sum % SIZE;  // Ensure the address is within bounds (0-9)
        while (flag[f] == 1) {  // If the slot is occupied, find the next one
            f = (f + 1) % SIZE;
        }

        b[f] = l;  // Insert the key into the table
        flag[f] = 1;  // Mark the slot as occupied
    }

    // Print the hash table
    printf("The hash table is:\n");
    for (i = 0; i < SIZE; i++) {
        if (flag[i] == 1) {
            printf("%d -> %d\n", i, b[i]);
        } else {
            printf("%d -> Empty\n", i);
        }
    }
}

void midsquare() {
    int c[SIZE], flag[SIZE], key, sum, l, x, n, i;
    printf("How many values you want to enter: ");
    scanf("%d", &n);

    // Initialize arrays
    for (i = 0; i < SIZE; i++) {
        c[i] = 0;
        flag[i] = 0;
    }

    // Insert values into the hash table
    printf("Enter key values:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &key);
        sum = key * key;
        l = key;

        // Extract middle digits
        sum = sum % 100;  // Extract the last two digits (middle if applicable)
        printf("Hash address for %d is %d\n", key, sum);

        // Linear probing for collision resolution
        if (c[sum] == 0) {
            c[sum] = 1;
        } else {
            flag[sum] = -1;  // Mark as collision
        }
    }

    // Print the hash table
    printf("The contents of the hash table are:\n");
    for (i = 0; i < SIZE; i++) {
        if (flag[i] == -1) {
            printf("%d = %d (collision)\n", i, c[i]);
        } else {
            printf("%d = %d\n", i, c[i]);
        }
    }
}

