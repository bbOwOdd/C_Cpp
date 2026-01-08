class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        function<void(int, int, string)> dfs = [&](int l, int r, string subset){
            if(l > n || r > n || l < r) return;
            if(l == n && r == n){
                ans.push_back(subset);
                return;
            }
            dfs(l + 1, r, subset + "(");
            dfs(l, r + 1, subset + ")");
        };
        dfs(0, 0, "");
        return ans;
    }
};
