class Solution {
public:

    bool searchInRow(vector<vector<int>>& matrix, int target,int midRow){
        int cols=matrix[0].size();
        int startCol=0,midCol,endCol=cols-1,startRow=0;
        while(startCol<=endCol){
            midCol=startCol+((endCol-startCol)/2);
            if(matrix[midRow][midCol]<target){
                startCol=midCol+1;
            }
            else if(matrix[midRow][midCol]>target){
                endCol=midCol-1;
            }
            else{
                return true;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows=matrix.size(),cols=matrix[0].size();
        int startCol=0,midCol,endCol=cols-1,startRow=0,endRow=rows-1,midRow;
        while (startRow<=endRow)
        {
            midRow=startRow+((endRow-startRow)/2);
            if(matrix[midRow][0] <= target && target <= matrix[midRow][cols-1]) {
            return searchInRow(matrix, target, midRow);
        }
        else if(target < matrix[midRow][0]) {
            endRow = midRow - 1;
        }
        else {
            startRow = midRow + 1;
        }
        }
        return false;
    }
};