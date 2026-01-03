class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0, min = prices[0];
        for (int v : prices) {
            ans = max(ans, v - min);
            min = min(min, v);
        }
        return ans;
    }
};
