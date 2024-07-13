import java.util.*;

class Solution {
    public List<Integer> survivedRobotsHealths(int[] positions, int[] healths, String directions) {
        int n = positions.length;
        Integer[] indices = new Integer[n];
        for (int i = 0; i < n; i++) indices[i] = i;
        
        // Sort indices based on positions
        Arrays.sort(indices, (a, b) -> positions[a] - positions[b]);
        
        Stack<Integer> stack = new Stack<>();
        
        for (int i : indices) {
            if (directions.charAt(i) == 'R') {
                stack.push(i);
            } else {
                while (!stack.isEmpty() && healths[i] > 0) {
                    int j = stack.peek();
                    if (healths[j] < healths[i]) {
                        healths[j] = 0;
                        stack.pop();
                        healths[i]--;
                    } else if (healths[j] > healths[i]) {
                        healths[i] = 0;
                        healths[j]--;
                        break;
                    } else {
                        healths[i] = healths[j] = 0;
                        stack.pop();
                        break;
                    }
                }
            }
        }
        
        List<Integer> result = new ArrayList<>();
        for (int health : healths) {
            if (health > 0) {
                result.add(health);
            }
        }
        
        return result;
    }
}