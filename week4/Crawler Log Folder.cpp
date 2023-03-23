class Solution {
public:
    int minOperations(vector<string>& logs) {
        int steps = 0;
        for (auto log : logs){

        
        if (log == "../"){
            if(steps != 0){
               steps--;
            }
        }
           
        else if (log != "./")
            steps++;
        }
    return steps;
    }
};
