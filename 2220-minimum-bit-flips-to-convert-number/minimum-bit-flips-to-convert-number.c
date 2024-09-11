int minBitFlips(int start, int goal) {
    // XOR the start and goal numbers
    int xor_result = start ^ goal;
    
    // Count the number of set bits in the XOR result
    int count = 0;
    while (xor_result) {
        count += xor_result & 1;
        xor_result >>= 1;
    }
    
    return count;
}