class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        long long ans = 0;
        for(auto i : nums) ans += i;
        return (ans%k);
    }
};