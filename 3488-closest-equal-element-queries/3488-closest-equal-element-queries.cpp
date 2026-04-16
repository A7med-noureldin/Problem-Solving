class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = queries.size(), m = nums.size();
        vector<int> ans(n, -1);
        map<int, vector<int>> mp;
        for(int i = 0; i < m; i++){
            mp[nums[i]].push_back(i);
        }
        for(auto &[x, v] : mp){
            int frst = v[0];
            v.insert(v.begin(), v.back()-m);
            v.push_back(frst+m);
        }
        for(int i = 0; i < n; i++){
            auto &v = mp[nums[queries[i]]];
            if(v.size() == 3) continue;
            
            int pos = lower_bound(v.begin(), v.end(), queries[i]) - v.begin();
            ans[i] = min(v[pos+1]-v[pos], v[pos]-v[pos-1]); 
        }
        return ans;
    }
};