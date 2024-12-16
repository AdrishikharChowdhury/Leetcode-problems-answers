#define MAX_CLASSES 10000

typedef struct {
    double improvement;
    int pass;
    int total;
} HeapNode;

typedef struct {
    HeapNode* heap;
    int size;
} PriorityQueue;

// Calculate potential improvement when adding a student
double calculateImprovement(int pass, int total) {
    return (double)(pass + 1) / (total + 1) - (double)pass / total;
}

// Initialize priority queue
void initPQ(PriorityQueue* pq, int** classes, int classesSize) {
    pq->heap = malloc(sizeof(HeapNode) * (classesSize + 1));
    pq->size = classesSize;
    
    for (int i = 0; i < classesSize; i++) {
        pq->heap[i + 1].pass = classes[i][0];
        pq->heap[i + 1].total = classes[i][1];
        pq->heap[i + 1].improvement = calculateImprovement(classes[i][0], classes[i][1]);
    }
    
    // Heapify
    for (int i = classesSize / 2; i >= 1; i--) {
        int parent = i;
        HeapNode temp = pq->heap[parent];
        int child;
        
        while ((child = parent * 2) <= pq->size) {
            if (child < pq->size && 
                pq->heap[child + 1].improvement > pq->heap[child].improvement) {
                child++;
            }
            
            if (temp.improvement >= pq->heap[child].improvement) break;
            
            pq->heap[parent] = pq->heap[child];
            parent = child;
        }
        
        pq->heap[parent] = temp;
    }
}

// Extract max improvement class
HeapNode extractMax(PriorityQueue* pq) {
    HeapNode max = pq->heap[1];
    pq->heap[1] = pq->heap[pq->size];
    pq->size--;
    
    int parent = 1;
    HeapNode temp = pq->heap[parent];
    int child;
    
    while ((child = parent * 2) <= pq->size) {
        if (child < pq->size && 
            pq->heap[child + 1].improvement > pq->heap[child].improvement) {
            child++;
        }
        
        if (temp.improvement >= pq->heap[child].improvement) break;
        
        pq->heap[parent] = pq->heap[child];
        parent = child;
    }
    
    pq->heap[parent] = temp;
    
    return max;
}

// Insert a node back into the heap
void insert(PriorityQueue* pq, HeapNode node) {
    pq->size++;
    int i = pq->size;
    
    while (i > 1 && node.improvement > pq->heap[i/2].improvement) {
        pq->heap[i] = pq->heap[i/2];
        i /= 2;
    }
    
    pq->heap[i] = node;
}

double maxAverageRatio(int** classes, int classesSize, int* classesColSize, int extraStudents) {
    // Create and initialize priority queue
    PriorityQueue pq;
    initPQ(&pq, classes, classesSize);
    
    // Distribute extra students
    for (int i = 0; i < extraStudents; i++) {
        HeapNode maxClass = extractMax(&pq);
        
        // Add a student
        maxClass.pass++;
        maxClass.total++;
        maxClass.improvement = calculateImprovement(maxClass.pass, maxClass.total);
        
        // Reinsert into heap
        insert(&pq, maxClass);
    }
    
    // Calculate average pass ratio
    double totalPassRatio = 0.0;
    for (int i = 1; i <= pq.size; i++) {
        totalPassRatio += (double)pq.heap[i].pass / pq.heap[i].total;
    }
    
    // Free memory and return result
    free(pq.heap);
    return totalPassRatio / classesSize;
}