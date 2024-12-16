import java.util.PriorityQueue;

class Solution {
    public double maxAverageRatio(int[][] classes, int extraStudents) {
        // Create a max heap based on the potential improvement of pass ratio
        PriorityQueue<double[]> pq = new PriorityQueue<>((a, b) -> {
            double diffA = calculateImprovement(a[0], a[1]);
            double diffB = calculateImprovement(b[0], b[1]);
            return Double.compare(diffB, diffA);
        });
        
        // Add all classes to the priority queue
        for (int[] cls : classes) {
            pq.offer(new double[]{cls[0], cls[1]});
        }
        
        // Distribute extra students to maximize pass ratio
        for (int i = 0; i < extraStudents; i++) {
            double[] top = pq.poll();
            top[0]++; // Add a passing student
            top[1]++; // Increase total students
            pq.offer(top);
        }
        
        // Calculate average pass ratio
        double totalPassRatio = 0;
        while (!pq.isEmpty()) {
            double[] cls = pq.poll();
            totalPassRatio += cls[0] / cls[1];
        }
        
        return totalPassRatio / classes.length;
    }
    
    // Calculate potential improvement in pass ratio
    private double calculateImprovement(double pass, double total) {
        return (pass + 1) / (total + 1) - pass / total;
    }
}