#include <string.h>
#include <stdlib.h>

#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define INF 1000000000

long long minimumCost(char* source, char* target, char* original, int originalSize, char* changed, int changedSize, int* cost, int costSize) {
    int minCost[26][26];
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            minCost[i][j] = (i == j) ? 0 : INF;
        }
    }

    // Initialize costs from given transformations
    for (int i = 0; i < costSize; i++) {
        int from = original[i] - 'a';
        int to = changed[i] - 'a';
        minCost[from][to] = MIN(minCost[from][to], cost[i]);
    }

    // Floyd-Warshall algorithm
    for (int k = 0; k < 26; k++) {
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                minCost[i][j] = MIN(minCost[i][j], minCost[i][k] + minCost[k][j]);
            }
        }
    }

    long long totalCost = 0;
    int len = strlen(source);
    for (int i = 0; i < len; i++) {
        int from = source[i] - 'a';
        int to = target[i] - 'a';
        if (from != to) {
            if (minCost[from][to] == INF) {
                return -1; // Impossible to convert
            }
            totalCost += minCost[from][to];
        }
    }

    return totalCost;
}