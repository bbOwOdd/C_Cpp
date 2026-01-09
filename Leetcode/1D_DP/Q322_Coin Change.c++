class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int dp[amount + 1];
        memset(dp, 0x3f, sizeof(dp));
        dp[0] = 0;
        for (int n : coins) {
            for (int i = n; i <= amount; i++) {
                dp[i] = min(dp[i], dp[i - n] + 1);
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};
