class Solution {
public:
    string maxSumOfSquares(int n, int sum) {
        string ans = "";
        int summ = sum;
        for(int i = 0; i < n; i++){
            for(int d = 9; d >= 0; d--){
                if(sum >= d) {ans.push_back(char(d+'0')), sum -= d; break;}
            }
        }

        int sm = 0;
        for(int i = 0; i < n; i++){
            sm += ans[i]-'0';
        }
        // cout << sm << " " << s;
        return (sm != summ? "" : ans);
    }
};