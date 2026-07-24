class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int>ans;
        unordered_map<int,int>mp;
        int mini=int(nums.size()/3)+1;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
            if(mp[nums[i]]==mini){
                ans.push_back(nums[i]);
            }
            if(ans.size()==2) break;
        }
        return ans;
    }
};