// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         unordered_map<char, int> ss;
//         int i=0,j=0;
//         int longest = 0;
//         while(j < s.size()){
//             ss[s[j]]++;
//             if((int)ss.size() == j-i+1){
//                 longest = max(longest, j-i+1);
//                 j++;
//             }
//             else{
//                 ss[s[i]]--;
//                 if(ss[s[i]]==0){
//                     ss.erase(s[i]);
//                 }
//                 i++;
//             }
        

//         }

//         return longest;
//     }
// };
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> ss;
        int i = 0, j = 0, longest = 0;

        while (j < s.size()) {
            ss[s[j]]++;

            if (ss.size() == j - i + 1) {
                longest = max(longest, j - i + 1);
                
            } else {
                while(ss.size() < j-i+1){

                ss[s[i]]--;
                if (ss[s[i]] == 0) ss.erase(s[i]);
                i++;
                }
            }
            j++;
        }

        return longest;
    }
};