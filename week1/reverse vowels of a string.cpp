class Solution {
private:
    bool isavowel(char c){
        if(c == 'a' || c == 'A' ){
            return true;
        }
        if(c == 'e' || c == 'E' ){
            return true;
        }
        if(c == 'i' || c == 'I' ){
            return true;
        }
        if(c == 'o' || c == 'O' ){
            return true;
        }
        if(c == 'u' || c == 'U' ){
            return true;
        }
        return false;
    }
public:
    string reverseVowels(string s) {
        int i = 0;
        int j = s.size()-1;
        while(i<j){
            while(i< j && !isavowel(s[i])){
                i++;
            }
            while(i< j && !isavowel(s[j])){
                j--;
            }
            swap(s[i], s[j]);
            i++;
            j--;
        }
        return s;
    }
};
