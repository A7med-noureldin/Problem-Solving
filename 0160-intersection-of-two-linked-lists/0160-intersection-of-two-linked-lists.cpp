/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* x = headA;
        ListNode* y = headB;
        while(x!=y){
            x = (x == NULL) ? headB : x->next;
            y = (y == NULL) ? headA : y->next;
        }
        return x;
    }
};