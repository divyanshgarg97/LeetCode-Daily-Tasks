class Solution {
public:
    int ans = 0;
    int maxN;
    void solve(int posToFill,vector<int> filled,vector<int> vis){
        if(filled.size() == maxN) {
            ans++;
            return;
        }
        for(int i = 1; i <= maxN;i++) {
            if(vis[i] == -1 && (posToFill%i==0 || i%posToFill==0)){
                vis[i] = 1;
                filled.push_back(i);
                solve(posToFill+1,filled,vis);
                vis[i] = -1;
                filled.pop_back();
            }
        }
    }
    int countArrangement(int n) {
        maxN = n;
        // posToFill , this can be filled with anyone from 1 to n such that anyone condition is true
        vector<int> vis(n+1,-1);
        solve(1,{},vis);
        return ans;
    }
}/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* newStartNode = new ListNode();
        ListNode* ptr1 = l1;
        ListNode* ptr2 = l2;
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        ListNode* currNode = newStartNode->next;
        ListNode* prevNode = newStartNode;
        while(ptr1 != NULL && ptr2!= NULL) {
            if(ptr1->val == ptr2->val ) {
                prevNode->next = ptr1;
                ptr1= ptr1->next;
                prevNode = prevNode ->next;
            }
            else if(ptr1->val < ptr2->val) {
                prevNode->next = ptr1;
                ptr1= ptr1->next;
                prevNode = prevNode->next;
            }
            else {
                prevNode->next = ptr2;
                ptr2 = ptr2->next;
                prevNode = prevNode->next;
            }
        }
        if(ptr1 == NULL && ptr2 == NULL) {
            return newStartNode->next;
        }
        else if(ptr1 == NULL) {
            prevNode->next = ptr2;
            return newStartNode->next;
        }
        prevNode->next = ptr1;
        return newStartNode->next;
        
        
        
        
        
        
        
        //return newStartNode->next;
    }
};