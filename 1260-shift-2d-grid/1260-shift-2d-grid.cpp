class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        int mod = n*m;
        vector<vector<int>> ans(n, vector<int>(m));
        k %= mod;
        vector<int> tmp;
        for(auto r : grid){
            for(auto x : r) tmp.push_back(x);
        }

        int st = mod-k;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(st >= mod)st = 0;
                ans[i][j] = tmp[st++];
            }
        }
        return ans;
    }
};