class Solution {
public:
    vector<int>op;
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>candidates;
        vector<vector<int>>ans;
        for(int i=1; i<=9; i++){
            candidates.push_back(i);
        }
        solve(candidates,0,k,n,ans);
        return ans;
    }
    void solve(vector<int>& candidates, int i, int&k, int &n, vector<vector<int>>&ans){
        if(n==0 && k==0){
            ans.push_back(op);
            return;
        }
        if(i==candidates.size()|| k<0 || n<0){
            return;
        }
        for(int j=i; j<candidates.size(); j++){
            if(j>i && candidates[j]==candidates[j-1]) continue;
            op.push_back(candidates[j]);
            n=n-candidates[j];
            k=k-1;
            solve(candidates,j+1,k,n,ans);
            op.pop_back();
            n=n+candidates[j];
            k=k+1;
        }
        return;
    }
};