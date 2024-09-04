import java.util.HashSet;
import java.util.Set;

class Solution {
    public int robotSim(int[] commands, int[][] obstacles) {
        int x = 0, y = 0;
        int direction = 0; // 0 = north, 1 = east, 2 = south, 3 = west
        int maxDistanceSquared = 0;
        Set<String> obstacleSet = new HashSet<>();
        
        for (int[] obstacle : obstacles) {
            obstacleSet.add(obstacle[0] + "," + obstacle[1]);
        }
        
        for (int command : commands) {
            if (command == -2) {
                direction = (direction + 3) % 4;
            } else if (command == -1) {
                direction = (direction + 1) % 4;
            } else {
                for (int i = 0; i < command; i++) {
                    int newX = x, newY = y;
                    if (direction == 0) {
                        newY++;
                    } else if (direction == 1) {
                        newX++;
                    } else if (direction == 2) {
                        newY--;
                    } else {
                        newX--;
                    }
                    
                    if (obstacleSet.contains(newX + "," + newY)) {
                        break;
                    }
                    
                    x = newX;
                    y = newY;
                    maxDistanceSquared = Math.max(maxDistanceSquared, x * x + y * y);
                }
            }
        }
        
        return maxDistanceSquared;
    }
}