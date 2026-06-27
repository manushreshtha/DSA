class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        for(int i:s){
            mp[i]++;
        }
        vector<pair<char,int>>v(mp.begin(), mp.end());
        sort(v.begin(), v.end(), [](pair<char,int>&a, pair<char,int>&b){
            return a.second>b.second;
        });
        string ans="";
        for(auto c:v){
            ans.append(c.second,c.first);
        }
        return ans;
    }
};