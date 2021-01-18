class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // make a min heap , smaller than heap main value then ignore , if not then put
        priority_queue<int,vector<int> , greater<int> > pq;
        for(auto i : nums) {
            if(pq.size() < k) {
                pq.push(i);
            }
            else {
                if(i < pq.top()){
                    //ignore
                }
                else {
                    pq.pop();
                    pq.push(i);
                }
            }
        }
        return pq.top();
    }
};