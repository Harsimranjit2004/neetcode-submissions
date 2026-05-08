class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> perm;
        for(int i =0;i< s1.size();i++){
            perm[s1[i]]++;
        }
        int i = 0, j = 0;
        unordered_map<char , int> window;
        while(j< s2.size()){
            window[s2[j]]++;

            if(j-i+1 > s1.size()){
                window[s2[i]]--;
                if(window[s2[i]]==0){
                    window.erase(s2[i]);
                }
                i++;
            } 
               
            if(window == perm){
                return true;
            }
            j++;
           
        }
        return false;
    }
};
