class Solution {
public:
    
    int solve(int i,int count,  int target, vector<int>& nums, unordered_map<string, int>& dp){
        if (i == nums.size()) {
            return count == target ? 1 : 0;
        }
        string key = to_string(i) + ',' +to_string(count);
         if(dp.find(key) != dp.end()){
            return dp[key];
        }
        int ch1 = solve(i+1, count+nums[i], target, nums, dp);
        int ch2 = solve(i+1, count-nums[i], target, nums, dp);
        return dp[key] =  ch1 + ch2;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<string, int> dp;
        return solve(0, 0, target, nums, dp);
    }
};
