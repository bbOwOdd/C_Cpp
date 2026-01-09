class Solution {
public:
    string longestPalindrome(string s) {
        int c = 0, l, r;
        int mx = 0, count = 1;
        string ans = "";
        while(c < s.size()){
            count = 1;
            l = c - 1;
            r = c + 1;
            while(r < s.size() && s[r] == s[c]){
                count += 1;
                r++;
                c++;
            }
            while(l >= 0 && r < s.size()){
                if(s[l] != s[r]) break;
                l--;
                r++;
                count += 2;
            }
            if(count > mx){
                ans = s.substr(l + 1, count);
                mx = count;
            }
            c++;
        }
        return ans;
    }
};
