class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> brackets = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };

        for(char c : s){
            if(c == '(' || c == '[' || c == '{') st.push(c);
            else{
                if(st.empty() || st.top() != brackets[c]) return false;
                st.pop();
            }          
        }

        return st.empty();
    }
};
