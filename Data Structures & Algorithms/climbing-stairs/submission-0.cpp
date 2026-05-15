class Solution {
public:
    int count(int n , vector<int>& dp){
        if(n<0)return 0;
        if(n==0)return 1;
        if(dp[n] != -1) return dp[n];
        int choice1 = count(n-1, dp);
        int choice2 = count(n-2, dp);
        return dp[n] = choice1+choice2;

    }
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);

        return count(n, dp);
        
    }
};
