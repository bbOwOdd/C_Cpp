class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        int cnt[51] = {0}, ans = 0;
        for(int i = 0; i < nums.size(); i++){
            if(++cnt[nums[i]] >= 2){
                ans ^= nums[i];
            }
        }
        return ans;
    }
};
