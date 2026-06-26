class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        stack<int>st;
        vector<int>pse(n,-1), nse(n,n), nge(n,n), pge(n,-1);
        for(int i=0; i<nums.size(); i++){
            while(!st.empty() && nums[st.top()]>nums[i]){
                st.pop();
            }
            if(!st.empty()){
                pse[i]=st.top();
            }
            st.push(i);
        }
        while(!st.empty()){
            st.pop();
        }
        for(int i=0; i<nums.size(); i++){
            while(!st.empty() && nums[i]<nums[st.top()]){
                nse[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()){
            st.pop();
        }
        for(int i=0; i<nums.size(); i++){
            while(!st.empty() && nums[i]>nums[st.top()]){
                st.pop();
            }
            if(!st.empty()){
                pge[i]=st.top();
            }
            st.push(i);
        }
        while(!st.empty()){
            st.pop();
        }
        for(int i=0 ; i<nums.size(); i++){
            while(!st.empty() && nums[i]>nums[st.top()]){
                nge[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        long long ans=0;
        for(int i=0; i<nums.size(); i++){
            long long left1=i-pse[i];
            long long right1=nse[i]-i;
            long long mini= 1LL*nums[i]*left1*right1;
            long long left2=i-pge[i];
            long long right2=nge[i]-i;
            long long maxi= 1LL*nums[i]*left2*right2;
            
            ans=ans+(maxi-mini);

        }
        return ans;
    }
};