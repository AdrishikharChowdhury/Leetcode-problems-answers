#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10

typedef struct {
    int row;
    int col;
} Point;

typedef struct {
    Point* array;
    int front;
    int rear;
    int size;
} Queue;

Queue* createQueue(int size) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->array = (Point*)malloc(size * sizeof(Point));
    queue->front = queue->rear = -1;
    queue->size = size;
    return queue;
}

int isEmpty(Queue* queue) {
    return queue->front == -1;
}

void enqueue(Queue* queue, Point point) {
    if (queue->rear == queue->size - 1) return;
    if (isEmpty(queue)) queue->front = 0;
    queue->rear++;
    queue->array[queue->rear] = point;
}

Point dequeue(Queue* queue) {
    Point point = queue->array[queue->front];
    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1;
    } else {
        queue->front++;
    }
    return point;
}

int orangesRotting(int** grid, int gridSize, int* gridColSize) {
    int rows = gridSize, cols = gridColSize[0];
    Queue* queue = createQueue(rows * cols);
    int freshOranges = 0;
    
    // Find all rotten oranges and count fresh oranges
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 2) {
                Point p = {i, j};
                enqueue(queue, p);
            } else if (grid[i][j] == 1) {
                freshOranges++;
            }
        }
    }
    
    // If there are no fresh oranges, return 0
    if (freshOranges == 0) {
        free(queue->array);
        free(queue);
        return 0;
    }
    
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // Up, Down, Left, Right
    int minutes = 0;
    
    // BFS to rot oranges
    while (!isEmpty(queue) && freshOranges > 0) {
        int size = queue->rear - queue->front + 1;
        for (int i = 0; i < size; i++) {
            Point point = dequeue(queue);
            for (int d = 0; d < 4; d++) {
                int x = point.row + directions[d][0];
                int y = point.col + directions[d][1];
                if (x < 0 || y < 0 || x >= rows || y >= cols || grid[x][y] != 1) continue;
                grid[x][y] = 2;
                Point newPoint = {x, y};
                enqueue(queue, newPoint);
                freshOranges--;
            }
        }
        minutes++;
    }
    
    free(queue->array);
    free(queue);
    return freshOranges == 0 ? minutes : -1;
}