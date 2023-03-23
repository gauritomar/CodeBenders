class Solution {
private:
int sum(vector<int> output){
    int sum = 0;
    for(int i = 0; i< output.size(); i++){
        sum += output[i];
    }
    return sum;
}

void helper(vector<int> candidates, int target, vector<vector<int>> &ans, vector<int> output, int index){
    if(sum(output)== target){
        ans.push_back(output);
        return ;
    }
    if(sum(output)> target){
        return ;
    }
    if(index >= candidates.size()){
        return ;
    }

    helper(candidates,target, ans, output,index+1);
    output.push_back(candidates[index]);
    helper(candidates,target, ans, output,index);

    output.pop_back();

}


public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
            vector<vector<int>> ans;
            vector<int> output ;
            int index = 0;

        helper(candidates,target, ans, output,index);
        return ans;
    }
};
