class Solution {
public:
    void sortColors(vector<int>& nums) {
        /*
         * Insertion O(n^2)
         * R W B
         * 0 1 2
        */
        int n = nums.size();
        for(int i = 1; i < n; i++){
            int temp = nums[i];
            for(int j = i-1; j >= 0 && nums[j] > temp; j--){
                nums[j+1] = nums[j];
                nums[j] = temp;
            }
        }
    }
};