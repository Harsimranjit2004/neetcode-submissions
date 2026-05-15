class Solution {
public:
    int solve(int i, string& s , vector<int>& dp){
        if(i == s.size())return 1;
        if(s[i] == '0')return 0;

        if(dp[i] != -1)return dp[i];
        
        int choice1 = solve(i+1, s, dp);
        int choice2 = 0;
        if(i+1 < s.size()){
            int twoDigit(stoi(s.substr(i, 2)));
            if(twoDigit<=26){
                choice2 = solve(i+2, s, dp);
            }
        }
        return dp[i] = choice1+choice2;
    }
    int numDecodings(string s) {
         vector<int> dp(s.size(), -1);
        return solve(0, s, dp);  
    }
};
