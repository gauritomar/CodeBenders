class Solution {
private:
    bool dfs(int i, int j, string word, vector<vector<char>> &board,vector<vector<int>>& visited, int index){
        
        if(i< 0|| j< 0|| i>=board.size() || j>=board[0].size() || board[i][j]!=word[index] || visited[i][j]==1){
            return false;
        }
        if(index== word.size()-1){
            return true;
        }
        visited[i][j]=1;
        bool a = dfs(i+1,j, word, board, visited, index+1);
        bool b = dfs(i, j+1, word, board, visited, index+1);
        bool c = dfs(i-1, j, word, board, visited, index+1);
        bool d = dfs(i, j-1, word, board, visited, index+1);
        visited[i][j]=0;
        return a||b||c||d;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int ch = word[0];
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j< board[0].size(); j++){
                if(board[i][j]==ch){
                    vector<vector<int>> visited (board.size(), vector<int>(board[0].size(), 0));
                    bool ans = dfs(i, j , word, board, visited, 0);
                    if(ans == true){
                        return true;
                    }
                }
            }
        }
        return false;
        
    }
};
