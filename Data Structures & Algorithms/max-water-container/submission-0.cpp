class Solution {
public:
    int maxArea(vector<int>& h) {
        int left = 0;
        int right = h.size()-1;
        int maxi = 0;


        while(left < right){
            int width = right -left;
            int area = min(h[left], h[right])* width;
            maxi = max(maxi, area);
            if(h[left]<= h[right]){
                left++;
            }
            else{
                right--;
            }

        }
        return maxi;
    }
};
