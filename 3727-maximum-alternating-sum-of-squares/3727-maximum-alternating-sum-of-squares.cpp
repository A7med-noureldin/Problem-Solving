class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long ans = 0;
        for(auto &x : nums) if(x < 0) x *= -1;
        sort(nums.begin(), nums.end());
        int i = 0, j = (int)nums.size()-1, turn = 0;
        while(i <= j){
            if(turn&1) ans -= nums[i]*nums[i], i++;
            else ans += nums[j]*nums[j], j--;
            turn = 1-turn;
        }
        return ans;
    }
};