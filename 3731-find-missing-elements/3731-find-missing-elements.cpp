class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> ans;
        sort(nums.begin(), nums.end());
        int x = nums[0], n = nums.size();
        for(int i = 0; i < n; i++, x++){
            while(i < n && x != nums[i]){
                ans.push_back(x++);
            }
        }
        return ans;
    }
};