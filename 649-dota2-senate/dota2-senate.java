import java.util.LinkedList;
import java.util.Queue;

class Solution {
    public String predictPartyVictory(String senate) {
        Queue<Integer> radiant = new LinkedList<>();
        Queue<Integer> dire = new LinkedList<>();
        int n = senate.length();
        
        // Initialize queues
        for (int i = 0; i < n; i++) {
            if (senate.charAt(i) == 'R') {
                radiant.offer(i);
            } else {
                dire.offer(i);
            }
        }
        
        // Simulate the voting process
        while (!radiant.isEmpty() && !dire.isEmpty()) {
            int r_index = radiant.poll();
            int d_index = dire.poll();
            
            if (r_index < d_index) {
                radiant.offer(r_index + n);
            } else {
                dire.offer(d_index + n);
            }
        }
        
        return radiant.isEmpty() ? "Dire" : "Radiant";
    }
}