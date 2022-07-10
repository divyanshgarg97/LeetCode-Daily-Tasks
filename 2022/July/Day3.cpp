// https://leetcode.com/problems/wiggle-subsequence/
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        // up[i] = ans when last two numbers are increasing, that is diff is positive nums[i] - nums[i-1] > 0
        // down[i] = ans when last two numbers are decreasing, that is diff is negative nums[i] - nums[i-1] < 0
        
        
        int n = nums.size();
        int up[n];
        int down[n];
        up[0] = 1;
        down[0] = 1;
        for(int i = 1; i < n; i++) {
            if(nums[i] == nums[i-1] ) {
                // basically just delete this number, hence old values are taken 
                up[i] = up[i-1];
                down[i] = down[i-1];
            }
            else if(nums[i] - nums[i-1] > 0) {
                up[i] = down[i-1] + 1;
                down[i] = down[i-1];
            }
            else {
                up[i] = up[i-1];
                down[i] = up[i-1] + 1;
            }
        }
        return max(up[n-1], down[n-1]);
    }
};