class Solution {
public:
    string removeOuterParentheses(string s) {
        int on = 0;
        string ans = "";
        for(auto c : s){
            if(c == ')') on--;
            if(on) ans += c;
            if(c == '(') on++;
        }
        return ans;
    }
};