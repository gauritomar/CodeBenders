class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> ans;
        if(prices.size()==1){
            return prices;
        }
        if(prices.size()==2){
            if(prices[1]<= prices[0]){
                prices[0] = prices[0]-prices[1];
                return prices;
            }
            else return prices;
        }
        for(int i = 0; i < prices.size()-1; i++){
            int temp = prices[i];
            for(int j = i+1; j< prices.size();j++){
                if(prices[j]<= prices[i]){
                    temp = prices[i]- prices[j];
                    break;
                }
            }
            ans.push_back(temp);
        }
        ans.push_back(prices.back());
        return ans;
    }
};
