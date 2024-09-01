#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VARS 40
#define MAX_EQUATIONS 20
#define MAX_VAR_LEN 5  // Increased from 2 to 5 to accommodate longer variable names

typedef struct {
    char var[MAX_VAR_LEN];
    double value;
} Edge;

typedef struct {
    Edge edges[MAX_VARS];
    int size;
} Node;

Node graph[MAX_VARS];
int graph_size = 0;

int find_var(char* var) {
    for (int i = 0; i < graph_size; i++) {
        if (strcmp(graph[i].edges[0].var, var) == 0) {
            return i;
        }
    }
    return -1;
}

void add_var(char* var) {
    if (find_var(var) == -1 && graph_size < MAX_VARS) {
        strncpy(graph[graph_size].edges[0].var, var, MAX_VAR_LEN - 1);
        graph[graph_size].edges[0].var[MAX_VAR_LEN - 1] = '\0';  // Ensure null-termination
        graph[graph_size].size = 1;
        graph_size++;
    }
}

void add_edge(char* from, char* to, double value) {
    add_var(from);
    add_var(to);
    
    int u = find_var(from);
    int v = find_var(to);
    
    if (u != -1 && v != -1 && graph[u].size < MAX_VARS && graph[v].size < MAX_VARS) {
        strncpy(graph[u].edges[graph[u].size].var, to, MAX_VAR_LEN - 1);
        graph[u].edges[graph[u].size].var[MAX_VAR_LEN - 1] = '\0';
        graph[u].edges[graph[u].size].value = value;
        graph[u].size++;
        
        strncpy(graph[v].edges[graph[v].size].var, from, MAX_VAR_LEN - 1);
        graph[v].edges[graph[v].size].var[MAX_VAR_LEN - 1] = '\0';
        graph[v].edges[graph[v].size].value = 1.0 / value;
        graph[v].size++;
    }
}

double dfs(char* start, char* end, int* visited) {
    int u = find_var(start);
    if (u == -1) return -1.0;
    if (strcmp(start, end) == 0) return 1.0;
    
    visited[u] = 1;
    
    for (int i = 1; i < graph[u].size; i++) {
        int v = find_var(graph[u].edges[i].var);
        if (v != -1 && !visited[v]) {
            double result = dfs(graph[u].edges[i].var, end, visited);
            if (result != -1.0) {
                return result * graph[u].edges[i].value;
            }
        }
    }
    
    return -1.0;
}

double* calcEquation(char*** equations, int equationsSize, int* equationsColSize, double* values, int valuesSize, char*** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    graph_size = 0;
    
    for (int i = 0; i < equationsSize && i < MAX_EQUATIONS; i++) {
        add_edge(equations[i][0], equations[i][1], values[i]);
    }
    
    double* results = (double*)malloc(queriesSize * sizeof(double));
    *returnSize = queriesSize;
    
    for (int i = 0; i < queriesSize; i++) {
        int visited[MAX_VARS] = {0};
        results[i] = dfs(queries[i][0], queries[i][1], visited);
    }
    
    return results;
}