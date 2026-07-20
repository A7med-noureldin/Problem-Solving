class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        vector<int> ans(n);
        for(int i = 0, idx = n-k; i < n; i++, idx++){
            ans[i] = nums[idx%n];
        }
        for(int i = 0; i < n; i++){
            nums[i] = ans[i];
        }
    }
};