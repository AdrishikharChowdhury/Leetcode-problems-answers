bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {
    int count = 0;
    
    for (int i = 0; i < flowerbedSize; i++) {
        if (flowerbed[i] == 0) {
            bool emptyLeft = (i == 0) || (flowerbed[i - 1] == 0);
            bool emptyRight = (i == flowerbedSize - 1) || (flowerbed[i + 1] == 0);           
            if (emptyLeft && emptyRight) {
                flowerbed[i] = 1;
                count++;               
                if (count >= n)
                return true;
            }
        }
    }
    
    return count >= n;
}