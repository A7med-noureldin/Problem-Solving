class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int l = 0, r = n-1;
        int maxi = INT_MIN;
        while(l < r){
            maxi = max(maxi, nums[l++]+nums[r--]);
        }
        return maxi;
    }
};