class Solution {
public:

    long long solve(int i,
                    int j,
                    string& s,
                    string& t,
                    vector<vector<long long>>& dp)
    {
        // fully formed t
        if(j == t.size())
            return 1;

        // s finished but t not finished
        if(i == s.size())
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        // skip current char in s
        long long skip =
            solve(i+1, j, s, t, dp);

        long long take = 0;

        // chars match
        if(s[i] == t[j]){

            take =
                solve(i+1,
                      j+1,
                      s,
                      t,
                      dp);
        }

        return dp[i][j] =
            take + skip;
    }

    int numDistinct(string s, string t) {

        vector<vector<long long>> dp(
            s.size(),
            vector<long long>(t.size(), -1)
        );

        return solve(0, 0, s, t, dp);
    }
};