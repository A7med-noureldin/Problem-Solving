class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n, 1), suff(n+1, 1);
        int prod = 1;
        for(int i = 0; i < n; i++){
            pre[i] = prod, prod *= nums[i];
        }

        prod = 1;
        for(int j = n-1; j >= 0; j--){
            suff[j] = prod, prod *= nums[j];
        }
        nums[0] = suff[0], nums[n-1] = pre[n-1];
        for(int i = 1; i+1 < n; i++){
            nums[i] = pre[i] * suff[i];
        }
        return nums;
    }
};