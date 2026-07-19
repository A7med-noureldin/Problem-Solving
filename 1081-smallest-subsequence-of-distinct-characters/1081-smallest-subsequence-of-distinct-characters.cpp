class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> cnt(26, 0), vis(26, 0);
        for(auto c : s) cnt[c-'a']++;

        string stk;
        for(auto c : s){
            if(!vis[c-'a']){
                while(!stk.empty() && stk.back() > c && cnt[stk.back()-'a'] > 0){
                    vis[stk.back()-'a'] = 0; stk.pop_back();
                }
                vis[c-'a'] = 1;
                stk.push_back(c);
            }
            cnt[c-'a']--;
        }
        return stk;
    }
};