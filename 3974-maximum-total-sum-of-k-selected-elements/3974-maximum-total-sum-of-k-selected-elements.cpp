class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        long long maxsum=0;
        sort(nums.begin(), nums.end(), greater<int>());
        for(int i=0; i<nums.size(); i++){
            if(k==0) break;          
            if(mul>0){
                maxsum=max(maxsum+ 1LL*mul*nums[i], maxsum+nums[i]);
            }else{
                maxsum=maxsum+nums[i];               
            }
            k--;
            mul--;
        }
        return maxsum;
    }
};