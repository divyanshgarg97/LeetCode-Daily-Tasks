class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        bool dp[n+1][n+1];
        memset(dp,false,sizeof(dp));
        // fill for l = 1 i.e. like i =1 ,j=1
        // fill for l = 2 i.e. like i = 2, j = 3 ,, as i+1 and j -1 lies outside range
        int ansStart = 0;
        int ansLength = 1;
        for(int i = 0 ; i <= n;i++)
            dp[i][i] = true;
        for(int i = 0 ; i < n-1 ; i++) {
            if(s[i] == s[i+1]) {
                dp[i][i+1] = true;
                if(ansLength < 2) {
                    ansLength = 2;
                    ansStart = i;
                }
            }
            else dp[i][i+1] = false;
        }
        
        for(int l = 3; l <= n ;l++) {
            for(int i = 0 ; i < n - l + 1; i++) {
                int j = i + l - 1; 
                if(s[i] == s[j] && (dp[i+1][j-1] == true) ){
                    dp[i][j] = true; 
                    if(l > ansLength) {
                        ansLength = l;
                        ansStart = i;
                    }
                }
                else {
                    dp[i][j] = false;
                }
            }
        }
        string ans;
        for(int i = 0 ; i < ansLength ;i++) {
            ans += s[i + ansStart];
        }
        return ans;
        
    }
};