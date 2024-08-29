#define MAX_STONES 1000

int parent[MAX_STONES];

int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void unionSets(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX != rootY) {
        parent[rootX] = rootY;
    }
}

int removeStones(int** stones, int stonesSize, int* stonesColSize) {
    for (int i = 0; i < stonesSize; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < stonesSize; i++) {
        for (int j = i + 1; j < stonesSize; j++) {
            if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                unionSets(i, j);
            }
        }
    }

    int groups = 0;
    for (int i = 0; i < stonesSize; i++) {
        if (parent[i] == i) {
            groups++;
        }
    }

    return stonesSize - groups;
}