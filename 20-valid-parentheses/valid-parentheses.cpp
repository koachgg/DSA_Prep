#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if(ch == '}' || ch == ')' || ch == ']') {
                if(st.empty()) {
                    return false;
                }
                char top = st.top();
                if((ch == '}' && top == '{') || (ch == ')' && top == '(') || (ch == ']' && top == '[')) {
                    st.pop();
                } else {
                    return false;
                }
            } else {
                st.push(ch);
            }
        }
        return st.empty();
    }
};
