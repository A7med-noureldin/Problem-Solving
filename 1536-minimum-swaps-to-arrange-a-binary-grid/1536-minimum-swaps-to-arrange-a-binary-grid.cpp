class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> mxR(n, -1);
        for(int i = 0; i < n; i++){
            for(int j = n-1; j >= 0; j--){
                if(grid[i][j] == 1){
                    mxR[i] = j;
                    break;
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
           int x = -1;
           for(int j = i; j < n; j++){
                if(mxR[j] <= i){
                    ans += j-i;
                    x = j;
                    break;
                }
           }
           if(x == -1) return -1;
            for(int j = x; j > i; j--){
                swap(mxR[j], mxR[j-1]);
            }
        }
        return ans;
    }
};