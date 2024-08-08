int** spiralMatrixIII(int rows, int cols, int rStart, int cStart, int* returnSize, int** returnColumnSizes) {
    int totalCells = rows * cols;
    int** result = malloc(totalCells * sizeof(int*));
    int* data = malloc(totalCells * 2 * sizeof(int));
    *returnColumnSizes = malloc(totalCells * sizeof(int));
    *returnSize = totalCells;

    for (int i = 0; i < totalCells; i++) {
        result[i] = &data[i * 2];
        (*returnColumnSizes)[i] = 2;
    }

    int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
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
