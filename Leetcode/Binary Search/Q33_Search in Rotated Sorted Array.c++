class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size() - 1;
        int left = 0, right = n;
        while(left < right){
            int middle = (left + right) >> 1;
            if(nums[0] <= nums[middle]){
                if(nums[0] <= target && target <= nums[middle]) right = middle;
                else left = middle + 1;
            }else{
                if(nums[middle] < target && target <= nums[n]) left = middle + 1;
                else right = middle;
            }
        }
        return nums[left] == target ? left : -1;
    }
};
