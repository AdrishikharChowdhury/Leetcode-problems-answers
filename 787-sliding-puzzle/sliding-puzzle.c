#define MAX_STATES 720  // 6! possible states
#define BOARD_SIZE 6

// Structure to store board state
typedef struct {
    char board[BOARD_SIZE + 1];
    int steps;
} State;

// Queue implementation
typedef struct {
    State states[MAX_STATES];
    int front, rear;
} Queue;

void initQueue(Queue* q) {
    q->front = q->rear = 0;
}

void enqueue(Queue* q, State state) {
    q->states[q->rear++] = state;
}

State dequeue(Queue* q) {
    return q->states[q->front++];
}

bool isQueueEmpty(Queue* q) {
    return q->front == q->rear;
}

// Swap characters in string
void swap(char* str, int i, int j) {
    char temp = str[i];
    str[i] = str[j];
    str[j] = temp;
}

int slidingPuzzle(int** board, int boardSize, int* boardColSize) {
    // Initialize variables
    Queue queue;
    initQueue(&queue);
    bool visited[MAX_STATES] = {false};
    char start[BOARD_SIZE + 1] = "";
    const char* target = "123450";
    
    // Convert board to string
    int idx = 0;
    for(int i = 0; i < boardSize; i++) {
        for(int j = 0; j < boardColSize[i]; j++) {
            start[idx++] = board[i][j] + '0';
        }
    }
    start[idx] = '\0';
    
    // Possible moves for each position
    int moves[6][4] = {
        {1, 3, -1, -1},     // position 0
        {0, 2, 4, -1},      // position 1
        {1, 5, -1, -1},     // position 2
        {0, 4, -1, -1},     // position 3
        {1, 3, 5, -1},      // position 4
        {2, 4, -1, -1}      // position 5
    };
    
    // Initialize start state
    State startState;
    strcpy(startState.board, start);
    startState.steps = 0;
    enqueue(&queue, startState);
    
    // BFS
    while(!isQueueEmpty(&queue)) {
        State current = dequeue(&queue);
        
        if(strcmp(current.board, target) == 0) {
            return current.steps;
        }
        
        // Find position of 0
        int zero;
        for(zero = 0; zero < BOARD_SIZE; zero++) {
            if(current.board[zero] == '0') break;
        }
        
        // Try all possible moves
        for(int i = 0; moves[zero][i] != -1; i++) {
            State next = current;
            swap(next.board, zero, moves[zero][i]);
            
            // Check if this state was visited
            bool found = false;
            for(int j = 0; j < queue.rear; j++) {
                if(strcmp(queue.states[j].board, next.board) == 0) {
                    found = true;
                    break;
                }
            }
            
            if(!found) {
                next.steps = current.steps + 1;
                enqueue(&queue, next);
            }
        }
    }
    
    return -1;
}