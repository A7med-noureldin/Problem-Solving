class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, n = nums.size();
        int sum = 0, ans = INT_MAX;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            if(sum == target) ans = min(ans, i-l+1);
            while(sum >= target) ans = min(ans, i-l+1), sum -= nums[l++];
        }
        return (ans == INT_MAX? 0 : ans);
    }
};