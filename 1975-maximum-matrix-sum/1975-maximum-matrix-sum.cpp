class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum = 0;
        int n = matrix.size(), m = matrix[0].size();
        int neg = 0, mini = 1e6;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] < 0){
                    neg++;
                    matrix[i][j] *= -1;
                } 
                sum += matrix[i][j];
                mini = min(mini, matrix[i][j]);
            }
        }

        if(neg&1) sum -= (2LL*mini);

        return sum;
    }
};