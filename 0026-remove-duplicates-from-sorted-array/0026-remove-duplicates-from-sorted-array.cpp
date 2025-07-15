class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int x = 0;
        vector<int> vis(400, 0);
        for(int i = 0; i < nums.size(); i++){
            if(vis[nums[i]+100] == 0)nums[x++] = nums[i],  vis[nums[i]+100]++;
        }
        return x;
    }
};