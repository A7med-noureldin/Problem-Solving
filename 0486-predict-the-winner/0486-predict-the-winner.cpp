class Solution {
public:
    vector<vector<int>> dp;
    int calc(vector<int>& piles, int l, int r){
        if(l > r) return 0;
        if(dp[l][r] != -1) return dp[l][r];
        if(l == r) return piles[l];

        int left = piles[l] - calc(piles, l+1, r);
        int right = piles[r] - calc(piles, l, r-1);
        return dp[l][r] = max(left, right);
    }

    bool predictTheWinner(vector<int>& piles) {
        int n = piles.size();
        dp = vector<vector<int>>(n, vector<int>(n, -1));
        return calc(piles, 0, n-1) >= 0;
    }
};