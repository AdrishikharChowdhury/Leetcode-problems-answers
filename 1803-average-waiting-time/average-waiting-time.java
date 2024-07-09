class Solution {
    public double averageWaitingTime(int[][] customers) {
        double totalWaitingTime = 0;
        int chefAvailableTime = 0;
        
        for (int[] customer : customers) {
            int arrivalTime = customer[0];
            int prepTime = customer[1];
            
            // Time chef starts preparing this order
            int startTime = Math.max(chefAvailableTime, arrivalTime);
            
            // Waiting time for this customer
            int waitingTime = startTime - arrivalTime + prepTime;
            
            // Update total waiting time
            totalWaitingTime += waitingTime;
            
            // Update chef's available time
            chefAvailableTime = startTime + prepTime;
        }
        
        // Calculate average waiting time
        return totalWaitingTime / customers.length;
    }
}