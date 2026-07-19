class Solution {
public:
    set<string>ans;
    int numTilePossibilities(string tiles) {
        string op="";
        sort(tiles.begin(), tiles.end());
        solve(tiles,op);
        return ans.size();
    }
    void solve(string tiles, string op){
        if(tiles.size()==0){
            ans.insert(op);
            return;
        }
        for (int i = 0; i < tiles.size(); i++) {
            string newIp = tiles.substr(0, i) + tiles.substr(i + 1);
            string newOp = op + tiles[i];
            ans.insert(newOp);  
            solve(newIp, newOp);
        }
        return;
    }
};