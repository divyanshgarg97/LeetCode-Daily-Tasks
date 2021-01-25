class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n = nums.size();
        bool ans = true;
        int ptr1 = -1;
        for(int i = 0 ;i < n;i++) {
            if(nums[i] == 1) {
                ptr1 = i;
                break;
            }
        }
        if(ptr1 == -1) {
            return true;
        }
        for(int i = ptr1+ 1; i < n ;i++) {
            if(nums[i] == 1) {
                if(i - ptr1 - 1 >=k) {
                    ptr1 = i;
                    continue;
                }
                else {
                    return false;
                }
            }
        }
        return ans;
    }
};