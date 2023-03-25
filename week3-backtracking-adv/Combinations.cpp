class Solution {
vector<vector<int>> ans;
private:  
    void helper(int i, int n, int k, vector<int> output){
        if(output.size()==k){
            ans.push_back(output);
            return;
        }
        if(i >n){
            return;
        }
        
        for(int x = i; x<=n; x++){
            output.push_back(x);
            helper(x+1, n, k, output);
            output.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        
        vector<int> output;
        helper(1, n, k, output);
        return ans;

    }
};
//another approach that gave me a TLE
class Solution {
private:
void helper(int index, vector<vector<int>> &ans, vector<int> output, int n, int k){
    if(output.size()== k && index>=n){
        ans.push_back(output);
        return;
    }
    if(index>n){
        return;
    }



    //exclude
    helper(index+1, ans, output, n, k);
    //include
    output.push_back(index);
    helper(index+1, ans, output, n, k);


}

public:
    vector<vector<int>> combine(int n, int k) {
        int index;
        vector<vector<int>> ans;
        vector<int> output;
        helper(1, ans, output, n, k);
        return ans;
    }
};
