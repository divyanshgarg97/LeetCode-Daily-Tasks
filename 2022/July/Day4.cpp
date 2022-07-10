// https://leetcode.com/problems/candy/

class Solution {
public:
    int candy(vector<int>& ratings) {
        // each child must have at least one candy 
        int n = ratings.size();
        vector<int> ans(n,1);
        for(int i = 1; i < n;i++) {
            if(ratings[i] > ratings[i-1]) 
                ans[i] = ans[i-1] + 1;
        }
        for(int i = n - 2; i >= 0 ; i--) {
            if(ratings[i] > ratings[i+1] && ans[i] <= ans[i+1]) 
                ans[i] = ans[i+1] + 1; 
        }
        for(int j : ans) cout << j << " ";
        int sum = 0; for(int j : ans) sum +=j;
        return sum;
    }
};