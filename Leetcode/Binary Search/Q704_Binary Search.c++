class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while(left < right){
            int middle = (left + right) >> 1;
            if(nums[middle] == target) return middle;
            else if(nums[middle] > target) right = middle;
            else left = middle + 1;
        }
        return nums[left] == target ? left : -1;
    }
};
