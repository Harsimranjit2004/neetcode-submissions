class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int longest = 0;

        unordered_set<int> ss;

        for(int i = 0;i<nums.size();i++){
            ss.insert(nums[i]);

        }

        for(int i = 0;i<nums.size();i++){
            if(!ss.contains(nums[i]-1)){
                int currLong= 0;
                while(ss.contains(nums[i]+currLong)){
                    currLong++;
                }
                longest = max(longest, currLong);
            }

        }
        return longest;

    }
};
