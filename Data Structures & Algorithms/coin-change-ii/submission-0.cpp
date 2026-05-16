class Solution {
public:
    int solve(int i, int amt, vector<int>& coins, vector<vector<int>>& dp) {

        if (amt == 0) return 1;
        if (amt < 0) return 0;
        if (i >= coins.size()) return 0;
        if(dp[i][amt] != -1)return dp[i][amt];
        // skip current coin
        int skip = solve(i + 1, amt, coins, dp);

        int take = solve(i, amt - coins[i], coins, dp);

        return dp[i][amt] = skip + take;
    }

    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size()+1, vector<int>(amount+1, -1));

        return solve(0, amount, coins, dp);
    }
};