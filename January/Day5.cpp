/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 **/


class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL) return head;
        if(head->next == NULL) 
            return head;
        // 1, 2, 3, 3, 4, 4, 5
        ListNode* newHead = new ListNode(-200,head);
        ListNode * ptr1 = newHead->next, *ptr2 = newHead->next->next, *prev = newHead;
        while((ptr2 != NULL) && (ptr1 != NULL)){
            if((ptr1->val) == (ptr2->val)) {
                while((ptr2 != NULL ) && (ptr2->val == ptr1->val)) {
                    ptr2 = ptr2->next;
                }
                if(ptr2 != NULL) {
                    prev->next = ptr2;
                    ptr1 = ptr2;
                    ptr2 = ptr2->next;
                }
                else {
                    prev->next = ptr2;
                    return newHead->next;
                }
            }
            else {
                prev = ptr1;
                ptr1 = ptr2;
                ptr2 = ptr2->next;
            }
        }
        return newHead->next;
    }
};