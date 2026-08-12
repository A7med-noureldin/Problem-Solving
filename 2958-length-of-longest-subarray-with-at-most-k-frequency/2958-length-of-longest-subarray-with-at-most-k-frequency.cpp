class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        vector<int> v(nums.begin(), nums.end());
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        vector<int> freq(1e5+5, 0);
        int l = 0, r = 0, n = nums.size();
        int ans = 0;
        for(int r = 0; r < n; r++){
            int cur = lower_bound(v.begin(), v.end(), nums[r]) - v.begin();
            freq[cur]++;
            while(l <= r && freq[cur] > k) {
                int x = lower_bound(v.begin(), v.end(), nums[l]) - v.begin();
                freq[x]--, l++;
            }
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};