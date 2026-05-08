class Solution {
public:
    int trap(vector<int>& h) {
        int leftMax= h[0];
        int maxRight = h[h.size()-1];
        int res  = 0;
        int i = 0;
        int j = h.size()-1;

        while(i < j){

            if(h[i] < h[j]){
                leftMax = max(leftMax , h[i]);
                res += leftMax-h[i];
                i++; 
            }else{
                maxRight = max(maxRight , h[j]);
                res += maxRight-h[j];
                j--;
            }
        }
        return res;
    }
};
