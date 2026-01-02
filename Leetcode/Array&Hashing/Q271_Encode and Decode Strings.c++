#include <cstring>

class Solution {
public:

    string encode(vector<string>& strs) {
        string ans = "";
        for(string s : strs){
            int size = s.size();
            ans += string((const char*) &size, sizeof(size));
            ans += s;
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int size = 0;
        for(int i = 0; i < s.size(); i += size) {
            memcpy(&size, s.data() + i, sizeof(size));
            i += sizeof(size);
            ans.push_back(s.substr(i, size));
        }
        return ans;
    }
};
