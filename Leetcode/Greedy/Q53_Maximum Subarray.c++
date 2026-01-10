class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0], mx = nums[0];
        for(int i = 1; i < nums.size(); i++){
            mx = max(mx, 0) + nums[i];
            ans = max(ans, mx);
        }
        return ans;
    }
};
