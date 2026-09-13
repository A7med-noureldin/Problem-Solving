class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();  
        int ans = 0;

        auto isValid = [&](int i, int j, int x, int y){
            return i >= 0 && i < n && j >= 0 && j < n && img1[i][j] == img2[x][y] && img1[i][j] == 1;
        };

        for(int h = -(n-1); h <= n-1; h++){
            for(int v = -(n-1); v <= n-1; v++){
                int mx = 0;
                for(int i = 0; i < n; i++){
                    for(int j = 0; j < n; j++){
                        int ii = i+h, jj = j+v;
                        if(isValid(ii, jj, i, j)) mx++;
                    }
                    ans = max(ans, mx);
                }
            }
        }
        return ans;
    }
};