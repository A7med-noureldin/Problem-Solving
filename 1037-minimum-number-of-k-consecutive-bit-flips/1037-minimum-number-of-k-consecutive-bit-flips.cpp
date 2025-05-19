class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int flips = 0, ans = 0;
        for(int i = 0; i < nums.size(); i++){
            if(i >= k && nums[i-k] == -1){
                --flips;
            }
            if(nums[i] == (flips&1)){
                if(i+k > nums.size())return -1;
                flips++, nums[i] = -1, ans++;
            }
        }
        return ans;
    }
};
