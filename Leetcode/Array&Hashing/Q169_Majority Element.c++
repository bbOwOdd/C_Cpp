class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0, m = 0;
        for (int n : nums) {
            if (cnt == 0) {
                m = n;
                cnt = 1;
            } 
            else cnt += m == n ? 1 : -1;
        }
        return m;
    }
};
