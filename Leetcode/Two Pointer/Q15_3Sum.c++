class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int size = nums.size();
        for (int i = 0; i < size - 2 && nums[i] <= 0; i++) {
            if (i && nums[i] == nums[i - 1]) continue;
            int j = i + 1, k = size - 1;
            while (j < k) {
                int n = nums[i] + nums[j] + nums[k];
                if (n < 0) j++;
                else if (n > 0) k--;
                else {
                    ans.push_back({nums[i], nums[j++], nums[k--]});
                    while (j < k && nums[j] == nums[j - 1]) j++;
                    while (j < k && nums[k] == nums[k + 1]) k--;
                }
            }
        }
        return ans;
    }
};
