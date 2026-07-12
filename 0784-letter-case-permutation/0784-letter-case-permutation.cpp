class Solution {
public:
    vector<string>ans;
    vector<string> letterCasePermutation(string s) {
        string op="";
        solve(s,op);
        return ans;
    }
    void solve(string s, string op){
        if(s.size()==0){
            ans.push_back(op);
            return;
        }
        if(isalpha(s[0])){
            string op1=op;
            string op2=op;
            op1.push_back(tolower(s[0]));
            op2.push_back(toupper(s[0]));
            s.erase(s.begin()+0);
            solve(s,op1);
            solve(s,op2);
            return;
        }else{
            op.push_back(s[0]);
            s.erase(s.begin()+0);
            solve(s,op);
            return;
        }
    }
};