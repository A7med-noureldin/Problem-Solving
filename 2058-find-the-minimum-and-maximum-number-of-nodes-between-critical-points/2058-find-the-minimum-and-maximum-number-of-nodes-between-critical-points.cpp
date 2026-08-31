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

        vector<int> points;
        while(nxt){
            if(nxt->next && valid()){
                points.push_back(x);
            }
            tmp = tmp->next, nxt = nxt->next;
            x++;
        } 
        if(points.size() < 2) return v;
        sort(points.begin(), points.end());
        int mx = points.back()-points[0];
        int mn = 1e9;
        for(int i = 1; i < points.size(); i++){
            mn = min(mn, points[i]-points[i-1]);
        }
        vector<int> ans = {mn, mx};
        return ans;
    }
};