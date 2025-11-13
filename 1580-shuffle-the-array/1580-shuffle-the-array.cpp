class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int i = 0, j = n, idx = 0;
        vector<int> ans(2*n);
        while(i < n && j < 2*n){
            ans[idx] = nums[i++];
            idx++;
            ans[idx] = nums[j++];
            idx++;
        }
        return ans;
    }
};