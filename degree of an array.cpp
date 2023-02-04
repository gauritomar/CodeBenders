class Solution {
private:
    int sum(vector<int> vec){
        
        return vec.size();
    }
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, vector<int>> m;
        for(int i = 0; i < nums.size(); i++){
            m[nums[i]].push_back(i);
        }
        int d = 0;
        for(auto x: m){
            d = max(d, sum(x.second));
        }
        int ans = INT_MAX;

        for(auto x: m){
           if(sum(x.second)==d){
               
               ans = min(ans, x.second.back()-x.second.front());
           }
        }
        return ans+1;
    }
};
