class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<string> d = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans = {""};
        for (char c : digits) {
            string s = d[c - '2'];
            vector<string> subset;
            for (string a : ans) {
                for (char b : s) subset.push_back(a + b);
            }
            ans = move(subset);
        }
        return ans;
    }
};
