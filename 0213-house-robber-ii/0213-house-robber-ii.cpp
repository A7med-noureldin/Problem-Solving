class Solution {
public:
    int solve(vector<int>& nums, int l, int r) {
        int prevRob = 0, maxRob = 0;
        for (int i = l; i <= r; i++) {
            int t = max(maxRob, prevRob + nums[i]);
            prevRob = maxRob;
            maxRob = t;
        }
        return maxRob;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        return max(solve(nums, 0, n-2), solve(nums, 1, n-1));
    }
};
