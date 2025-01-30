#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Graph node structure for adjacency list
struct Node {
    int vertex;
    struct Node* next;
};

// Graph structure
struct Graph {
    int numVertices;
    struct Node** adjLists;
};

// Queue structure for BFS
struct Queue {
    int front, rear, size;
    unsigned capacity;
    int* array;
};

// Create a new graph node
struct Node* createNode(int v) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Create a graph with n vertices
struct Graph* createGraph(int n) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = n;
    graph->adjLists = malloc((n + 1) * sizeof(struct Node*));
    
    for (int i = 0; i <= n; i++) {
        graph->adjLists[i] = NULL;
    }
    return graph;
}

// Add edge to graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Add edge from src to dest
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
    
    // Add edge from dest to src
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Create a queue
struct Queue* createQueue(unsigned capacity) {
    struct Queue* queue = malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = malloc(capacity * sizeof(int));
    return queue;
}

// Queue operations
int isFull(struct Queue* queue) {
    return (queue->size == queue->capacity);
}

int isEmpty(struct Queue* queue) {
    return (queue->size == 0);
}

void enqueue(struct Queue* queue, int item) {
    if (isFull(queue)) return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
}

int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) return -1;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

// BFS to find maximum groups from a start node
int bfs(struct Graph* graph, int start, int* distance, int n) {
    struct Queue* queue = createQueue(n + 1);
    memset(distance, -1, (n + 1) * sizeof(int));
    int maxGroup = 1;
    
    enqueue(queue, start);
    distance[start] = 1;
    
    while (!isEmpty(queue)) {
        int curr = dequeue(queue);
        int currGroup = distance[curr];
        maxGroup = currGroup > maxGroup ? currGroup : maxGroup;
        
        struct Node* temp = graph->adjLists[curr];
        while (temp) {
            int neighbor = temp->vertex;
            if (distance[neighbor] == -1) {
                distance[neighbor] = currGroup + 1;
                enqueue(queue, neighbor);
            } else if (abs(distance[neighbor] - currGroup) != 1) {
                free(queue->array);
                free(queue);
                return -1;
            }
            temp = temp->next;
        }
    }
    
    free(queue->array);
    free(queue);
    return maxGroup;
}

// DFS to find connected components
void dfs(struct Graph* graph, int node, int* component, int* componentSize, int* visited) {
    visited[node] = 1;
    component[(*componentSize)++] = node;
    
    struct Node* temp = graph->adjLists[node];
    while (temp) {
        if (!visited[temp->vertex]) {
            dfs(graph, temp->vertex, component, componentSize, visited);
        }
        temp = temp->next;
    }
}

// Main solution function
int magnificentSets(int n, int** edges, int edgesSize, int* edgesColSize) {
    struct Graph* graph = createGraph(n);
    
    // Build graph
    for (int i = 0; i < edgesSize; i++) {
        addEdge(graph, edges[i][0], edges[i][1]);
    }
    
    int* visited = calloc(n + 1, sizeof(int));
    int* component = malloc((n + 1) * sizeof(int));
    int* distance = malloc((n + 1) * sizeof(int));
    int result = 0;
    
    // Process each connected component
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            int componentSize = 0;
            dfs(graph, i, component, &componentSize, visited);
            
            // Find maximum groups for current component
            int maxGroups = -1;
            for (int j = 0; j < componentSize; j++) {
                int groups = bfs(graph, component[j], distance, n);
                if (groups == -1) {
                    // Clean up and return -1 if impossible
                    free(visited);
                    free(component);
                    free(distance);
                    // Free graph
                    for (int k = 0; k <= n; k++) {
                        struct Node* current = graph->adjLists[k];
                        while (current) {
                            struct Node* temp = current;
                            current = current->next;
                            free(temp);
                        }
                    }
                    free(graph->adjLists);
                    free(graph);
                    return -1;
                }
                maxGroups = groups > maxGroups ? groups : maxGroups;
            }
            result += maxGroups;
        }
    }
    
    // Clean up
    free(visited);
    free(component);
    free(distance);
    // Free graph
    for (int i = 0; i <= n; i++) {
        struct Node* current = graph->adjLists[i];
        while (current) {
            struct Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(graph->adjLists);
    free(graph);
    
    return result;
}