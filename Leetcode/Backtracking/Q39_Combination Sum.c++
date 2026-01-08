class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> subset;
        function<void(int, int)> dfs = [&](int startIdx, int target) {
            if (target == 0) {
                ans.push_back(subset);
                return;
            }
            if (target < candidates[startIdx]) return;
            for (int i = startIdx; i < candidates.size(); i++) {
                subset.push_back(candidates[i]);
                dfs(i, target - candidates[i]);
                subset.pop_back();
            }
        };
        dfs(0, target);
        return ans;
    }
};
