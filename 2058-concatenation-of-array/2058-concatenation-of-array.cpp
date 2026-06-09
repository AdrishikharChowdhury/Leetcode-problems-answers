class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n=nums.size();
        vector<int> twoNums(2*n);
        for(int i=0;i<nums.size();i++){
            twoNums[i]=nums[i];
            twoNums[i+n]=nums[i];
        }
        return twoNums;
    }
};