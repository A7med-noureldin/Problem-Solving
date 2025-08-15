class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> stk;
        set<int> v;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(')stk.push(i);
            if(s[i] == ')'){
                if(!stk.empty())stk.pop();
                else v.insert(i);
            }
        }
        string ans = "";
        while(!stk.empty()){
            v.insert(stk.top());
            stk.pop();
        }
        for(int i = 0; i < s.size(); i++){
            if(v.count(i))continue;
            ans += s[i];
        }
        return ans;
    }
};