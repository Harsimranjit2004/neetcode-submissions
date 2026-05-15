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
         int n = nums.size();
        if(n == 1) return nums[0];

        // Case 1: index 0 to n-2
        vector<int> sub1(nums.begin(), nums.begin() + n-1);
        vector<int> dp1(n-1, -1);
        int case1 = maxCost(n-2, sub1, dp1);

        // Case 2: index 1 to n-1
        vector<int> sub2(nums.begin() + 1, nums.end());
        vector<int> dp2(n-1, -1);
        int case2 = maxCost(n-2, sub2, dp2);

        return max(case1, case2);
    }
};
