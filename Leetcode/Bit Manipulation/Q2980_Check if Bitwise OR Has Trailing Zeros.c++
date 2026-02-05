class Solution {
public:
    bool hasTrailingZeros(vector<int>& nums) {
        int cnt = 0;
        for(int i = 0; i < nums.size(); i++){
            cnt += (nums[i] & 1 ^ 1);
        }
        return cnt >= 2;
    }
};
