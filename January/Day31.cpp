class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n -2;
        for(i = n - 2; i >= 0 ; i-- ) {
            if(nums[i] < nums[i+1]) {
               break; 
            }
        }
        if(i ==  -1) {
            reverse(nums.begin(),nums.end());
            return;
        }
        reverse(nums.begin() + i + 1 , nums.end()) ; 
        auto itr = upper_bound(nums.begin() + i + 1, nums.end(), nums[i]) ;
        swap(*itr,nums[i]);
    }
};