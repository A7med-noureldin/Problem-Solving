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
    ListNode *detectCycle(ListNode *head) {
        ListNode* s = head;
        ListNode* f = head;
        bool cycle = false;
        while(f && f->next){
            f = f->next->next;
            s = s->next;
            if(f == s){
                cycle = true;
                break;
            }
        }
        
        if(!cycle) return NULL;
        
        s = head;
        while(s != f){
            s = s->next;
            f = f->next;
        }
        return f;
    }
};