class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0], sum = 0, n = (int) nums.size();
        for(int i = 0; i < n; i++){
            sum = max(sum+nums[i], nums[i]);
            ans = max(sum, ans);
        }
        return ans;
    }
};