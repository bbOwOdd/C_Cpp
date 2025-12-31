class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> ans(size);
        for(int i = 0, left = 1; i < size; i++){
            ans[i] = left;
            left *= nums[i];
        }

        for(int i = size - 1, right = 1; i >= 0; i--){
            ans[i] *= right;
            right *= nums[i];
        }

        return ans;
    }
};
