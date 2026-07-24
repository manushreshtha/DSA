class Solution {
public:
    vector<int>op;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        sort(candidates.begin(), candidates.end());
        solve(candidates,0,target,ans);
        return ans;
    }
    void solve(vector<int>& candidates, int i, int &target, vector<vector<int>>&ans){
        if(target==0){
            ans.push_back(op);
            return;
        }
        if(i==candidates.size()|| target<0){
            return;
        }
        for(int j=i; j<candidates.size(); j++){
            if(j>i && candidates[j]==candidates[j-1]) continue;
            op.push_back(candidates[j]);
            target=target-candidates[j];
            solve(candidates,j+1,target,ans);
            op.pop_back();
            target=target+candidates[j];
        }
        return;
    }
};