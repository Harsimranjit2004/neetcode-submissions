class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> ss;

        int i=0 , j =0;
        int maxFreq = 0;
        int longest = 0;
        while (j< s.size()){
            ss[s[j]]++;
            maxFreq = max(maxFreq, ss[s[j]]);

            if((j-i+1) - maxFreq <=k){
                longest = max(longest, (j-i+1));
            }else{
                while((j-i+1) - maxFreq >k ){
                    ss[s[i]]--;
                    if(ss[s[i]]==0){
                        ss.erase(s[i]);
                    }
                    i++;
                }
            }
            j++;

        }
        return longest;
    }
};
