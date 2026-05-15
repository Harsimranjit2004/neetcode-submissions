class Solution {
public:
    void solve(int i, vector<int>& nums, int currMax, int currMin, int& ans) {
        if (i == nums.size()) return;

        int x = nums[i];

        int oldMax = currMax;
        int oldMin = currMin;

        currMax = max({x, oldMax * x, oldMin * x});
        currMin = min({x, oldMax * x, oldMin * x});

        ans = max(ans, currMax);

        solve(i + 1, nums, currMax, currMin, ans);
    }

    int maxProduct(vector<int>& nums) {
        int ans = nums[0];

        solve(1, nums, nums[0], nums[0], ans);

        return ans;
    }
};