// https://leetcode.com/problems/longest-consecutive-sequence/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // needs to be O(n)
        //      cannot sort them
        //      nums[i] can reach until 10^9, cannot use cyclic sort 
        // Logic to solve is lets try to find the longest consecutive sequence starting from me.
        // If someone before me existed then don't check for me, as it will definitely be covered in that previous one sequence
        int n = nums.size();
        if(n == 0) return 0;
        unordered_set<int> us;
        for(int i= 0 ;i < n;i++) {
            us.insert(nums[i]);
        }
        int ans = 1; 
        for(int i = 0 ;i < n;i++) {
            // starting a sequence from nums[i];
            int curr = nums[i];
            int prev = curr - 1;
            int temp = 1; 
            if(us.find(prev) != us.end()) {
                // we have found the previous one , lets not do anything
            }
            else {
                int nxt = curr + 1;
                while(us.find(nxt) != us.end()) {
                    nxt+=1;
                    temp += 1;
                    if(temp > ans) 
                        ans = temp;
                }
            }
        }
        return ans;
        
    }
};