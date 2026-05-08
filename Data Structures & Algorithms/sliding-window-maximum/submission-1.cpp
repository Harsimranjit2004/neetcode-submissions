class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        int i = 0;
        int j = 0;
        deque<int> dq; // stores indices
        vector<int> res; 

        while(j < nums.size()){
            // remove useless smaller elements from back
            while(!dq.empty() && nums[dq.back()] < nums[j])
                dq.pop_back();
            
            dq.push_back(j);

            if(j - i + 1 < k){
                j++;
            } else if(j - i + 1 == k){
    res.push_back(nums[dq.front()]);
    if(dq.front() == i)  // expire front if needed
        dq.pop_front();
    i++;  // shrink from left
    j++;
}
        }

        return res;
    }
};
