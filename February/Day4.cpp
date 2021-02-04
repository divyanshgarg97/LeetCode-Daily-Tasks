class Solution {
public:
    int findLHS(vector<int>& nums) {
        // O(n) , 1 Pass
        unordered_map<int,int> mp;
        int ans = 0;
        for(auto i : nums) {
            mp[i]++;
            if(mp.find(i-1)!= mp.end()) 
                ans = max(ans, mp[i] + mp[i-1]);
            if(mp.find(i+1)!= mp.end())
                ans = max(ans,mp[i] + mp[i+1]);
        }
        return ans;
        // // Time Complexity : n(for unordered_map) , 2 pass
        // unordered_map<int,int> mp;
        // for(auto i : nums) mp[i]++; // loop 1
        // int ans = 0;
        // for(auto i : mp){ // loop 2
        //     int val = i.first;
        //     if(mp.find(val + 1) != mp.end()) {
        //         ans = max(ans,i.second + mp[val+1]);
        //     }
        //     if(mp.find(val - 1) != mp.end()) {
        //         ans = max(ans,i.second + mp[val-1]);
        //     }
        // }
        // return ans;
        // Time Complexity : nlogn (for Map),2 pass
        // map<int,int> mp;
        // for(auto i : nums) mp[i]++;
        // int prev = - INT_MAX;
        // int ans = 0;
        // for(auto i : mp){
        //     if(prev == -INT_MAX) {
        //         prev = i.first;
        //     }
        //     else {
        //         if(abs(prev - i.first) == 1) {
        //             ans = max(ans,mp[prev] + i.second);
        //         }
        //         prev = i.first;
        //     }
        // }
        // return ans;
    }
};