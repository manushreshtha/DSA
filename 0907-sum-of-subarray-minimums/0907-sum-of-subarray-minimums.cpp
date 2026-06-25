class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int>nse(n,n),pse(n,-1);
        stack<int>st;
        for(int i=0;i<arr.size();i++){
            while(!st.empty() && arr[i]<arr[st.top()]){
                nse[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()){
            st.pop();
        }
        for(int i=0; i<arr.size(); i++){
            while(!st.empty() && arr[i]<arr[st.top()]){
                st.pop();
            }
            if(!st.empty()){
                pse[i]=st.top();
            }
            st.push(i);
        }
        long long ans=0;
        for(int i=0;i<arr.size(); i++){
            long long left=i-pse[i];
            long long right=nse[i]-i;
            ans=(ans+(1LL*arr[i]*left*right)%1000000007)%1000000007;
        }
        return ans;
        
    }
};