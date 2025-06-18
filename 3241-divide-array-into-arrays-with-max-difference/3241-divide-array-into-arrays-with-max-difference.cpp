class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        if(nums.size() == 1){
            ans.push_back(nums);
            return ans;
        }
        bool comp = true;
        for(int i = 0; i+2 < nums.size(); i+=3){
            if(nums[i+2]-nums[i] <= k){
                vector<int> v;
                v.push_back(nums[i]);v.push_back(nums[i+1]); v.push_back(nums[i+2]);
                ans.push_back(v);
            }
            else{
                comp = false;
                break;
            }
        }
        if(!comp)return vector<vector<int>>();
        return ans;
    }
};