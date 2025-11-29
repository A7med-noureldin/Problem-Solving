class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int minCost = 0, n = cost.size();
        vector<int> dp(n+2, 0);
        dp[0] = cost[0], dp[1] = cost[1];
        for(int i = n-1; i >= 0; i--){
            dp[i] = cost[i] + min(dp[i+1], dp[i+2]);
        }
        return min(dp[0], dp[1]);
    }
};