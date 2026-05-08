class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int , int> ss;

        for(int i = 0;i< nums.size();i++){
            ss[nums[i]]++;
        }
        auto cmp = [&](int a , int b){
            return ss[a] > ss[b];
        };
        priority_queue<int, vector<int> , decltype(cmp)> pq(cmp);

        for(auto& [key, value]: ss){
            pq.push(key);
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<int> ans;

        while(!pq.empty()){
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;

    }
};
