class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans;
        for(int i = 0 ;i < n ;i++) {
            ans += 'a';
            k-=1;
        }
        int i = 0 ;
        while( k > 25){
            ans[i] = ans[i] + 25;
            k -= 25;
            i++;
        }
        if(k == 0) {
            reverse(ans.begin(),ans.end());
            return ans;
        }
        if(k > 0) {
            ans[i] = ans[i] + k;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};