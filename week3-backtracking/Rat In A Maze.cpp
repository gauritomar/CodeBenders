//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    vector<string> ans;
    private:
    void dfs(vector<vector<int>>&m, vector<vector<bool>>& visited, int i, int j, string str){
        if(i<0 || j<0 || i>=m.size() || j>=m[0].size() || visited[i][j]==1 || m[i][j]==0){
            return;
        }
        int n = m.size();
        if(i==n-1 && j== n-1){
            ans.push_back(str);
            return;
        }
        visited[i][j]=1;
        
        
    
        str+='L';
        dfs(m, visited, i, j-1, str);
        str.pop_back();
        
        str+='U';
        dfs(m, visited, i-1, j, str);
        str.pop_back();
        
        
        str+='D';
        dfs(m, visited, i+1, j, str);
        str.pop_back();
        
        str+='R';
        dfs(m, visited, i, j+1, str);
        str.pop_back();
        
            visited[i][j]=0;
        
    }
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        
        vector<vector<bool>>visited(n, vector<bool>(n, 0));
        string str;
        dfs(m, visited, 0, 0, str);
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
