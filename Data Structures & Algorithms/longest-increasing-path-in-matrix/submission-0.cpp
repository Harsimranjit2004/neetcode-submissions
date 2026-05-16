class Solution {
public:
    int rows, cols;

    int solve(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        if (dp[i][j] != -1) return dp[i][j];

        int up = 0, down = 0, left = 0, right = 0;

        // up
        if (i - 1 >= 0 && matrix[i - 1][j] > matrix[i][j]) {
            up = solve(i - 1, j, matrix, dp);
        }

        // down
        if (i + 1 < rows && matrix[i + 1][j] > matrix[i][j]) {
            down = solve(i + 1, j, matrix, dp);
        }

        // left
        if (j - 1 >= 0 && matrix[i][j - 1] > matrix[i][j]) {
            left = solve(i, j - 1, matrix, dp);
        }

        // right
        if (j + 1 < cols && matrix[i][j + 1] > matrix[i][j]) {
            right = solve(i, j + 1, matrix, dp);
        }

        return dp[i][j] = 1 + max({up, down, left, right});
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        rows = matrix.size();
        cols = matrix[0].size();

        vector<vector<int>> dp(rows, vector<int>(cols, -1));

        int ans = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                ans = max(ans, solve(i, j, matrix, dp));
            }
        }

        return ans;
    }
};