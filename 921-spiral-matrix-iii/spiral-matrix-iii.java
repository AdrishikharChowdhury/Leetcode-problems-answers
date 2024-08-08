class Solution {
    public int[][] spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
    int totalCells = rows * cols;
    int[][] result = new int[totalCells][2];
    
    int[][] directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int x = rStart, y = cStart, count = 0;
    int directionIndex = 0, steps = 1;

    while (count < totalCells) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < steps; j++) {
                if (x >= 0 && x < rows && y >= 0 && y < cols) {
                    result[count][0] = x;
                    result[count][1] = y;
                    count++;
                    if (count == totalCells) {
                        return result;
                    }
                }
                x += directions[directionIndex][0];
                y += directions[directionIndex][1];
            }
            directionIndex = (directionIndex + 1) % 4;
        }
        steps++;
    }

    return result;
}

}