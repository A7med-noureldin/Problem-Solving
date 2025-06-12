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
    ListNode* split(ListNode* head){
        ListNode* f = head;
        ListNode* s = head;

        while(f && f->next){
            f = f->next->next;
            if (f != NULL) {
                s = s->next;
            }
        }

        ListNode* temp = s->next;
        s->next = NULL;
        return temp;
    }
    ListNode* merge(ListNode* head, ListNode* second){
        if (head == nullptr) return second;
        if (second == nullptr) return head;
        if(head->val <= second->val){
            head->next = merge(head->next, second);
            return head;
        }
        else{
            second->next = merge(head, second->next);
            return second;
        }
    }
    ListNode* mergeSort(ListNode* head){
        if (head == NULL || head->next == NULL)
            return head;
        ListNode* second = split(head);
        head = mergeSort(head);
        second = mergeSort(second);
        return merge(head, second);
    }
    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }
};