class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int o1=0,o2=0,o3=0;
        for(auto i : s) {
            if(i == '('){
                st.push(i);
            }
            else if(i == ')'){
                if(st.size() == 0) return false;
                char t = st.top();
                if(t == '('){
                    st.pop();
                }
                else return false;
            }
            else if( i == '['){
                 st.push(i);
            }
            else if(i == ']'){
                if(st.size() ==0) return false;
                char t = st.top();
                if(t == '['){
                    st.pop();
                }
                else return false;
            }
            else if(i == '{'){
                st.push(i);
            }
            else {
                if(st.size() == 0) return false;
                char t = st.top();
                if(t == '{'){
                    st.pop();
                }
                else return false;
            }
        }
        if(st.size() == 0) return true;
        return false;
    }
};