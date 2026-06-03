class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int n = s.size();

        for(int i=0; i<n; i++) {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            }
            else{ 
                if(st.size() == 0) {
                    return false;
                }

                if((st.top() == '(' && s[i] == ')') || (st.top() == '{' && s[i] == '}') || (st.top() == '[' && s[i] == ']')) {
                        st.pop();
                }
                else{
                    return false;
                }
            }
        }
        if(st.size() == 0) {
            return true;
        }else{
            return false;
        }
    }
};