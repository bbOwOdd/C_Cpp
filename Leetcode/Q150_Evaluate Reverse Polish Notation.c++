class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> q;

        for(const string &c : tokens) {
            int op;
            if(c == "+") {
                op = q.top();
                q.pop();
                op += q.top();
                q.pop();
            } else if(c == "-") {
                op = q.top();
                q.pop();
                op = q.top() - op;
                q.pop();
            } else if(c == "*") {
                op = q.top();
                q.pop();
                op *= q.top();
                q.pop();
            } else if(c == "/") {
                op = q.top();
                q.pop();
                op = q.top() / op;
                q.pop();
            } else {
                op = stoi(c);
            }
            q.push(op);
        }
        return q.top();
    }
};
