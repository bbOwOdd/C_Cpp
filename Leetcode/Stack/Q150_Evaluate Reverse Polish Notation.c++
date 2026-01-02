class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto& t : tokens){
            if(t.size() > 1 || isdigit(t[0])) st.push(stoi(t));
            else{
                int x = st.top();
                st.pop();
                int y = st.top();
                st.pop();
                if(t[0] == '+') st.push(y + x);
                else if(t[0] == '-') st.push(y - x);
                else if(t[0] == '*') st.push(y * x);
                else st.push(y / x);
            }
        }
        return st.top();
    }
};
