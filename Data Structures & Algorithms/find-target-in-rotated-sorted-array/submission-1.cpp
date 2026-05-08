class Solution {
public:

    int binarySearch(vector<int>& nums, int left, int right, int target){

        while(left <= right){

            int mid = left + (right - left) / 2;

            if(nums[mid] == target){
                return mid;
            }

            else if(nums[mid] < target){
                left = mid + 1;
            }

            else{
                right = mid - 1;
            }
        }

        return -1;
    }

    int search(vector<int>& nums, int target) {

        int n = nums.size();

        int left = 0;
        int right = n - 1;

        // find minimum index (rotation point)

        while(left < right){

            int mid = left + (right - left) / 2;

            if(nums[mid] > nums[right]){
                left = mid + 1;
            }
            else{
                right = mid;
            }
        }

        int split = left;

        // search left sorted half

        int ans = binarySearch(nums, 0, split - 1, target);

        if(ans != -1){
            return ans;
        }

        // search right sorted half

        return binarySearch(nums, split, n - 1, target);
    }
};