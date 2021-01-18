class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        // divide array like:-
        // Deleted Sum from First side + Array elements not Deleted + Deleted Sum from Right Side
        // so we need to maximize the length of Middle not deleted portion
        // the deleted values sum would be x
        // Middle portion sum will be TotalSum - x;
        // thus question is reduced to find the longest subarray with sum = TotalSum - x;
        long n = nums.size();
        long sumFind = -x;
        for(auto i : nums) sumFind +=i;
        if(sumFind == 0) return n;
        long ans = -1;
        long currSum = 0;
        unordered_map<long,long> mp;
        mp[0] = -1;// 0 sum ka matlab , ki -1 yaani 0 index se bhi pehle mil gya the ye
        for(int i = 0 ; i < n;i++) {
            currSum += nums[i];
            if(currSum < sumFind){
                mp[currSum] = i;
            }
            else {
                //cout<<"CUrr Sum" << " " << currSum << endl;
                //cout<< "Sum Find" << " " << sumFind << endl;
                long extra = currSum - sumFind;
                //cout<< "EXtra" << " " << extra << endl;
                // what if extra is zero , then we need to store indexing as mp[0] = -1 as well
                if(mp.find(extra) != mp.end()){
                    ///cout<< "HERE" << extra << endl;
                    ans = max(ans, i - mp[extra]);
                    // mean mil gya extra tak sum
                    // 1 2 3  4  5  6  7
                    // 1 3 6 10 15 21 28
                    // 0 1 2 3  4  5  6
                }
                mp[currSum] = i;
            }
        
        }
        if(ans == -1) return -1;
        return n - ans;
    }
};