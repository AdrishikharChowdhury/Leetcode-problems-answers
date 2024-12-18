int* finalPrices(int* prices, int pricesSize, int* returnSize) {
    // Allocate memory for result
    int* answer = (int*)malloc(pricesSize * sizeof(int));
    *returnSize = pricesSize;
    
    for (int i = 0; i < pricesSize; i++) {
        // Initialize with original price
        answer[i] = prices[i];
        
        // Look for discount in subsequent elements
        for (int j = i + 1; j < pricesSize; j++) {
            if (prices[j] <= prices[i]) {
                answer[i] -= prices[j];
                break;
            }
        }
    }
    
    return answer;
}