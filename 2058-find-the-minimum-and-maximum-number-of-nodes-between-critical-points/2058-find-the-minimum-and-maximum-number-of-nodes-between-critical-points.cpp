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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int x = 1;
        ListNode* tmp = head;
        vector<int> v = {-1, -1};
        ListNode* nxt = NULL;
        if(head->next) nxt = head->next;
        else return v;

        auto valid = [&]() -> bool{
            return nxt->next && ((tmp->val < nxt->val && nxt->val > nxt->next->val) ||
                    (tmp->val > nxt->val && nxt->val < nxt->next->val)); 
        };

        int st = -1, prev = -1, mn = 1e9, mx = -1e9;
        while(nxt){
            if(nxt->next && valid()){
                if(prev != -1) mn = min(mn, x-prev);
                if(st == -1) st = x;
                if(st != -1) mx = max(mx, x-st); 
                prev = x;
            }
            tmp = tmp->next, nxt = nxt->next;
            x++;
        } 
        vector<int> ans;
        if(mn != 1e9) ans.push_back(mn);
        if(mx != -1e9) ans.push_back(mx); 
        if(ans.size() < 2) return v;
        return ans;
    }
};