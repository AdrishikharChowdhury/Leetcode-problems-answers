/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define MAX_K 500

int** buildMatrix(int k, int** rowConditions, int rowConditionsSize, int* rowConditionsColSize, 
                  int** colConditions, int colConditionsSize, int* colConditionsColSize, 
                  int* returnSize, int** returnColumnSizes) {
    int graph[MAX_K + 1][MAX_K + 1] = {0};
    int inDegree[MAX_K + 1] = {0};
    int queue[MAX_K + 1], front = 0, rear = 0;
    int order[MAX_K + 1], orderSize = 0;
    
    int** result = malloc(k * sizeof(int*));
    for (int i = 0; i < k; i++) {
        result[i] = calloc(k, sizeof(int));
    }
    *returnSize = k;
    *returnColumnSizes = malloc(k * sizeof(int));
    for (int i = 0; i < k; i++) {
        (*returnColumnSizes)[i] = k;
    }
    
    int topologicalSort(int** conditions, int conditionsSize) {
        memset(graph, 0, sizeof(graph));
        memset(inDegree, 0, sizeof(inDegree));
        front = rear = orderSize = 0;
        
        for (int i = 0; i < conditionsSize; i++) {
            int from = conditions[i][0], to = conditions[i][1];
            if (!graph[from][to]) {
                graph[from][to] = 1;
                inDegree[to]++;
            }
        }
        
        for (int i = 1; i <= k; i++) {
            if (inDegree[i] == 0) {
                queue[rear++] = i;
            }
        }
        
        while (front < rear) {
            int node = queue[front++];
            order[orderSize++] = node;
            for (int i = 1; i <= k; i++) {
                if (graph[node][i] && --inDegree[i] == 0) {
                    queue[rear++] = i;
                }
            }
        }
        
        return orderSize == k;
    }
    
    if (!topologicalSort(rowConditions, rowConditionsSize) || 
        !topologicalSort(colConditions, colConditionsSize)) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }
    
    int colPosition[MAX_K + 1];
    for (int i = 0; i < k; i++) {
        colPosition[order[i]] = i;
    }
    
    memset(order, 0, sizeof(order));
    orderSize = 0;
    if (!topologicalSort(rowConditions, rowConditionsSize)) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }
    
    for (int i = 0; i < k; i++) {
        int num = order[i];
        result[i][colPosition[num]] = num;
    }
    
    return result;
}