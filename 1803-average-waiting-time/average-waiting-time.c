double averageWaitingTime(int** customers, int customersSize, int* customersColSize) {
    double totalWaitingTime = 0;
    int chefAvailableTime = 0;
    
    for (int i = 0; i < customersSize; i++) {
        int arrivalTime = customers[i][0];
        int prepTime = customers[i][1];
        
        // Time chef starts preparing this order
        int startTime = (chefAvailableTime > arrivalTime) ? chefAvailableTime : arrivalTime;
        
        // Waiting time for this customer
        int waitingTime = startTime - arrivalTime + prepTime;
        
        // Update total waiting time
        totalWaitingTime += waitingTime;
        
        // Update chef's available time
        chefAvailableTime = startTime + prepTime;
    }
    
    // Calculate average waiting time
    return totalWaitingTime / customersSize;
}