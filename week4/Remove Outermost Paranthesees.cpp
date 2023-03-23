class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<int> st;
        string ans;
        for(int i = 0; i < s.size(); i++){
            if(s[i]=='('){
                if(st.empty()){
                    st.push(s[i]);
                }
                else{
                    st.push(s[i]);
                    ans+=s[i];
                }
            }
            else{
                if(st.top()=='('){
                    if(st.size()==1){
                        st.pop();
                    }
                    else{
                        ans+=')';
                        st.pop();
                    }
                }
                else{
                    st.push(')');
                }
            }
        }
        return ans;
    }

};
