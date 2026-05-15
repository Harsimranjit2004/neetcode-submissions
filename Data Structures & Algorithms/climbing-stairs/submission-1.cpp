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


        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2;i<=n;i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
        // return count(n, dp);
        
    }
};
