// https://leetcode.com/problems/min-cost-climbing-stairs/

class Solution {
public:
    int minCostClimbingStairs(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,0);
        // mere yaha par pahuchne kaa kitna lagega
        dp[0] = 0; 
        dp[1] = 0;
        for(int i = 2; i < n;i++) {
            dp[i] = min(dp[i-1] + nums[i-1] , dp[i-2] + nums[i-2]);
        }
        return min(dp[n-1] + nums[n-1], dp[n-2] + nums[n-2]);
    }
};