class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        int ptr1 = 0;
        int ptr2 = n - 1;
        sort(people.begin(),people.end(),greater<int>());
        int ans=0;
        while(ptr1 <= ptr2){
            if(ptr1 == ptr2) {
                return ans+1;
            }
            else{
                if(people[ptr1] + people[ptr2] <= limit) {
                    ans ++;
                    ptr1++;
                    ptr2--;
                }
                else {
                    ans++;
                    ptr1++;
                }
            }
        }
        return ans;
    }
};