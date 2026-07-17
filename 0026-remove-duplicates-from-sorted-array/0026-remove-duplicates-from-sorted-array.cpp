class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        int j=0;
        while(i<nums.size() && j<nums.size()){
            if(nums[i]!=nums[j]){
                i++;
                swap(nums[i], nums[j]);
                j++;
            }else{
                j++;
            }
        }
        return i+1;
    }
};