class Solution {
public:
    int maximumSwap(int num) {
        int k=1;
        string s = to_string(num);
        string res=s;
        solve(s,k,res,0);
        int ans=stoi(res);
        return ans;
    }
    void solve(string &s, int k, string &res, int start){
        if(k==0 || start==s.size()-1) return;
        int maxi=*max_element(s.begin()+start+1,s.end());
        for(int i=start+1; i<s.size(); i++){
            if(s[start]<s[i] && s[i]==maxi){
                swap(s[start],s[i]);
                if(s.compare(res)>0) res=s;
                solve(s,k-1,res,start+1);
                swap(s[start],s[i]);
            }
        }
        solve(s,k,res,start+1);
    }
};