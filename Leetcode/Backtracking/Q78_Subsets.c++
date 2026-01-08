class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset;
        if(nums.empty()) return ans;
        function<void(int)> dfs = [&](int startIdx){
            ans.push_back(subset);
            for(int i = startIdx; i < nums.size(); i++){
                subset.push_back(nums[i]);
                dfs(i + 1);
                subset.pop_back();
            }
        };
        dfs(0);
        return ans;
    }

    // void dfs(vector<int>& nums, vector<int>& subset, int startIdx, vector<vector<int>>& ans){
    //     ans.push_back(subset);
    //     for(int i = startIdx; i < nums.size(); i++){
    //         subset.push_back(nums[i]);
    //         dfs(nums, subset, i + 1, ans);
    //         subset.pop_back();
    //     }
    // }
};
