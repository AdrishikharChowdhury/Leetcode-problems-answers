#define MAX_N 10001
int secondMinimum(int n, int** edges, int edgesSize, int* edgesColSize, int time, int change) {
    int* graph[MAX_N] = {0};
    int graphSize[MAX_N] = {0};
    
    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0], v = edges[i][1];
        graph[u] = realloc(graph[u], (graphSize[u] + 1) * sizeof(int));
        graph[v] = realloc(graph[v], (graphSize[v] + 1) * sizeof(int));
        graph[u][graphSize[u]++] = v;
        graph[v][graphSize[v]++] = u;
    }
    
    int dist[MAX_N][2];
    for (int i = 1; i <= n; i++) {
        dist[i][0] = dist[i][1] = INT_MAX;
    }
    
    typedef struct {
        int node;
        int time;
    } QueueNode;

    typedef struct {
        QueueNode* arr;
        int front;
        int rear;
        int size;
        int capacity;
    } Queue;

    Queue* createQueue(int capacity) {
        Queue* queue = (Queue*)malloc(sizeof(Queue));
        queue->arr = (QueueNode*)malloc(capacity * sizeof(QueueNode));
        queue->front = queue->rear = -1;
        queue->size = 0;
        queue->capacity = capacity;
        return queue;
    }

    void enqueue(Queue* queue, int node, int time) {
        if (queue->size == queue->capacity) return;
        queue->rear = (queue->rear + 1) % queue->capacity;
        queue->arr[queue->rear].node = node;
        queue->arr[queue->rear].time = time;
        if (queue->front == -1) queue->front = queue->rear;
        queue->size++;
    }

    QueueNode dequeue(Queue* queue) {
        QueueNode node = queue->arr[queue->front];
        if (queue->front == queue->rear) {
            queue->front = queue->rear = -1;
        } else {
            queue->front = (queue->front + 1) % queue->capacity;
        }
        queue->size--;
        return node;
    }

    Queue* queue = createQueue(MAX_N * 2);
    enqueue(queue, 1, 0);
    dist[1][0] = 0;
    
    while (queue->size > 0) {
        QueueNode node = dequeue(queue);
        int u = node.node, t = node.time;
        
        if (u == n && t > dist[n][0]) return t;
        
        int wait = ((t / change) % 2 == 0) ? 0 : change - (t % change);
        int newTime = t + wait + time;
        
        for (int i = 0; i < graphSize[u]; i++) {
            int v = graph[u][i];
            if (newTime < dist[v][0]) {
                dist[v][1] = dist[v][0];
                dist[v][0] = newTime;
                enqueue(queue, v, newTime);
            } else if (newTime > dist[v][0] && newTime < dist[v][1]) {
                dist[v][1] = newTime;
                enqueue(queue, v, newTime);
            }
        }
    }
    
    return -1;
}