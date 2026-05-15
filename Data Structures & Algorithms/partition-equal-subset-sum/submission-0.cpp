class Solution {
public:
    bool solve(int i , int target, vector<int>& nums, vector<vector<int>>& dp){
        if(target == 0) return true;
        if(i == nums.size()) return false;

        // skip
        if(dp[target][i] != -1) return dp[target][i];
        bool skip = solve(i+1, target, nums, dp);

        // take 
        bool take = false;
        if(nums[i]<=target){
            take = solve(i+1, target-nums[i], nums, dp);
        }
        return dp[target][i] =  skip || take;
    }
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for(int i = 0;i < nums.size();i++){
            totalSum+=nums[i];
        }
        if(totalSum % 2 != 0) return false;

        int sum = totalSum/2;
        vector<vector<int>> dp(sum+1, vector<int>(nums.size(), -1));
        return solve(0, sum , nums , dp);
    }
};
