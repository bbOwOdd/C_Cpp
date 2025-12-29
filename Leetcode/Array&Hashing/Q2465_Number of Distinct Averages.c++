class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_set<float> vis;
        int i = 0;
        int n = nums.size() - 1;
        while(i <= n){
            vis.insert((nums[i] + nums[n]) / 2.0);
            i++;
            n--;
        }
        return vis.size();
    }
};
