#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(a) ((a) < 0 ? -(a) : (a))

int maxDistance(int** arrays, int arraysSize, int* arraysColSize) {
    int result = 0;
    int min = arrays[0][0];
    int max = arrays[0][arraysColSize[0] - 1];
    
    for (int i = 1; i < arraysSize; i++) {
        result = MAX(result, MAX(ABS(arrays[i][arraysColSize[i] - 1] - min),
                                 ABS(max - arrays[i][0])));
        min = MIN(min, arrays[i][0]);
        max = MAX(max, arrays[i][arraysColSize[i] - 1]);
    }
    
    return result;
}