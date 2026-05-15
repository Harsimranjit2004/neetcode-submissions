class Solution {
public:

    int solve(int i , int prev , vector<int>& nums, vector<vector<int>>& dp){
        if(nums.size() == i ){
            return 0;
        }
        if(dp[i][prev+1] != -1)return dp[i][prev + 1];
        // skip
        int skip = solve(i+1, prev, nums, dp);

        //take
        int take = 0;
         if(prev == -1 ||
           nums[i] > nums[prev])
        {
            take =
                1 + solve(i+1, i, nums, dp);
        }
        return dp[i][prev + 1] =  max(skip, take );
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size()+1, vector<int>(nums.size()+1, -1));

        return solve(0, -1, nums, dp);
    }
};
