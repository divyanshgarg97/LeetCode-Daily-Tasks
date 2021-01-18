class Solution {
public:
    int ans = 0;
    int maxN;
    void solve(int posToFill,vector<int> filled,vector<int> vis){
        if(filled.size() == maxN) {
            ans++;
            return;
        }
        for(int i = 1; i <= maxN;i++) {
            if(vis[i] == -1 && (posToFill%i==0 || i%posToFill==0)){
                vis[i] = 1;
                filled.push_back(i);
                solve(posToFill+1,filled,vis);
                vis[i] = -1;
                filled.pop_back();
            }
        }
    }
    int countArrangement(int n) {
        maxN = n;
        // posToFill , this can be filled with anyone from 1 to n such that anyone condition is true
        vector<int> vis(n+1,-1);
        solve(1,{},vis);
        return ans;
    }
};