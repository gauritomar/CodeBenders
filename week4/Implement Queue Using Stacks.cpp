class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        while(!s1.empty()){
            int i = s1.top();
            s2.push(i);
            s1.pop();
        }
        int ans = s2.top();
        s2.pop();
        while(!s2.empty()){
            int i = s2.top();
            s1.push(i);
            s2.pop();
        }
        return ans;
    }
    
    int peek() {
        while(!s1.empty()){
            int i = s1.top();
            s2.push(i);
            s1.pop();
        }
        int ans = s2.top();
        while(!s2.empty()){
            int i = s2.top();
            s1.push(i);
            s2.pop();
        }
        return ans;
        
    }
    
    bool empty() {
        return s1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
