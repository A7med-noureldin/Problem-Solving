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
        /*
         * Length of list A before intersection: a
         * Length of list B before intersection: b
         * Length of shared (intersecting) part: c
         * Total: A: a + c, B: b + c
         * When x reaches the end of list A, it jumps to headB.
         * When y reaches the end of list B, it jumps to headA.
         * They traverse the same total number of nodes: 
         * a + c + b == b + c + a
         * Therefore, they meet either:
                - At the intersection node, or
                - At NULL, if there's no intersection. 
         */
        ListNode* x = headA;
        ListNode* y = headB;
        while(x!=y){
            x = (x == NULL) ? headB : x->next;
            y = (y == NULL) ? headA : y->next;
        }
        return x;
    }
};