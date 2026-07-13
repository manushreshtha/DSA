class Solution {
public:
    set<vector<int>>ans;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>op;
        sort(nums.begin(), nums.end());
        solve(nums,op);
        vector<vector<int>>answer;
        for(auto i:ans){
            answer.push_back(i);
        }
        return answer;
    }
    void solve(vector<int>nums, vector<int>op){
        if(nums.size()==0){
            ans.insert(op);
            return;
        }
        vector<int>op1=op;
        vector<int>op2=op;
        op2.push_back(nums[0]);
        nums.erase(nums.begin()+0);
        solve(nums,op1);
        solve(nums,op2);
        return;
    }
};