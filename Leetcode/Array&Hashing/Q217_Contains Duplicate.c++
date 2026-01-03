class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> map;
        for(int i = 0; i < nums.size(); i++){
            if(map.contains(nums[i])) return true;
            map[nums[i]] = i;
        }
        return false;
    }
};
