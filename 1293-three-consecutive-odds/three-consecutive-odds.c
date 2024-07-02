bool threeConsecutiveOdds(int* arr, int arrSize) {
    int i,count=0;
    for (i = 0; i < arrSize; i++) {
        if (arr[i] % 2 != 0) {
            count++;
            if (count == 3)
            {
                return true;
            }
        } 
        else
            count = 0; // Reset the counter if the current number is not odd
    }
    return false;
}