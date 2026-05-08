class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()){return false;}
        unordered_map<char, int> sss;
        unordered_map<char, int> ssss;
        for (char c: s){
            sss[c]++;
        }
        for(char c: t){
            ssss[c]++;
        }

       
        if(sss==ssss){
            return true;
        }
        return false;
    }

};
