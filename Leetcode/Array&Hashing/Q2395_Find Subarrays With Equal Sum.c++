class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        unordered_set<int> vis;
        for(int i = 1; i < nums.size(); i++){
            int sum = nums[i] + nums[i - 1];
            if(vis.count(sum)) return true;
            vis.insert(sum);
        }
        return false;
    }
};
