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
};