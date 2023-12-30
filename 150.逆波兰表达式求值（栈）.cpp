class Solution {
public:
    void caculate(stack<int>&stk, char sym) {
        int b = stk.top();
        stk.pop();
        int a = stk.top();
        stk.pop();
        switch (sym) {
            case '+':
            stk.push(a + b);
            break;
            case '-':
            stk.push(a - b);
            break;
            case '*':
            stk.push(a * b);
            break;
            case '/':
            stk.push(a / b);
            break;
        }
    }
    int evalRPN(vector<string>& tokens) {
        stack<int>stk;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/") {
                int tmp = stoi(tokens[i]);
                stk.push(tmp);
            }
            else {
                caculate(stk, tokens[i][0]);
            }
        }
        return stk.top();
    }
};
