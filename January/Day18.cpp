class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int> ump;
        for(auto i : nums) ump[i]++;
        int ans=0;
        for(auto i : nums){
            if((k-i) != i){
                if(ump[i] > 0 && (ump[k-i] > 0)) {
                    ans++;
                    ump[i]--;
                    ump[k-i]--;
                }
            }
            else if(ump[i] > 1) {
                ans++;
                ump[i] -=2;
            }
        }
        return ans;
    }
};