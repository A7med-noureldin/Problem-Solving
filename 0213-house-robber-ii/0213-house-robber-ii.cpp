class Solution {
public:
    int solve(vector<int>& nums, int l, int r) {
        int len = r-l+1;
        if (len == 1) return nums[l];
        if (len == 2) return max(nums[l], nums[l + 1]);

        vector<int> dp(len);
        dp[0] = nums[l];
        dp[1] = max(nums[l], nums[l+1]);

        for (int i = 2; i < len; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[l + i]);
        }
        return dp[len-1];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);

        return max(solve(nums, 0, n-2), solve(nums, 1, n-1));
    }
};
