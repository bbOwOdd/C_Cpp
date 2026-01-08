class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> subset;
        function<void(int, string)> dfs = [&](int startIdx, string s){
            int size = s.size();
            if(startIdx == size){
                ans.push_back(subset);
                return;
            }
            for(int i = startIdx; i < size; i++){
                string tmp = s.substr(startIdx, i - startIdx + 1);
                if(isPalindrome(tmp)){
                    subset.push_back(tmp);
                    dfs(i + 1, s);
                    subset.pop_back();
                }
            }
        };
        dfs(0, s);
        return ans;
    }

    bool isPalindrome(string s){
        string p = s;
        reverse(p.begin(), p.end());
        if (s == p) return true;
        else return false;
    }
};
