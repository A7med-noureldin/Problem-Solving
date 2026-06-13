class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 1) return 1;

        int idx = 1, n = (int)nums.size();
        for(int j = 1; j < n; j++){
            if(nums[idx-1] != nums[j]){
                nums[idx] = nums[j], idx++;
            }
        }
        return idx;
    }
};