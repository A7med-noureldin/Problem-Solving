class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int n = mat.size(), m = mat[0].size();

        if(n*m != r*c) return mat;

        vector<vector<int>> ans(r, vector<int>(c));
        vector<int> t;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                t.push_back(mat[i][j]);
            }
        }

        for(int i = 0; i < t.size(); i++){
            ans[i/c][i%c] = t[i];
        }
        return ans;
    }
};