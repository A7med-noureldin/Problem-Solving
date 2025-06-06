class Solution {
public:
    string robotWithString(string s) {
        int n = s.size();
        stack<char> stk;
        map<char, int> mp;
        for(auto c : s)
            mp[c]++;
        
        string ans = "";
        char mini = 'a';
        for(auto c : s){
            stk.push(c), mp[c]--;
            while(mini != 'z' && mp[mini] == 0)
                mini++;
            while(!stk.empty() && stk.top() <= mini){
                ans += stk.top();
                stk.pop();
            }
        }
        return ans;
    }
};