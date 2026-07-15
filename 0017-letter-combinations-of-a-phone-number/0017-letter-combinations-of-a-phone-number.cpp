class Solution {
public:
    vector<string>ans;
    unordered_map<char,string>mp={{'2', "abc"},{'3', "def"},{'4', "ghi"},{'5', "jkl"},{'6', "mno"},{'7', "pqrs"},{'8', "tuv"},{'9', "wxyz"}};
    vector<string> letterCombinations(string digits){
        string op="";
        solve(digits,op);
        return ans;
    }
    void solve(string digits, string op){
        if(digits.size()==0){
            ans.push_back(op);
            return;
        }
        char digit=digits[0];
        digits.erase(digits.begin()+0);
        for(char ch:mp[digit]){
            string op1=op;
            op1.push_back(ch);
            solve(digits,op1);
        }
        return;
    }
};