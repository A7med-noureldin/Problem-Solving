class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int maxi = INT_MIN, n = nums.size();
        for(int i = 0; i <= n;i++){
            maxi = max(maxi, abs(nums[i%n]-nums[(i+1)%n]));
        }
        return maxi;
    }
};