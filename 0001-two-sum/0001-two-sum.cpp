class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int l = 0, n = nums.size();
        unordered_map<int, int> mp;
        while(l < n){
            if (mp.find(target-nums[l]) != mp.end()) {
                return {mp[target-nums[l]], l};
            }
            mp[nums[l]] = l;
            l++;
        }
        return vector<int>();
    }
};