class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> ans;
        int orgSize = original.size();
        if(orgSize != m*n) return ans;

        ans = vector<vector<int>>(m, vector<int>(n));
        // Brute force
        // int x = 0;
        // for(int i = 0; i < m; i++){
        //     for(int j = 0; j < n; j++){
        //         ans[i][j] = original[x++];
        //     }
        // }

        // Math
        for(int i = 0; i < orgSize; i++){
            ans[i/n][i%n] = original[i];
        }

        return ans;
    }
};