bool* isArraySpecial(int* nums, int numsSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
   // Precompute problematic indices
   bool* isProblem = (bool*)malloc((numsSize - 1) * sizeof(bool));
   for (int i = 0; i < numsSize - 1; i++) {
       isProblem[i] = (nums[i] % 2 == nums[i + 1] % 2);
   }
   
   // Precompute prefix sum of problems
   int* prefixSum = (int*)calloc(numsSize, sizeof(int));
   for (int i = 1; i < numsSize; i++) {
       prefixSum[i] = prefixSum[i - 1] + (isProblem[i - 1] ? 1 : 0);
   }
   
   // Process queries
   bool* result = (bool*)malloc(queriesSize * sizeof(bool));
   *returnSize = queriesSize;
   
   for (int i = 0; i < queriesSize; i++) {
       int from = queries[i][0];
       int to = queries[i][1];
       
       // Check if any problem in the range
       result[i] = (prefixSum[to] - prefixSum[from]) == 0;
   }
   
   // Free temporary arrays
   free(isProblem);
   free(prefixSum);
   
   return result;
}