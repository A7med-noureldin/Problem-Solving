class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int prev = 0;
        vector<bool> ans(nums.size());
        for(int i = 0; i < nums.size(); i++){
            int temp = (2 * prev + nums[i])%5;
            ans[i] = ((temp%5)==0);
            prev = temp; 
        }
        return ans;
    }
};