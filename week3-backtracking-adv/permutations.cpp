class Solution {
private:
    void solve(vector<vector<int>> &ans, vector<int> nums, int index){
        if(index>=nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i = index; i <nums.size(); i++){
            swap(nums[index], nums[i]);
            solve(ans, nums, index+1);
            //backtrack
            swap(nums[index], nums[i]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        solve(ans, nums, 0);
        return ans;
    }
};
