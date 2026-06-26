#include <string>
#include <stack>

class Solution {
public:
    bool isValid(string s) {
        if(s.size() % 2 != 0){
            return false;
        }
        stack<char> st; 

        for (char c : s) {
            if(c == '(' || c == '{' || c == '['){
                st.push(c);
            } else {
                if(st.size() == 0){
                    return false;
                }
                if((st.top() == '(' && c == ')') || 
                   (st.top() == '[' && c == ']') || 
                   (st.top() == '{' && c == '}')){
                    st.pop();
                } else {
                    return false;
                }
            }
        }
        return st.size() == 0;
    }
};
