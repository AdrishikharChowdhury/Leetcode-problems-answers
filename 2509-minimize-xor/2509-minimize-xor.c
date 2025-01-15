int countSetBits(int n) {
    int count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

int minimizeXor(int num1, int num2) {
    // Count set bits in num2
    int countBits2 = countSetBits(num2);
    
    // Initialize result
    int x = 0;
    
    // First pass: Try to set bits where num1 has set bits
    int remainingBits = countBits2;
    for (int i = 30; i >= 0 && remainingBits > 0; i--) {
        if (num1 & (1 << i)) {
            x |= (1 << i);
            remainingBits--;
        }
    }
    
    // Second pass: If we still need more set bits, set them from right to left
    // where num1 has 0s
    if (remainingBits > 0) {
        for (int i = 0; i < 31 && remainingBits > 0; i++) {
            if (!(num1 & (1 << i)) && !(x & (1 << i))) {
                x |= (1 << i);
                remainingBits--;
            }
        }
    }
    
    return x;
}