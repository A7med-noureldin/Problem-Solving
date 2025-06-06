class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> pq;
        map<int, int> mp;
        for(auto i : nums)
            mp[i]++;
        for(auto [x, y] : mp)
            pq.push({y, x});
        vector<int> ans;
        while(k-- && !pq.empty()){
            int x = pq.top().second;
            ans.push_back(x);
            pq.pop();
        }
        return ans;
    }
};