class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> q;
        for(int i =1; i <=n; i++){
            q.push(i);
        }
        while(q.size()>1){
            int d = k-1;
            while(d--){
                int top = q.front();
                q.pop();
                q.push(top);
            }
            q.pop();
            if(q.size()==1){
                return q.front();
            }
        }
        return q.front();
    }
};
