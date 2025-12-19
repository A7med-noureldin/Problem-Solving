class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int area = 0, n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == '0') continue;
                int l = 0, u = 0, ul = 0;
                if(j > 0) l = dp[i][j-1];
                if(i > 0) u = dp[i-1][j];
                if(i > 0 && j > 0) ul = dp[i-1][j-1];
                dp[i][j] = min(l, min(u, ul)) + 1;
                area = max(area, dp[i][j]);
            }
        }
        area *= area;
        return area;
    }
};