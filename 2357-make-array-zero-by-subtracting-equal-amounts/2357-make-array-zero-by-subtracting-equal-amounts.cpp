class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        vector<int> numbers(105, 0);
        for(int i = 0; i < nums.size(); i++){
            numbers[nums[i]]++;
        }
        int ans = 0;
        for(int i = 1; i <= 100; i++){
            if(numbers[i]) ans++;
        }
        return ans;
    }
};