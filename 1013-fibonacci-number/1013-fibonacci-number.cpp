class Solution {
public:
    int dp[31];
   Solution() {
        dp[1] = 1;
    }
    int fib(int n) {
        if(n <= 0) return 0;
        if(dp[n] > 0) return dp[n];
        dp[n] = fib(n - 1) + fib(n - 2);
        return dp[n];
    }
};