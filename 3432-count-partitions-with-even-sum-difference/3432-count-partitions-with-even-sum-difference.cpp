class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int sum = 0;
        for(auto n : nums) sum += n;
        int ans = 0, temp = 0;
        for(int i = 0; i+1 < nums.size(); i++){
            temp += nums[i];
            if((sum - 2*temp)%2 == 0)ans++;
        }
        return ans;
    }
};