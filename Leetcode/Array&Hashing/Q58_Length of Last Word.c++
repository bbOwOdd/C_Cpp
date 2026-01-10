class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = 0;
        int right = s.size() - 1;
        while(s[right] == ' ') right--;
        for(int i = right; i >= 0; i--){
            if(s[i] == ' ') break;
            else count++;
        }
        return count;
    }
};
