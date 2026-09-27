class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> stk;
        string ans = "";
        for(auto c : s){
            if(c == '('){
                stk.push(ans.size());
            }
            else if(c == ')'){
                int sz = stk.top(); stk.pop();
                reverse(ans.begin()+sz, ans.end());
            }
            else{
                ans += c;
            }
        }
        return ans;
    }
};