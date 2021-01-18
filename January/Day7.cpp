class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int hash[1001];
        memset(hash,0,sizeof(hash));
        for(auto i : arr) {
            hash[i] ++;
        }
        for(int i =  1; i <= 1000 ; i++) {
            if(hash[i] == 0) {
                k--;
                if(k==0) 
                    return i;
            }
        }
        if(k>0) {
            int twice = 1000;
            while(k>0) {
                twice++;
                k--;
                if(k==0) 
                    return twice;
            }
        }
        return -1;
    }
}class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if(n == 0 || n == 1) return n;
        int anse = 0;
        int anss = 0;
        int low = 0;
        int high = 0;
        unordered_set<int> us;
        for(high = 0 ;high < n;high ++ ) {
            if(us.find(s[high]) == us.end()) {
                us.insert(s[high]);
                if(anse - anss < (high - low + 1)) {
                    anse = high + 1;
                    anss = low ;
                }
            }
            else {
                while(us.find(s[high]) != us.end()) {
                    us.erase(s[low]);
                    low++;
                }
                us.insert(s[high]);
            }
        }
        return (anse - anss);
    }
};