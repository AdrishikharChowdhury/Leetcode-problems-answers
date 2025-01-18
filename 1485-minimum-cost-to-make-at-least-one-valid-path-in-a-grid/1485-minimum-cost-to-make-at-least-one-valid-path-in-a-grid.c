#define MAX_NODES 10000
#define INF 1000000000

struct Node {
    int row;
    int col;
    int cost;
};

// Priority Queue implementation
struct PriorityQueue {
    struct Node* nodes;
    int size;
};

void swap(struct Node* a, struct Node* b) {
    struct Node temp = *a;
    *a = *b;
    *b = temp;
}

void push(struct PriorityQueue* pq, struct Node node) {
    int curr = pq->size++;
    pq->nodes[curr] = node;
    
    // Bubble up
    while (curr > 0) {
        int parent = (curr - 1) / 2;
        if (pq->nodes[parent].cost <= pq->nodes[curr].cost) break;
        swap(&pq->nodes[curr], &pq->nodes[parent]);
        curr = parent;
    }
}

struct Node pop(struct PriorityQueue* pq) {
    struct Node result = pq->nodes[0];
    pq->nodes[0] = pq->nodes[--pq->size];
    
    // Bubble down
    int curr = 0;
    while (true) {
        int smallest = curr;
        int left = 2 * curr + 1;
        int right = 2 * curr + 2;
        
        if (left < pq->size && pq->nodes[left].cost < pq->nodes[smallest].cost)
            smallest = left;
        if (right < pq->size && pq->nodes[right].cost < pq->nodes[smallest].cost)
            smallest = right;
        
        if (smallest == curr) break;
        swap(&pq->nodes[curr], &pq->nodes[smallest]);
        curr = smallest;
    }
    
    return result;
}

int minCost(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize;
    int n = gridColSize[0];
    const int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}; // right, left, down, up
    
    // Initialize cost array
    int** cost = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        cost[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            cost[i][j] = INF;
        }
    }
    cost[0][0] = 0;
    
    // Initialize priority queue
    struct PriorityQueue pq;
    pq.nodes = (struct Node*)malloc(MAX_NODES * sizeof(struct Node));
    pq.size = 0;
    
    struct Node start = {0, 0, 0};
    push(&pq, start);
    
    while (pq.size > 0) {
        struct Node curr = pop(&pq);
        
        if (curr.cost > cost[curr.row][curr.col]) continue;
        
        // Try all directions
        for (int i = 0; i < 4; i++) {
            int newRow = curr.row + directions[i][0];
            int newCol = curr.col + directions[i][1];
            
            if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n) {
                int newCost = curr.cost + (grid[curr.row][curr.col] == i + 1 ? 0 : 1);
                
                if (newCost < cost[newRow][newCol]) {
                    cost[newRow][newCol] = newCost;
                    struct Node next = {newRow, newCol, newCost};
                    push(&pq, next);
                }
            }
        }
    }
    
    int result = cost[m-1][n-1];
    
    // Free allocated memory
    free(pq.nodes);
    for (int i = 0; i < m; i++) {
        free(cost[i]);
    }
    free(cost);
    
    return result;
}