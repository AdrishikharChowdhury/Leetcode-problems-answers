#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_OBSTACLES 10000

static int compareObstacles(const void* a, const void* b) {
    int* aa = (int*)a;
    int* bb = (int*)b;
    if (aa[0] != bb[0]) return aa[0] - bb[0];
    else return aa[1] - bb[1];
}

int robotSim(int* commands, int commandsSize, int** obstacles, int obstaclesSize, int* obstaclesColumnSize) {
    int x = 0, y = 0;
    int direction = 0; // 0 = north, 1 = east, 2 = south, 3 = west
    int maxDistanceSquared = 0;
    int obstacleSet[MAX_OBSTACLES][2];
    int obstacleCount = 0;

    // Store obstacle positions in the obstacleSet
    for (int i = 0; i < obstaclesSize; i++) {
        obstacleSet[obstacleCount][0] = obstacles[i][0];
        obstacleSet[obstacleCount][1] = obstacles[i][1];
        obstacleCount++;
    }

    // Sort the obstacle set by x-coordinate, then y-coordinate
    qsort(obstacleSet, obstacleCount, sizeof(int[2]), compareObstacles);

    for (int i = 0; i < commandsSize; i++) {
        if (commands[i] == -2) {
            direction = (direction + 3) % 4;
        } else if (commands[i] == -1) {
            direction = (direction + 1) % 4;
        } else {
            int dx[] = {0, 1, 0, -1};
            int dy[] = {1, 0, -1, 0};
            int steps = commands[i];
            while (steps > 0) {
                int newX = x + dx[direction];
                int newY = y + dy[direction];

                // Binary search to find the nearest obstacle in the direction of movement
                int left = 0, right = obstacleCount - 1;
                int nearestObstacle = -1;
                while (left <= right) {
                    int mid = (left + right) / 2;
                    if (obstacleSet[mid][0] > newX || (obstacleSet[mid][0] == newX && obstacleSet[mid][1] > newY)) {
                        right = mid - 1;
                    } else {
                        nearestObstacle = mid;
                        left = mid + 1;
                    }
                }

                // Check if the new position is an obstacle
                if (nearestObstacle != -1 && obstacleSet[nearestObstacle][0] == newX && obstacleSet[nearestObstacle][1] == newY) {
                    break;
                }

                x = newX;
                y = newY;
                int distanceSquared = x * x + y * y;
                maxDistanceSquared = (distanceSquared > maxDistanceSquared) ? distanceSquared : maxDistanceSquared;
                steps--;
            }
        }
    }

    return maxDistanceSquared;
}