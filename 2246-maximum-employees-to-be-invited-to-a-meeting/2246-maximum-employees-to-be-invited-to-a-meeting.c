#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to find the maximum number of employees to be invited
int maximumInvitations(int* favorite, int n) {
    // Step 1: Initialize arrays
    int* ins = (int*)calloc(n, sizeof(int));     // Array to store in-degrees
    int* queue = (int*)malloc(n * sizeof(int)); // Queue for topological sorting
    int* deep = (int*)calloc(n, sizeof(int));   // Depth array to store chain lengths

    // Step 2: Count in-degrees
    for (int i = 0; i < n; i++) {
        ins[favorite[i]]++;
    }

    // Step 3: Process chains using topological sorting
    int l = 0, r = 0; // Pointers for the queue
    for (int i = 0; i < n; i++) {
        if (ins[i] == 0) queue[r++] = i; // Add nodes with in-degree 0
    }

    while (l < r) {
        int cur = queue[l++];              // Remove node from queue
        int next = favorite[cur];          // Follow the edge to the next node
        deep[next] = (deep[next] > deep[cur] + 1) ? deep[next] : deep[cur] + 1; // Update chain length
        if (--ins[next] == 0) {            // Reduce in-degree of the next node
            queue[r++] = next;
        }
    }

    // Step 4: Process cycles and calculate results
    int smallCircle = 0; // Sum of lengths of chains and 2-cycles
    int bigCircle = 0;   // Maximum cycle length for larger cycles

    for (int i = 0; i < n; i++) {
        if (ins[i] != 0) { // Node is part of a cycle
            ins[i] = 0;    // Mark node as visited
            int count = 1; // Count the cycle size
            for (int j = favorite[i]; j != i; j = favorite[j]) {
                count++;
                ins[j] = 0; // Mark all nodes in the cycle as visited
            }

            if (count == 2) { // Special case: 2-cycle
                smallCircle += deep[i] + deep[favorite[i]] + 2;
            } else { // Larger cycles
                bigCircle = (bigCircle > count) ? bigCircle : count;
            }
        }
    }

    // Free allocated memory
    free(ins);
    free(queue);
    free(deep);

    return (bigCircle > smallCircle) ? bigCircle : smallCircle; // Return the maximum result
}
