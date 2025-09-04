class Solution {
public:
    vector<string> ans;
    void backtrack(string &s, int i, int n){
        if(i == n){
            ans.push_back(s);
            return;
        }
        
        if(isdigit(s[i]))
            backtrack(s, i+1, n);
        else{
            backtrack(s, i+1, n);

            s[i] = islower(s[i])? toupper(s[i]) : tolower(s[i]);
            backtrack(s, i+1, n);
            s[i] = islower(s[i])? toupper(s[i]) : tolower(s[i]);
        }
    }
    vector<string> letterCasePermutation(string s) {
        backtrack(s, 0, s.size());
        return ans;
    }
};