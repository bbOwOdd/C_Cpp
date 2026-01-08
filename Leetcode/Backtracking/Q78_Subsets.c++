class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        if(nums.empty()) return ans;

        vector<int> subset;
        dfs(nums, subset, 0, ans);
        return ans;
    }

    void dfs(vector<int>& nums, vector<int>& subset, int startIdx, vector<vector<int>>& ans){
        ans.push_back(subset);
        for(int i = startIdx; i < nums.size(); i++){
            subset.push_back(nums[i]);
            dfs(nums, subset, i + 1, ans);
            subset.pop_back();
        }
    }
};
