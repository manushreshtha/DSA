class Solution {
public:
    int maxarea(vector<int>&heights){
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
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        int row=matrix.size();
        int col=matrix[0].size();
        vector<int>heights(col,0);
        int ans=INT_MIN;
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(matrix[i][j]=='1'){
                    heights[j]++;
                }else{
                    heights[j]=0;
                }
            }
            ans=max(ans,maxarea(heights));
        }
        return ans;
    }
};