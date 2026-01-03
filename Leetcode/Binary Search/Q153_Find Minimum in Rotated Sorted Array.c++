class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size() - 1;
        if(nums[0] <= nums[n]) return nums[0];
        int left = 0, right = n;
        while(left < right){
            int middle = (left + right) >> 1;
            if(nums[0] <= nums[middle]) left = middle + 1;
            else right = middle;
        }
        return nums[left];
    }
};
