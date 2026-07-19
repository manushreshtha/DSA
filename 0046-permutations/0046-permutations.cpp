class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>v;
        vector<int>op;
        solve(nums,op,v);
        return v;
    }
    void solve(vector<int>nums, vector<int>op, vector<vector<int>>&v){
        if(nums.size()==0){
            v.push_back(op);
            return;
        }
        for(int i=0; i<nums.size(); i++){
            vector<int>newIp;
            newIp.insert(newIp.end(), nums.begin(), nums.begin() + i);
            newIp.insert(newIp.end(), nums.begin() + i + 1, nums.end());
            vector<int> newOp = op;
            newOp.push_back(nums[i]);
            solve(newIp,newOp,v);
        }
        return;
    }
};