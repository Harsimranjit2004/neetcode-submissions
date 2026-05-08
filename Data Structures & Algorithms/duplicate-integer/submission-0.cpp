#include <unordered_map> 
using namespace std;

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> setss;

        for(int i = 0;i< nums.size();i++){
            if(setss.contains(nums[i])){
                return true;
            }
            setss.insert(nums[i]);
        }
        return false;
    }
};