class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> ss;
        vector<vector<string>> ans;

        for(int i = 0;i< strs.size();i++){
            vector<int> freq(26, 0); 
            for(char c : strs[i]){
                freq[c-'a']++;
            }
            string key = "";
            for (int j = 0;j <26;j++){
                key+= '#' + to_string(freq[j]);
            }

            ss[key].push_back(strs[i]);
        }
        for (auto& [key, val]: ss){
            ans.push_back(val);
        }
        return ans;
    }
};
