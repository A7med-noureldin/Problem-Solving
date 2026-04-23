#define ll long long
class Solution {
public:
    int n;
    ll tar, sum;
    vector<int> v;
    ll dp[1<<17]; // mask
    bool calc(int mask, int currSum){
        if(mask == (1<<n)-1) return currSum == 0;

        ll &ret = dp[mask];
        if(~ret) return ret;
        ret = 0;

        for(int i = 0; i < n; i++){
            if((mask>>i)&1) continue;
            if(currSum + v[i] > tar) continue;
            int nSum = currSum + v[i];
            int nMask = mask|(1<<i);
            if(nSum == tar){
                if(calc(nMask, 0)) ret = 1;
            } 
            else{
                if(calc(nMask, nSum)) ret = 1;
            }
        }   
        return ret;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        sum = 0;
        v = nums;
        n = nums.size();
        for(auto x : nums) sum += x;
        if(sum % k != 0) return false;
        tar = sum/k;
        memset(dp, -1, sizeof dp);
        return calc(0, 0);
    }
};