class Solution {

private:
    bool valid(string str){
        int i = 0;
        vector<string> num;
        string a;
        while(i<str.size() && str[i]!='.'){
            a+=str[i];
            i++;
        }
        
        i++;
        if(a.size()==0){
            return false;
        }
        string b;
        while(i<str.size() && str[i]!='.'){
            b+=str[i];
             i++;
        }
        if(b.size()==0){
            return false;
        }
        i++;
        string c;
         while(i<str.size() && str[i]!='.'){
            c+=str[i];
             i++;
        }
        if(c.size()==0){
            return false;
        }
        i++;
        string d;
        while(i<str.size() && str[i]!='.'){
            d+=str[i];
             i++;
        }
        if(d.size()==0){
            return false;
        }
        num.push_back(a);
        num.push_back(b);
        num.push_back(c);
        num.push_back(d);
        for(auto s: num){
            if(s.size()==0){
                return false;
            }
            if(s.size()>3){
            return false;}
            if(s.size()>1 && s[0]=='0'){
                return false;
            }
            int x = stoi(s);
            if(x<0 || x>255){
                return false;
            }
        }
        return true;

        
    }
    void rec(string s, vector<string>&ans, int index, int dots){

        if(dots==3){
            if(valid(s)){
                ans.push_back(s);
            }
            return;
        }
        if(index>=s.size()){
            return;
        }
        rec(s, ans, index+1, dots);
        string temp;
        for(int i = 0; i< index; i++){
            temp+=s[i];
        }
        temp+='.';
        for(int i = index; i<s.size();i++){
            temp+=s[i];
        }
        rec(temp, ans, index+1, dots+1);
    }
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        rec(s, ans, 0, 0);
        return ans;
    }
};
