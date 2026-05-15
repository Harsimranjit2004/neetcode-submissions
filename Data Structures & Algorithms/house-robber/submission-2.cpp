class Solution {
public:
    int maxCost(int i , vector<int>& nums, vector<int>& dp){
        if(i<0)return 0;
        if(dp[i] != -1) return dp[i];
        int skip = maxCost(i-1, nums, dp);
        int take = nums[i] + maxCost(i-2, nums, dp);
        return dp[i] =  max(skip, take);

    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+1, -1);
        return maxCost(nums.size()-1, nums, dp);
    }
};
