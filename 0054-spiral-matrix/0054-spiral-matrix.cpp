class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int srows=0,scols=0;
        int erows=matrix.size()-1,ecols=matrix[0].size()-1;
        vector <int> ans;
        while(srows<=erows && scols<=ecols){
            //Top
            for(int i=scols;i<=ecols;i++){
                ans.push_back(matrix[srows][i]);
            }
            //Right
            for(int i=srows+1;i<=erows;i++){
                ans.push_back(matrix[i][ecols]);
            }
            //Bottom
            for(int i=ecols-1;i>=scols;i--){
                if(srows==erows){
                    break;
                }
                ans.push_back(matrix[erows][i]);
            }
            //Left
            for(int i=erows-1;i>=srows+1;i--){
                if(scols==ecols){
                    break;
                }
                ans.push_back(matrix[i][scols]);
            }
            srows+=1; scols+=1;
            erows-=1; ecols-=1;
        }
        return ans;
    }
};