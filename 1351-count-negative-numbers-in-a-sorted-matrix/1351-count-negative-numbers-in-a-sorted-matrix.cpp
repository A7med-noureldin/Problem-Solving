class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ans = 0, n = grid.size(), m = grid[0].size();
        for(int i = n-1; i >= 0; i--){
            for(int j = m-1; j >= 0; j--){
                if(grid[i][j] >= 0)break;
                ans++;
            }
        }
        return ans;
    }
};