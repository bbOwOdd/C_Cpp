class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int output = -1;
        for(int i : s){
            if(s.count(-i)) output = max(output, i);
        }
        return output;
    }
};
