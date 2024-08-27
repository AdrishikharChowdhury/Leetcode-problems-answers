#include <stdlib.h>
#include <string.h>

#define MAX_NODES 10000

typedef struct {
    int node;
    double prob;
} Pair;

typedef struct {
    Pair* data;
    int size;
    int capacity;
} PriorityQueue;

void swap(Pair* a, Pair* b) {
    Pair temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(PriorityQueue* pq, int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (pq->data[parent].prob < pq->data[index].prob) {
            swap(&pq->data[parent], &pq->data[index]);
            index = parent;
        } else {
            break;
        }
    }
}

void heapifyDown(PriorityQueue* pq, int index) {
    while (1) {
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < pq->size && pq->data[left].prob > pq->data[largest].prob) {
            largest = left;
        }
        if (right < pq->size && pq->data[right].prob > pq->data[largest].prob) {
            largest = right;
        }

        if (largest != index) {
            swap(&pq->data[index], &pq->data[largest]);
            index = largest;
        } else {
            break;
        }
    }
}

void pqOffer(PriorityQueue* pq, Pair pair) {
    if (pq->size == pq->capacity) {
        pq->capacity *= 2;
        pq->data = realloc(pq->data, pq->capacity * sizeof(Pair));
    }
    pq->data[pq->size] = pair;
    heapifyUp(pq, pq->size);
    pq->size++;
}

Pair pqPoll(PriorityQueue* pq) {
    Pair result = pq->data[0];
    pq->size--;
    pq->data[0] = pq->data[pq->size];
    heapifyDown(pq, 0);
    return result;
}

double maxProbability(int n, int** edges, int edgesSize, int* edgesColSize, double* succProb, int succProbSize, int start, int end) {
    // Create adjacency list
    Pair* adj[MAX_NODES] = {NULL};
    int adjSize[MAX_NODES] = {0};
    int adjCapacity[MAX_NODES] = {0};

    for (int i = 0; i < edgesSize; i++) {
        int a = edges[i][0], b = edges[i][1];
        double prob = succProb[i];

        if (adjSize[a] == adjCapacity[a]) {
            adjCapacity[a] = adjCapacity[a] == 0 ? 1 : adjCapacity[a] * 2;
            adj[a] = realloc(adj[a], adjCapacity[a] * sizeof(Pair));
        }
        adj[a][adjSize[a]++] = (Pair){b, prob};

        if (adjSize[b] == adjCapacity[b]) {
            adjCapacity[b] = adjCapacity[b] == 0 ? 1 : adjCapacity[b] * 2;
            adj[b] = realloc(adj[b], adjCapacity[b] * sizeof(Pair));
        }
        adj[b][adjSize[b]++] = (Pair){a, prob};
    }

    // Dijkstra's algorithm
    double maxProb[MAX_NODES] = {0};
    maxProb[start] = 1.0;

    PriorityQueue pq = {malloc(sizeof(Pair)), 0, 1};
    pqOffer(&pq, (Pair){start, 1.0});

    while (pq.size > 0) {
        Pair curr = pqPoll(&pq);
        int node = curr.node;
        double prob = curr.prob;

        if (node == end) return prob;

        if (prob < maxProb[node]) continue;

        for (int i = 0; i < adjSize[node]; i++) {
            Pair neighbor = adj[node][i];
            int nextNode = neighbor.node;
            double newProb = prob * neighbor.prob;
            if (newProb > maxProb[nextNode]) {
                maxProb[nextNode] = newProb;
                pqOffer(&pq, (Pair){nextNode, newProb});
            }
        }
    }

    // Free allocated memory
    for (int i = 0; i < n; i++) {
        free(adj[i]);
    }
    free(pq.data);

    return 0.0;
}