class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        int mx = -1e9;
        vector<int> mn(n, 1e9);
        mn[n-1] = nums[n-1];
        for(int i = n-2; i >= 0; i--){
            mn[i] = min(mn[i+1], nums[i]);
        }
        for(int i = 0; i < n; i++){
            mx = max(mx, nums[i]);
            int x = mx - mn[i];
            if(x <= k) return i;
        }
        return -1;
    }
};