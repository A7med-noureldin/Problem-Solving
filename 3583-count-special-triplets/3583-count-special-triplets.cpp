class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int MAX = 200000+5;
        const int MOD = 1e9+7;
        vector<int> freq1(MAX), freq2(MAX);
        int n = nums.size();
        for(int i = 1; i < n; i++)
            freq2[nums[i]]++;

        long long ans = 0;

        for(int i = 1; i+1 < n; i++) {
            freq1[nums[i-1]]++;
            freq2[nums[i]]--;

            int x = 2 * nums[i];
            ans = (ans + 1LL * freq1[x] * freq2[x]) % MOD;
        }
        return ans;
    }
};