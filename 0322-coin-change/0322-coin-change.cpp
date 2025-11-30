class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        const int mod = 1e9+7;
        vector<int> dp(amount+5, 1e5);
        dp[0] = 0;

        for(int i = 1; i <= amount; i++){
            for(auto x : coins){
                if(i-x>=0){
                    dp[i] = min(dp[i], dp[i-x]+1);
                    if(dp[i] >= mod) dp[i] -= mod;
                }
            }
        }
        return (dp[amount]==1e5)? -1 : dp[amount];
    }
};