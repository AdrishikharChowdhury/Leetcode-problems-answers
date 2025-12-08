class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows=0,cols=matrix[0].size()-1;
        while(rows < matrix.size() && cols >= 0){
            if(target==matrix[rows][cols]){
                return true;
            }
            else if(target<matrix[rows][cols]){
                cols-=1;
            }
            else{
                rows+=1;
            }
        }
        return false;
    }
};