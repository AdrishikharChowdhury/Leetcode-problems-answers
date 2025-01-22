// Structure for queue node
typedef struct QNode {
    int row;
    int col;
    struct QNode* next;
} QNode;

// Structure for queue
typedef struct Queue {
    QNode *front, *rear;
} Queue;

// Create a new queue node
QNode* newNode(int row, int col) {
    QNode* temp = (QNode*)malloc(sizeof(QNode));
    temp->row = row;
    temp->col = col;
    temp->next = NULL;
    return temp;
}

// Create empty queue
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

// Add to queue
void enQueue(Queue* q, int row, int col) {
    QNode* temp = newNode(row, col);
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

// Remove from queue
void deQueue(Queue* q, int* row, int* col) {
    if (q->front == NULL) return;
    QNode* temp = q->front;
    *row = temp->row;
    *col = temp->col;
    q->front = temp->next;
    if (q->front == NULL) q->rear = NULL;
    free(temp);
}

// Check if queue is empty
int isEmpty(Queue* q) {
    return q->front == NULL;
}

// Free queue memory
void freeQueue(Queue* q) {
    while (!isEmpty(q)) {
        int r, c;
        deQueue(q, &r, &c);
    }
    free(q);
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** highestPeak(int** isWater, int isWaterSize, int* isWaterColSize, int* returnSize, int** returnColumnSizes) {
    int m = isWaterSize;
    int n = isWaterColSize[0];
    
    // Allocate memory for result
    int** heights = (int**)malloc(m * sizeof(int*));
    *returnColumnSizes = (int*)malloc(m * sizeof(int));
    for (int i = 0; i < m; i++) {
        heights[i] = (int*)malloc(n * sizeof(int));
        (*returnColumnSizes)[i] = n;
    }
    *returnSize = m;
    
    // Create and initialize queue
    Queue* q = createQueue();
    
    // Initialize heights array and queue
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (isWater[i][j] == 1) {
                heights[i][j] = 0;
                enQueue(q, i, j);
            } else {
                heights[i][j] = -1; // Unvisited
            }
        }
    }
    
    // Directions for adjacent cells
    int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    
    // BFS to assign heights
    while (!isEmpty(q)) {
        int row, col;
        deQueue(q, &row, &col);
        
        // Check all adjacent cells
        for (int d = 0; d < 4; d++) {
            int newRow = row + dirs[d][0];
            int newCol = col + dirs[d][1];
            
            // Check if within bounds and unvisited
            if (newRow >= 0 && newRow < m && 
                newCol >= 0 && newCol < n && 
                heights[newRow][newCol] == -1) {
                
                heights[newRow][newCol] = heights[row][col] + 1;
                enQueue(q, newRow, newCol);
            }
        }
    }
    
    // Free queue memory
    freeQueue(q);
    
    return heights;
}