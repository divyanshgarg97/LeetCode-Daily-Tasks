/**
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
    struct mycomp{
        bool operator()(pair<int,ListNode*> a,pair<int,ListNode*> b) {
            return a.first > b.first;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        //ListNode * nothing = new ListNode();
        if(n == 0) return NULL;
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,mycomp> pq;
        for(auto i : lists) {
            if(i== NULL)  continue;
            pq.push({i->val,i});
        }
        ListNode* dummy = new ListNode(-1);
        ListNode * curr = dummy;
        while(pq.size() > 0) {
            auto temp = pq.top();
            pq.pop();
            curr->next = new ListNode(temp.first);
            curr= curr->next;
            if(temp.second->next == NULL) continue;
            pq.push({temp.second->next->val,temp.second->next});
        }
        return dummy->next;
    }
};