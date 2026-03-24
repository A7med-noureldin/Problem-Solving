class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        const long long mod = 12345;
        long long pre = 1ll, suff = 1ll;
        int n = grid.size(), m = grid[0].size();

        vector<vector<int>> ans(n, vector<int>(m, 1));
        for(int i = n-1; i >= 0; i--){
            for(int j = m-1; j >= 0; j--){
                ans[i][j] = suff;
                suff = suff * grid[i][j] % mod;
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                ans[i][j] = pre * ans[i][j] % mod;
                pre = pre * grid[i][j] % mod;
            }
        }

        return ans;
    }
};