class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int ans = 0, n = (int)nums.size();
        vector<int> dp(2510, 1);
        for(int i = n-1; i >= 0; i--){
            for(int j = i+1; j < n; j++){
                dp[i] = max(dp[i], (nums[i] < nums[j]? dp[j]+1 : 0));
            }
        }
        ans = *max_element(dp.begin(), dp.end());
        return ans;
    }
};