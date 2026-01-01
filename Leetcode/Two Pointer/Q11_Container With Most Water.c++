class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0, r = heights.size() - 1, ans = 0;
        while(l < r){
            int d = min(heights[l], heights[r]) * (r - l);
            ans = max(ans, d);
            if(heights[l] < heights[r]) l++;
            else r--;
        }
        return ans;
    }
};
