class Solution {
public:
    int evalRPN(vector<string>& tokens) {
stack<int> st;
        for(auto it:tokens){
            if(it=="+"){
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();
                st.push(b+a);
            }
            else if(it=="-"){
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();
                st.push(b-a);                
            }
            else if(it=="*"){
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();
                st.push(b*a);                
            }
            else if(it=="/") {
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();
                st.push(static_cast<int>(static_cast<double>(b)/a));                
            }
            else {
                st.push(stoi(it));
            }
        }
        return st.top();        
    }
};