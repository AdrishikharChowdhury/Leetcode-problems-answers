#include <stdlib.h>
#include <string.h>
#include <limits.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int findMinDifference(char** timePoints, int timePointsSize) {
    int minutes[timePointsSize];
    
    // Convert all times to minutes since midnight
    for (int i = 0; i < timePointsSize; i++) {
        int hour = (timePoints[i][0] - '0') * 10 + (timePoints[i][1] - '0');
        int minute = (timePoints[i][3] - '0') * 10 + (timePoints[i][4] - '0');
        minutes[i] = hour * 60 + minute;
    }
    
    // Sort the minutes
    qsort(minutes, timePointsSize, sizeof(int), compare);
    
    int minDiff = INT_MAX;
    
    // Compare adjacent times
    for (int i = 1; i < timePointsSize; i++) {
        int diff = minutes[i] - minutes[i-1];
        if (diff < minDiff) {
            minDiff = diff;
        }
    }
    
    // Check wrap-around case (between last and first time)
    int wrapAroundDiff = (minutes[0] + 1440) - minutes[timePointsSize - 1];
    if (wrapAroundDiff < minDiff) {
        minDiff = wrapAroundDiff;
    }
    
    return minDiff;
}