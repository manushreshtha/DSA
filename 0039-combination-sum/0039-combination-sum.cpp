class Solution {
public:
    vector<int>op;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        solve(candidates,0,target,ans);
        return ans;
    }
    void solve(vector<int>& candidates, int i, int &target, vector<vector<int>>&ans){
        if(i==candidates.size()|| target<0){
            return;
        }
        if(target==0){
            ans.push_back(op);
            return;
        }
        op.push_back(candidates[i]);
        target=target-candidates[i];
        solve(candidates,i,target,ans);
        op.pop_back();
        target=target+candidates[i];
        solve(candidates,i+1,target,ans);
        return;
    }
};