class Solution {
    const int N = 1001;
public:
    int dp[1001][1001];
    int rn(int i, int j, string &s, string &t){
        if(i >= s.size() || j >= t.size()) return 0;
        if(~dp[i][j]) return dp[i][j];
        if(s[i] == t[j]) return dp[i][j] = rn(i+1, j+1, s, t) + 1;
        return dp[i][j] = max(rn(i+1, j, s, t), rn(i, j+1, s, t));
    }
    int longestCommonSubsequence(string s, string t) {
        memset(dp, -1, sizeof(dp));
        return rn(0, 0, s, t);
    }
};