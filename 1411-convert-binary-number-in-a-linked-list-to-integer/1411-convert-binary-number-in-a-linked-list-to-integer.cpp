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
    int getDecimalValue(ListNode* head) {
        string s = "";
        while(head != NULL){
            s += to_string(head->val);
            head = head->next;
        }
        cout << s << '\n';
        int ans = 0;
        for(int i = s.size()-1, j = 0; i >= 0; i--, j++){
            cout << s[i] << ' ' << j << '\n';
            if(s[i]-'0') ans += pow(2, j);
        }
        return ans;
    }
};