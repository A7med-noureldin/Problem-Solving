class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size(), maxOr = 0, ans = 0;
        for(int i = 0; i < n; i++){
            maxOr |= nums[i];
        }
        for(int mask = 0; mask < (1<<n); mask++){
            int Or = 0;
            for(int i = 0; i < n; i++){
                if(mask&(1<<i)){
                    Or|=nums[i];
                }
            }
            if(Or==maxOr) ans++;
        }
        return ans;
    }
};