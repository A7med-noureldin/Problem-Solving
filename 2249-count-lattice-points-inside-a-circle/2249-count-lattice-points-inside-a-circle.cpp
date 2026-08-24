class Solution {
public:
    int countLatticePoints(vector<vector<int>>& circles) {
        vector<vector<bool>> vis(205, vector<bool>(205, 0));

        for(auto c : circles){
            int xc = c[0], yc = c[1], r = c[2];
            for(int x = xc-r; x <= xc+r; x++){
                for(int y = yc-r; y <= yc+r; y++){
                    int dx = x-xc, dy = y-yc;
                    if(dx*dx + dy*dy <= r*r) vis[x][y] = 1;
                }
            }
        }
        
        int cnt = 0;
        for(int i = 0; i < 205; i++){
            for(int j = 0; j < 205; j++){
                cnt += vis[i][j];
            }
        }
        return cnt;
    }
};