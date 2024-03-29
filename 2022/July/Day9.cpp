//  https://leetcode.com/problems/jump-game-vi/

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        if(nums.size()==1)return nums[0];
        vector<int>dp(nums.size(),INT_MIN);
        multiset<int>Q;
        dp[0] = nums[0];
        Q.insert(dp[0]);
        for(int i = 1;i<nums.size();i++){
            if(Q.size()>k){
                auto it = Q.find(dp[i-k-1]);
                Q.erase(it);
            }
            dp[i] = max(*Q.rbegin()+nums[i],dp[i]);
            Q.insert(dp[i]);
        }
        return dp[nums.size()-1];
    }
};