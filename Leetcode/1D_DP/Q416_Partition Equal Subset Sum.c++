class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 == 1) return false;
        int mid = sum >> 1;
        bool dp[mid + 1];
        memset(dp, false, sizeof(dp));
        dp[0] = true;
        for (int n : nums) {
            for (int i = mid; i >= n; i--) {
                dp[i] |= dp[i - n];
            }
        }
        return dp[mid];
    }
};
