class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<pair<int, int>> st;

        // calcuate next small element 
        vector<int> nse(n, 0);
        nse[n-1] = n;
        st.push({heights[n-1], n-1});

        for(int i = n-2;i>=0;i--){
            while(!st.empty() && heights[i] <= st.top().first){ // if height is small we need this not other 
                st.pop();
            }
            if(st.empty()){ // if st emptoy no element then ansower
                nse[i] = n;
            }
            else{
                nse[i] = st.top().second;
            }
            st.push({heights[i], i});
        }

        while(!st.empty()) st.pop();

        vector<int> pse(n, 0);
        pse[0] = -1;
        st.push({heights[0], 0});

        for(int i = 1;i< n;i++){
            while(!st.empty() && heights[i] <= st.top().first){
                st.pop();
            }
            if(st.empty()){
                pse[i] = -1;
            }else{
                pse[i] = st.top().second;
            }
            st.push({heights[i] , i});
        }
        int maxArea = -1;
        for(int i = 0;i< n;i++){
            int width  = nse[i] - pse[i] -1;
            maxArea = max(maxArea, (width*heights[i]));
        }

        return maxArea;
    }
};
