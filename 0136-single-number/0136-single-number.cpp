class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x = 0;
        for(auto i : nums){
            x ^= i;
        }
        // 3 011, 2 010, 1 001
        // 3 ^ 2 = 1
        // 3 ^ 1 = 2
        return x;
    }
};