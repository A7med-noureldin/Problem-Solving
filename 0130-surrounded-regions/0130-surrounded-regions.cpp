class Solution {
public:
    int n, m;
    bool vis[205][205];
    int dx[9] = {1, 0, -1, 0, -1, -1, 1, 1};
    int dy[9] = {0, -1, 0, 1, -1, 1, -1, 1};
    bool isValid(int x, int y, vector<vector<char>>& board){
        return x >= 0 && x < n && y >= 0 && y < m && board[x][y] == 'O' && !vis[x][y];
    }
    void dfs(int x, int y, vector<vector<char>>& board){
        vis[x][y] = true;
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i], ny = y + dy[i];
            if(isValid(nx, ny, board))
                dfs(nx, ny, board);
        }
    }
    void solve(vector<vector<char>>& board) {
        n = board.size(), m = board[0].size();
        memset(vis, false, sizeof vis);
        for(int i = 0; i < n; i++){
            if(board[i][0] == 'O') dfs(i, 0, board);
            if(board[i][m-1] == 'O') dfs(i, m-1, board);
        }
        for(int j = 0; j < m; j++){
            if(board[0][j] == 'O') dfs(0, j, board);
            if(board[n-1][j] == 'O') dfs(n-1, j, board);
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!vis[i][j] && board[i][j] == 'O') board[i][j] = 'X';
            }
        }
    }
};