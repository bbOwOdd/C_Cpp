class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ret = 0, n = heights.size();
        stack<int> st;
        vector<int> left(n, -1);
        vector<int> right(n, n);
        for(int i = 0; i < n; i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                right[st.top()] = i;
                st.pop();
            }
            if(!st.empty()) left[i] = st.top();
            st.push(i);
        }
        for(int i = 0; i < n; i++) ret = max(ret, heights[i] * (right[i] - left[i] - 1));
        return ret;
    }
};
