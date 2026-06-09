class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        std::sort(nums.begin(),nums.end());
        return 1LL * k*(nums.back()-nums[0]);

    }
};