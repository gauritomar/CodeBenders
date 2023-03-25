class ProductOfNumbers {
public:
vector<int> vec;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        if(num!=0){
            vec.push_back(num);
        }
        else{
            vec.clear();
            vec.push_back(0);
        }
    }
    
    int getProduct(int k) {
        int x = vec.size() -1;
        int ans = 1;
        while(k--){
            ans = ans*vec[x];
            x--;
            if(ans==0){
                return 0;
            }
        }
        return ans;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
