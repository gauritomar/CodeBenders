class Solution {
private:
    bool func(int n){
        if(n==1){
            return true;
        }
        if(n%3 ==0){
            return func(n/3);
        }
        else{
            return false;
        }
    }
public:
    bool isPowerOfThree(int n) {
        if(n<=0){
            return false;
        }
        if(n<1){
            n= 1/n;
        }
        return func(n);
    }
};
