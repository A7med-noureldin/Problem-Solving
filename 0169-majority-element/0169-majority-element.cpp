class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majority = 0, votes = 0, n = nums.size();
        for(int i = 0; i < n; i++){
            if(votes == 0) majority = nums[i], votes = 1;
            else {
                if(majority != nums[i])votes--;
                else votes++;
            }
        }
        return majority;
    }
};