class Solution {
private:
    string stacked(string s){
        stack<int> st;
        int i = 0; 
        int n = s.size();
        while(i< n){
            if(s[i]=='#'){
                if(!st.empty()){
                    st.pop();
                }
            }
            else{
                st.push(s[i]);
            }

            i++;
        }
        string ans = "";
        while(!st.empty()){
            char c = st.top();
            st.pop();
            ans+=c;
        }
        return ans;
    }
public:
    bool backspaceCompare(string s, string t) {
        string s1 = stacked(s);
        string t1 = stacked(t);
        return s1 == t1;
    }
};
