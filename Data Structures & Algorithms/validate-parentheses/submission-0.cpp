class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> um = {{'}','{'},{']','['},{')','('}};
        for(auto &ch: s){
            if(ch == '[' ||ch == '(' ||ch == '{' ){
                st.push(ch);
            }
            else{
                if (!st.empty() && um[ch] == st.top()){
                    st.pop();
                }
                else{
                    return false;
                }
            }
        }
        if(st.size()>0){
            return false;
        }
        return true;
    }
};