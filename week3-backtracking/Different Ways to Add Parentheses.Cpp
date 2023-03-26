//backtracking approach
class Solution {
private:
    vector<int> solve(string s){
        vector<int> ans;
        for(int i = 0; i < s.size(); i++){
            if(s[i]=='+' || s[i]=='-' || s[i]=='*'){
                vector<int> left = solve(s.substr(0, i));
                vector<int> right = solve(s.substr(i+1));
                for(auto x: left){
                    for(auto y : right){
                        if(s[i]=='+'){
                            ans.push_back(x+y);
                        }
                         if(s[i]=='-'){
                            ans.push_back(x-y);
                        }
                         if(s[i]=='*'){
                            ans.push_back(x*y);
                        }
                    }
                }
            }
        }
        if(ans.size()==0){
            int num = stoi(s);
            ans.push_back(num);

        }
        return ans;
    }
public:
    vector<int> diffWaysToCompute(string expression) {
        return solve(expression);
    }
};
//added DP to improve space complexity
class Solution {
unordered_map<string, vector<int>> val;
private:
    vector<int> solve(string s){
        if(val.find(s)!=val.end()){
            return val[s];
        }
        vector<int> ans;
        for(int i = 0; i < s.size(); i++){
            if(s[i]=='+' || s[i]=='-' || s[i]=='*'){
                vector<int> left = solve(s.substr(0, i));
                vector<int> right = solve(s.substr(i+1));
                for(auto x: left){
                    for(auto y : right){
                        if(s[i]=='+'){
                            ans.push_back(x+y);
                        }
                         if(s[i]=='-'){
                            ans.push_back(x-y);
                        }
                         if(s[i]=='*'){
                            ans.push_back(x*y);
                        }
                    }
                }
            }
        }
        if(ans.size()==0){
            int num = stoi(s);
            ans.push_back(num);

        }
        val[s]=ans;
        return ans;
    }
public:
    vector<int> diffWaysToCompute(string expression) {
        return solve(expression);
    }
};
