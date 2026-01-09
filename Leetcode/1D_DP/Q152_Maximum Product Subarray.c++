class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = INT_MIN, left = 1, right = 1;
        for(int i = 0; i < nums.size(); i++)
        {
            if(left == 0) left = 1;
            if(right == 0) right = 1;
            left *= nums[i];
            right *= nums[nums.size() - i - 1];
            ans = max(ans, max(left, right));
        }
        return ans;
    }
};
