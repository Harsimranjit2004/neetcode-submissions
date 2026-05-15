class Solution {
public:
    int solve(int i , int amt, vector<int>& coins){
        if(amt==0) return 0;
           if(i == coins.size() || amt < 0) return 1e9;

        // skip
        int choice1 = solve(i+1, amt, coins);

        //take many times
        int choice2 = 1+  solve(i, amt-coins[i], coins);

        return min(choice1, choice2);
    }
    int coinChange(vector<int>& coins, int amount) {
        
        int ans = solve(0, amount,coins );
        return ans == 1e9 ? -1 : ans;
    }
};
