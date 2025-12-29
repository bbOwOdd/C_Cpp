class Solution {
public:
    int lengthOfLastWord(string s) {
        int right = s.size() - 1, count = 0;
        while(s[right] == ' ') right--;
        for(int i = right; i >= 0; i--){
            if(s[i] == ' ') break;
            else count++;
        }
        return count;
    }
};
