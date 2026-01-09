class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int size = s.size();
        vector<bool> dp(size + 1, false);
        dp[0] = true;
        
        for(int i = 0; i < s.size(); i++){
            if(!dp[i]) continue;
            for(string w : wordDict){
                int len = w.size();
                if(i + len <= size && s.substr(i, len) == w){
                    dp[i + len] = true;
                }
            }
        }
        return dp[size];
    }
};
