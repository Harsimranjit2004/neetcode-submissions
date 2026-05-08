class Solution {
public:
    bool isPalindrome(string nums) {
        int left = 0;
        int right = nums.size()-1;


        while ( left< right){
            while(left <right && !isalnum(nums[left]))left++;
            while(left < right && !isalnum(nums[right]))right--;

            if(tolower(nums[left]) !=tolower(nums[right])){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};
