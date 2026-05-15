class Solution {
public:

    int minCost(int i, vector<int>& cost, vector<int>& dp){
        if(i< 0)return 0;
        if(i==0 || i==1)return cost[i];
        if(dp[i] != -1)return dp[i];
        int choice1 = cost[i] + minCost(i-1, cost, dp);
        int choice2 = cost[i] + minCost(i-2, cost, dp);
        return dp[i] = min(choice1, choice2);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1, -1);
        return min(minCost(n-1, cost, dp), minCost(n-2, cost,dp));
    }
};
