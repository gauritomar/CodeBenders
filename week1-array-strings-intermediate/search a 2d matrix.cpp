class Solution {
private:
    bool search(vector<vector<int>>&mat, int i, int j, int target){
        if(i<0 || j>=mat[0].size()){
            return false;
        }
        if(mat[i][j]==target){
            return true;
        }
        if(mat[i][j]<target){
            return search(mat, i, j+1, target);
        }
        else{
            return search(mat, i-1, j, target);
        }
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        return search(matrix, n-1, 0, target);
    }
};
