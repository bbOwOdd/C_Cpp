class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        unordered_set<int> s;
        for(int i = 1; i < nums.size(); i++){
            int sum = nums[i] + nums[i - 1];
            if(s.count(sum)) return true;
            s.insert(sum);
        }
        return false;
    }
};
