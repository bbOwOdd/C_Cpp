class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if (nums.empty()) return ans;

        for (int i = 0; i < nums.size();) {
            int start = nums[i];
            int j = i;
            while (j + 1 < nums.size() && nums[j + 1] == nums[j] + 1) {
                j++;
            }
            if (nums[j] == start) {
                ans.push_back(to_string(start));
            } else {
                ans.push_back(to_string(start) + "->" + to_string(nums[j]));
            }
            
            i = j + 1;
        }
        return ans;
    }
};
