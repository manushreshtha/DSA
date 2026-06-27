class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>pse(n,-1), nse(n,n);
        stack<int>st;
        for(int i=0; i<heights.size(); i++){
            while(!st.empty() && heights[i]<heights[st.top()]){
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
        for(int i=0; i<heights.size(); i++){
            while(!st.empty() && heights[i]<heights[st.top()]){
                nse[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        int ans=INT_MIN;
        for(int i=0; i<heights.size(); i++){
            int left=i-pse[i];
            int right=nse[i]-i;
            ans=max(ans, heights[i]*(left+right-1));
        }
        return ans;
    }
};