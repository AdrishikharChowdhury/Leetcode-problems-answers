#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int* array;
    int front;
    int rear;
    int size;
    int capacity;
} MyCircularDeque;

// Function prototypes
MyCircularDeque* myCircularDequeCreate(int k);
bool myCircularDequeInsertFront(MyCircularDeque* obj, int value);
bool myCircularDequeInsertLast(MyCircularDeque* obj, int value);
bool myCircularDequeDeleteFront(MyCircularDeque* obj);
bool myCircularDequeDeleteLast(MyCircularDeque* obj);
int myCircularDequeGetFront(MyCircularDeque* obj);
int myCircularDequeGetRear(MyCircularDeque* obj);
bool myCircularDequeIsEmpty(MyCircularDeque* obj);
bool myCircularDequeIsFull(MyCircularDeque* obj);
void myCircularDequeFree(MyCircularDeque* obj);

// Function implementations
MyCircularDeque* myCircularDequeCreate(int k) {
    MyCircularDeque* obj = (MyCircularDeque*)malloc(sizeof(MyCircularDeque));
    obj->array = (int*)malloc(k * sizeof(int));
    obj->front = -1;
    obj->rear = -1;
    obj->size = 0;
    obj->capacity = k;
    return obj;
}

bool myCircularDequeIsEmpty(MyCircularDeque* obj) {
    return obj->size == 0;
}

bool myCircularDequeIsFull(MyCircularDeque* obj) {
    return obj->size == obj->capacity;
}

bool myCircularDequeInsertFront(MyCircularDeque* obj, int value) {
    if (myCircularDequeIsFull(obj)) return false;
    if (obj->front == -1) {
        obj->front = obj->rear = 0;
    } else if (obj->front == 0) {
        obj->front = obj->capacity - 1;
    } else {
        obj->front--;
    }
    obj->array[obj->front] = value;
    obj->size++;
    return true;
}

bool myCircularDequeInsertLast(MyCircularDeque* obj, int value) {
    if (myCircularDequeIsFull(obj)) return false;
    if (obj->front == -1) {
        obj->front = obj->rear = 0;
    } else if (obj->rear == obj->capacity - 1) {
        obj->rear = 0;
    } else {
        obj->rear++;
    }
    obj->array[obj->rear] = value;
    obj->size++;
    return true;
}

bool myCircularDequeDeleteFront(MyCircularDeque* obj) {
    if (myCircularDequeIsEmpty(obj)) return false;
    if (obj->front == obj->rear) {
        obj->front = obj->rear = -1;
    } else if (obj->front == obj->capacity - 1) {
        obj->front = 0;
    } else {
        obj->front++;
    }
    obj->size--;
    return true;
}

bool myCircularDequeDeleteLast(MyCircularDeque* obj) {
    if (myCircularDequeIsEmpty(obj)) return false;
    if (obj->front == obj->rear) {
        obj->front = obj->rear = -1;
    } else if (obj->rear == 0) {
        obj->rear = obj->capacity - 1;
    } else {
        obj->rear--;
    }
    obj->size--;
    return true;
}

int myCircularDequeGetFront(MyCircularDeque* obj) {
    if (myCircularDequeIsEmpty(obj)) return -1;
    return obj->array[obj->front];
}

int myCircularDequeGetRear(MyCircularDeque* obj) {
    if (myCircularDequeIsEmpty(obj)) return -1;
    return obj->array[obj->rear];
}

void myCircularDequeFree(MyCircularDeque* obj) {
    free(obj->array);
    free(obj);
}