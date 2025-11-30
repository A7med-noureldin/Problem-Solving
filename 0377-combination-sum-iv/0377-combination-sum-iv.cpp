class Solution {
public:
    const long long MOD = 1e18;
    int combinationSum4(vector<int>& nums, int target) {
        vector<long long> dp(1005, 0);
        dp[0] = 1;

        int n = nums.size();
        for(int i = 1; i <= target; i++){
            for(int j = 0; j < n; j++){
                if(i-nums[j]>=0){
                    dp[i] += dp[i-nums[j]];
                    if (dp[i] > MOD) dp[i] -= MOD;
                }
            }
        }
        return dp[target];
    }
};