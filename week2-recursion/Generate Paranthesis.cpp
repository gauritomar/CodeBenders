class Solution {
private:
    void recursive(vector<vector<int>> &ans, vector<int> &output, vector<int> candidates, int target,int index, int summtillnow){
        if(summtillnow == target){
            ans.push_back(output);
            return;
        }
        if(summtillnow > target){
            return ;
        }
        if(index >= candidates.size()){
            return ;
        }

        output.push_back(candidates[index]);
        summtillnow += candidates[index];
        recursive(ans, output, candidates, target, index+1, summtillnow);
        output.pop_back();
        summtillnow -= candidates[index];

        while(index < candidates.size()-1 && candidates[index+1]== candidates[index]){
            index++;
        }
        recursive(ans, output, candidates, target, index+1, summtillnow);


    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> output;
        sort(candidates.begin(), candidates.end());
        recursive(ans, output, candidates, target, 0, 0);
        
        return ans;
    }
};
