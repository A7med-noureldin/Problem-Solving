class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 0);
        for(int i = 0; i < n; i++){
            if(nums[i] == 0) continue;
            int pos = (i+nums[i])%n;
            if(pos < 0) pos += n;
            res[i] = nums[pos];
        }
        return res;
    }
};