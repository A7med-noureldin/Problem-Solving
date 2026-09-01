int dx[] = {+1, +0, +0, -1, -1, -1, +1, +1};
int dy[] = {+0, -1, +1, +0, -1, +1, -1, +1};    
class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        pair<int, int> s = {-1, -1};
        int n = classroom.size(), m = classroom[0].size();
        int Ls = 0;
        vector<vector<int>> msk(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(classroom[i][j] == 'S') s = {i, j};
                if(classroom[i][j] == 'L') msk[i][j] = 1<<Ls++;
            }
        }

        auto valid = [&](int x, int y){
            return x >= 0 && x < n && y >= 0 && y < m && classroom[x][y] != 'X';
        };

        // x, y, energy, mask, cost
        queue<array<int, 5>> q;
        array<int, 5> a = {s.first, s.second, energy, 0, 0};
        q.push(a);
        int bst[n][m][1<<Ls];
        memset(bst, -1, sizeof bst);
        bst[s.first][s.second][0] = energy;
        while(!q.empty()){
            auto [x, y, e, mask, cost] = q.front(); q.pop();
            if(mask == (1<<Ls)-1) return cost;
            if(e == 0) continue;
            for(int i = 0; i < 4; i++){
                int nx = x+dx[i], ny = y+dy[i];
                if(valid(nx, ny)){
                    int ne = e;
                    if(classroom[nx][ny] == 'R') ne = energy;
                    else ne--;
                    int nmsk = mask | msk[nx][ny];
                    if(ne > bst[nx][ny][nmsk]){
                        array<int, 5> a = {nx, ny, ne, nmsk, cost+1};
                        q.push(a);
                        bst[nx][ny][nmsk] = ne;
                    }
                }
            }
        }
        return -1;
    }
};