class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int i,result=0;
        for(int i:nums)
        {
            result^=i;
        }
        return result;
    }
};