class Solution {
private:
    int maxdfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>&visited){
        if(i<0 || j< 0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==0 || visited[i][j]==1){
            return 0;
        }
        visited[i][j]=1;
        int a = maxdfs(i+1, j, grid, visited);
        int b = maxdfs(i, j+1, grid, visited);
        int c = maxdfs(i-1, j, grid, visited);
        int d = maxdfs(i ,j-1, grid, visited);
        int max_val = max(max(a, b), max(c, d));
        visited[i][j]=0;
        return grid[i][j]+ max_val;
    }
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j]!=0){
                    vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));
                    ans = max(ans, maxdfs(i, j, grid, visited));
                }
            }
        }
        return ans;

    }
};

//Another submission without backtracking that gave TLE
class Solution {
private:
    int maxdfs(int i, int j, vector<vector<int>> grid){
        if(i<0 || j< 0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==0){
            return 0;
        }
        int x = grid[i][j];
        grid[i][j]= 0;
        int a = maxdfs(i+1, j, grid);
        int b = maxdfs(i, j+1, grid);
        int c = maxdfs(i-1, j, grid);
        int d = maxdfs(i ,j-1, grid);
        int max_val = max(max(a, b), max(c, d));
        return x+ max_val;
    }
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        vector<int> ans;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j]!=0){
                    ans.push_back(maxdfs(i, j, grid));
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans.back();

    }
};
