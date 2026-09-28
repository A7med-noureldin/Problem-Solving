class Solution {
public:
    int maxDepth(string s) {
        stack<char> stk;
        int ans = 0;
        for(auto c : s){
            if(c == '(') stk.push('(');
            else if(c == ')'){
                ans = max(ans, (int)stk.size());
                stk.pop();
            }
        }
        return ans;
    }
};