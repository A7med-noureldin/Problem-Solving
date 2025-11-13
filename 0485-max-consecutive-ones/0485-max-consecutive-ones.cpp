class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0, n = nums.size(), c = 0;
        for(int i = 0; i < n; i++){
            if(nums[i])c++;
            else ans = max(ans, c), c = 0;
        }
        ans = max(ans, c);
        return ans;
    }
};