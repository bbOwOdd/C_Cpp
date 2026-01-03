class Solution {
public:
    char repeatedCharacter (string s)
    {
        for (int i = 1; i < s.size (); i++){
            for (int j = i - 1; j >= 0; j--){
                if(s [i] == s [j]) return s[i];
            } 
        }
        return 'n';
    }
};
