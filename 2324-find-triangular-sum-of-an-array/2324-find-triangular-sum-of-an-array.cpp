class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int ans = 0, n = nums.size();
        vector<int> temp;
        for(int i = 1; i < n; i++){
            temp.resize(n-i);
            for(int j = 0; j < n-1; j++){
                temp[j] = (nums[j] + nums[j+1])%10;
            }
            nums = temp;
        }
        return nums[0];
    }
};