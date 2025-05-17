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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head)return NULL;

        map<int, int> mp;
        ListNode* dummy = head;
        mp[head->val]++;
        while(dummy->next != NULL){
            if(mp.find(dummy->next->val) == mp.end()){
                mp[dummy->next->val]++;
                dummy = dummy->next;
            }
            else dummy->next = dummy->next->next;
        }
        return head;
    }
};