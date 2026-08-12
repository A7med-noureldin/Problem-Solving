class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> v(nums.begin(), nums.end());
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        vector<int> freq(1e5+5, 0), id(n, -1);
        for(int i = 0; i < n; i++){
            id[i] = lower_bound(v.begin(), v.end(), nums[i]) - v.begin();
        }
        int l = 0, r = 0;
        int ans = 0;
        for(int r = 0; r < n; r++){
            int cur = id[r];
            freq[cur]++;
            while(l <= r && freq[cur] > k) {
                int x = id[l];
                freq[x]--, l++;
            }
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};