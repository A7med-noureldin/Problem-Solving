class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans;
        set<int> s;
        for(int i = 0; i < nums.size(); i++){
            if(s.count(nums[i]))ans.push_back(nums[i]);
            s.insert(nums[i]);
        }

        for(int i = 1; i <= nums.size(); i++){
            if(!s.count(i))ans.push_back(i);
        }
       return ans;
    }
};