class Solution {
public:
    vector<string> ans;
    int size;
    void backtrack(string curr, int n, int open, int close){
        if((open + close) == 2*n){
            ans.push_back(curr);
            return;
        }
        
        if(open < n){
            backtrack(curr+"(", n, open+1, close);
        }

        if(close < open){
            backtrack(curr+")", n, open, close+1);
        }
    }

    vector<string> generateParenthesis(int n) {
        size = n;
        backtrack("", size, 0, 0);
        return ans;
    }
};