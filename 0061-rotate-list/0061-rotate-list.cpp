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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || k == 0 || !head->next) return head;
        int n = 1;
        ListNode* tail = head;

        while(tail->next) n++, tail = tail->next;
        k %= n;
        if(k == 0) return head;

        tail->next = head;
        int x = n-k-1;
        ListNode* nTail = head;

        while(x--){
            nTail = nTail->next;
        }

        ListNode* nHead = nTail->next;
        nTail->next = nullptr;
        return nHead; 
    }
};