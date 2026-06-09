class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> ans;
        unordered_set<int> s;
        int n=grid.size();
        int repeatValue, missingValue;
        int expectedSum=0,actualSum=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                actualSum+=grid[i][j];
                if(s.find(grid[i][j])!=s.end()){
                    repeatValue=grid[i][j];
                    ans.push_back(repeatValue);
                    
                }
                s.insert(grid[i][j]);
            }
        }
        expectedSum=(n*n)*(n*n+1)/2;
        missingValue=expectedSum+repeatValue-actualSum;
        ans.push_back(missingValue);
        return ans;
    }
};