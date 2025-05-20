class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int idx = 0;
        vector<int> pre(nums.size()+1, 0);
        for(int i = 0; i < nums.size(); i++){
            if(i)pre[i] += pre[i-1];
            while(nums[i] > pre[i]){
                if(idx == queries.size())return -1;
                int l = queries[idx][0], r = queries[idx][1], val = queries[idx][2];
                idx++;
                if(r < i)continue;
                pre[max(i, l)] += val, pre[r+1] -= val;
            }
            //cout << i << ' ' << idx << ' ' << nums[i] << ' ' << pre[i] << '\n';
        }
        return idx;
    }
};