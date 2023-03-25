class Solution {
    private:
    void recursive(vector<string> &ans, string output, string s, int index, vector<string> keypad){
        if(index == s.size()){
            ans.push_back(output);
            return ;
        }
        
         string str = keypad[s[index]];
        for(int i = 0; i < str.size(); i++){
            char ch = str[i];
            output.push_back(ch);
            recursive(ans, output, s, index+1, keypad);
            output.pop_back();
        }



    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> keypad = {"/", "/", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> ans;
    string output;
	recursive(ans, output, digits, 0, keypad);
    return ans;
    }
};
