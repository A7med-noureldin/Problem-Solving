class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int l = 0, n = nums.size();
        sort(nums.begin(), nums.end());
        int mx = 0;
        for(int r = 0; r < n; r++){
            while(l <= r && 1LL*nums[l]*k < nums[r]) l++;
            mx = max(mx, r-l+1);
        }
        return n-mx;
    }
};