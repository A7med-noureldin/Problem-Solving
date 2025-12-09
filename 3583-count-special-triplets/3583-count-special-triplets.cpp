class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        map<int, int> freq1, freq2;
        for(int i = 1; i < nums.size(); i++){
            freq2[nums[i]]++;
        }
        long long ans = 0;
    
        for(int i = 1; i+1 < nums.size(); i++){
            freq1[nums[i-1]]++, freq2[nums[i]]--;
            int x = 2*nums[i];
            ans = (ans + 1LL * freq1[x] * freq2[x]) % 1000000007;
        }
        return ans;
    }
};