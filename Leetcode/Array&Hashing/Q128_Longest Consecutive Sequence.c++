class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        unordered_map<int, int> map;
        int ans = 0;

        for(int n : nums){
            int y = n;
            while(s.contains(y)) s.erase(y++);
            map[n] = (map.contains(y) ? map[y] : 0) + y - n;
            ans = max(ans, map[n]);
        }

        return ans;
    }
};
