class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> ss;
        vector<int> ans;

        for(int i=0;i < nums.size(); i++ ){
            int compliment = target- nums[i];

            if(ss.contains(compliment)){
                return {ss[compliment], i};   
            }
            ss[nums[i]] = i;

        }
        return ans;
    }
};
