class RecentCounter {
public:
    vector<int> vec;
    RecentCounter() {
        
    }
    
    int ping(int t) {
        vec.push_back(t);


        int x = vec.back()-3000;
        int s = 0;
        int e = vec.size()-1;
        int ans = e;
        while(s<=e){
            int mid = (s+e)/2;
            if(vec[mid]>=x){
                ans = mid;
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }
        return vec.size()-ans;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
