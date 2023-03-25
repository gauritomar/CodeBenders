class Solution {
private:
    void rec(int n, int val, vector<string> &ans, string s){
        if(val == 0 && s.size() == 2*n){
            ans.push_back(s);
        }
        
        if(val > n){
            return ;
        }
        if(val < 0){
            return ;
        }
        if(s.size()> 2*n){
            return ;
        }
        
        
        s.push_back('(');
        rec(n, val+1, ans, s);
        s.pop_back();
        s.push_back(')');
        rec(n, val-1, ans, s);
        s.pop_back();

    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s;
        rec(n, 0, ans, s);
        return ans;
    }
};
