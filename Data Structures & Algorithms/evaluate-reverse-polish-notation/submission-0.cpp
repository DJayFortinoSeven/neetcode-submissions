class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st;
        string op1, op2;
        for(auto &s : tokens){
            if(s=="+"||s=="-"||s=="*"||s=="/"){
                op2 = st.top();
                st.pop();
                op1 = st.top();
                st.pop();
                st.push(evaluate(op1,op2,s[0]));
            }
            else{
                st.push(s);
            }
        }
        string output = st.top();
        return stoi(output);
    }

    string evaluate(string op1, string op2, char op){
        switch(op){
            case '+':
            return to_string(stoi(op1) + stoi(op2));
            case '-':
            return to_string(stoi(op1) - stoi(op2));
            case '*':
            return to_string(stoi(op1) * stoi(op2));
            case '/':
            return to_string(stoi(op1) / stoi(op2));
        }
    }
};
