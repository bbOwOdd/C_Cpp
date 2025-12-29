class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_set<int> vis(nums.begin(), nums.end());
        int output = -1;
        for(int i : vis){
            if(vis.count(-i)) output = max(output, i);
        }
        return output;
    }
};
