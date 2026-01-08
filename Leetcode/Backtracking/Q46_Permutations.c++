class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int size = nums.size();
        vector<vector<int>> ans;
        vector<int> subset(size);
        vector<bool> s(size);
        function<void(int)> dfs = [&](int startIdx){
            if(startIdx == size){
                ans.push_back(subset);
                return;
            }
            for(int i = 0; i < size; i++){
                if(!s[i]){
                    s[i] = true;
                    subset[startIdx] = nums[i];
                    dfs(startIdx + 1);
                    s[i] = false;
                }
            }
        };
        dfs(0);
        return ans;
    }
};
