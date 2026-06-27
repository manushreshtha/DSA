class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int>st;
        vector<int>nge(temperatures.size(), -1);
        for(int i=0; i<temperatures.size(); i++){
            while(!st.empty() && temperatures[i]>temperatures[st.top()]){
                nge[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        vector<int>ans;
        for(int i=0; i<temperatures.size(); i++){
            if(nge[i]==-1){
                ans.push_back(0);
            }else{
                ans.push_back(nge[i]-i);
            }         
        }
        return ans;
    }
};