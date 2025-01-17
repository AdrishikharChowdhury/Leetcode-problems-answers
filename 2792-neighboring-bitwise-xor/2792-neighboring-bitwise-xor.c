bool doesValidArrayExist(int* derived, int derivedSize) {
    // For the array to be valid, XOR of all elements must be 0
    // because original[0] ⊕ original[1] ⊕ original[1] ⊕ original[2] ⊕ ... ⊕ original[n-1] ⊕ original[0] = 0
    int xorSum = 0;
    for (int i = 0; i < derivedSize; i++) {
        xorSum ^= derived[i];
    }
    
    return xorSum == 0;
}