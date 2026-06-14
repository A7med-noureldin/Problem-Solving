class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int gMin = nums[0], curMin = 0, n = (int) nums.size();
        int gMax = nums[0], curMax = 0;
        for(int i = 0; i < n; i++){
            curMin = min(curMin+nums[i], nums[i]);
            curMax = max(curMax+nums[i], nums[i]);
            gMax = max(gMax, curMax);
            gMin = min(gMin, curMin); 
        }

        int tot = accumulate(nums.begin(), nums.end(), 0);
        return (gMax > 0? max(gMax, tot-gMin) : gMax);
    }
};