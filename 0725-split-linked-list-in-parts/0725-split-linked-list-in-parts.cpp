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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = 0;
        ListNode* tmp = head;
        while(tmp != NULL){
            n++;
            tmp = tmp->next;
        }

        vector<ListNode*> ans(k, NULL);
        if(n == 0) return ans;
        ListNode* curr = head;
        int Size = n / k, extra = n % k;

        for(int i = 0; i < k && curr != NULL; i++){
            ans[i] = curr;
            int x = Size;
            x += (extra > 0);
            if(extra)extra--;
            
            for(int j = 1; j < x; j++){
               if(curr) curr = curr->next; 
            }
            
            if(curr){
                ListNode* nextPart = curr->next;
                curr->next = nullptr;
                curr = nextPart;
            }
        }
        return ans;
    }
};