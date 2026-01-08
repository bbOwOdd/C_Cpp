class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset;
        sort(nums.begin(), nums.end());
        function<void(int)> dfs = [&](int startIdx){
            ans.push_back(subset);
            for(int i = startIdx; i < nums.size(); i++){
                if(i > startIdx && nums[i] == nums[i - 1]) continue;
                subset.push_back(nums[i]);
                dfs(i + 1);
                subset.pop_back();
            }
        };
        dfs(0);
        return ans;
    }
};
