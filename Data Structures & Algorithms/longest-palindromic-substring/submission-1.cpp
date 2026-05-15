// class Solution {
// public:
//     struct hashing{
//         size_t operator()(const pair<int,int>& p) const {
//             return hash<int>()(p.first)
//                    ^ hash<int>()(p.second);
//         }
//     };
//     string solve(int i, int j, string& s, unordered_map<pair<int,int>,string,hashing>& dp){

//         if (j < i)  return "";
//         if (i == j) return string(1, s[i]);
//         pair<int,int> key = {i, j};

//         if (dp.find(key) != dp.end()) {
//             return dp[key];
//         }
//         if(s[i] == s[j]){
//             return dp[key] = s[i] + solve(i+1, j-1, s, dp) + s[j];
//         }else{
//             string left = solve(i+1, j, s, dp);
//             string right = solve(i, j-1, s, dp);
//             return dp[key] = left.size()> right.size() ? left: right;
//         }

//     }
//     string longestPalindrome(string s) {
//         // unordered_map<pair<int,int>, string> 
//         unordered_map<pair<int,int>,string,hashing> dp;




//         return solve(0, s.size()-1, s, dp);
//     }
// };

class Solution {
public:
    vector<vector<int>> dp;

    bool isPalin(int i, int j, string& s){
        if(i >= j) return true;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] != s[j]) return dp[i][j] = false;
        return dp[i][j] = isPalin(i+1, j-1, s);
    }

    string longestPalindrome(string s){
        int n = s.size();
        dp.assign(n, vector<int>(n, -1));
        string best = "";

        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                if(isPalin(i, j, s)){
                    if(j - i + 1 > (int)best.size())
                        best = s.substr(i, j - i + 1);
                }
            }
        }
        return best;
    }
};
