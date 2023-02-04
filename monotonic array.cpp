// https://leetcode.com/problems/monotonic-array/
class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool increase = true;
        bool decrease = true;
        for(int i = 0; i < nums.size() ; i++) {
            if(A[i] > A[i+1]) increase = false;

            if(A[i] < A[i+1]) decrease = false;
            
            if(increase == false && decrease == false) return false;
        }
        return true;
    }
};
