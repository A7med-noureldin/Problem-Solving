class Solution {
public:
    bool isGood(vector<vector<int>> grid, int x, int y){
        vector<bool> vis(10, false);

        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                int num = grid[x+i][y+j];
                if(!(num >= 1 && num <= 9)) return false;
                if(vis[num]) return false;
                vis[num] = 1;
            }
        }

        int diag1 = grid[x][y]+grid[x+1][y+1]+grid[x+2][y+2];
        int diag2 = grid[x+2][y]+ grid[x+1][y+1]+grid[x][y+2];

        if(diag1 != diag2) return false;

        int row1 = grid[x][y]+grid[x][y+1]+grid[x][y+2];
        int row2 = grid[x+1][y]+grid[x+1][y+1]+grid[x+1][y+2];
        int row3 = grid[x+2][y]+grid[x+2][y+1]+grid[x+2][y+2];

        if(row1 != diag1 || row2 != diag1 || row3 != diag1) return false;

        int col1 = grid[x][y] + grid[x+1][y] + grid[x+2][y];
        int col2 = grid[x][y+1] + grid[x+1][y+1] + grid[x+2][y+1];
        int col3 = grid[x][y+2] + grid[x+1][y+2] + grid[x+2][y+2];

        if(col1 != diag2 || col2 != diag2 || col3 != diag2) return false;

        return true;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i = 0; i+2 < grid.size(); i++){
            for(int j = 0; j+2 < grid[0].size(); j++){
                if(isGood(grid, i, j)) ans++;
            }
        }
        return ans;
    }
};