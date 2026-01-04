class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int cnt[128]{};
        int ans = 0;
        for(int l = 0, r = 0; r < s.size(); r++){
            ++cnt[s[r]];
            while(cnt[s[r]] > 1) --cnt[s[l++]];
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};
