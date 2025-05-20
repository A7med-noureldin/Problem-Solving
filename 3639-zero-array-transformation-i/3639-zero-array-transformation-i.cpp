class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> pre(nums.size()+2, 0);
        // [1, 0, 1]
        // [0, 2]
        // [+1, 0, 0, -1, 0]
        // pre -> [1, 1, 1, 0, 0]
        for(auto v : queries){
            pre[v[0]]++, pre[v[1]+1]--;
        }
        for(int i = 1; i < nums.size(); i++){
            pre[i] += pre[i-1];
        }
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > pre[i])
                return 0;
        }
        return 1;
    }
};