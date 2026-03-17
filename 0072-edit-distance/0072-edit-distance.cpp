class Solution {
public:
    vector<vector<int>> dp;

    int ED(string &s, string &t, int i, int j) {
        if (i == -1) return max(j+1, 0);
        if (j == -1) return max(i+1, 0);

        if (dp[i][j] != -1) return dp[i][j];
        if (s[i] == t[j])
            return dp[i][j] = ED(s, t, i-1, j-1);
        return dp[i][j] = 1 + min({ED(s, t, i-1, j), ED(s, t, i, j-1), ED(s, t, i-1, j-1)});
    }

    int minDistance(string s, string t) {
        int n = (int)s.size(), m = (int)t.size();
        if(n == 0) return m;
        if(m == 0) return n;
        dp.assign(n, vector<int>(m, -1));
        ED(s, t, n-1, m-1);
        return dp[n-1][m-1];
    }
};