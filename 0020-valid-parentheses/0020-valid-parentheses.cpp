class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,int> mp={{'(',-1}, {'{',-2}, {'[',-3}, {')',1}, {'}',2}, {']',3}};
        stack<int>st;
        for(auto i:s){
            if(mp[i]<0){
                st.push(i);
            }else{
                if(st.empty()) return false;
                char top=st.top();
                st.pop();
                if(mp[top]+mp[i]!=0) return false;
            }

        }
        return st.empty();
    }
};