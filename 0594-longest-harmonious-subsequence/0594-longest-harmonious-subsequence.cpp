class Solution {
public:
    int findLHS(vector<int>& nums) {
        int ans = 0;
        map<int, int> mp;
        for(auto x : nums)
            mp[x]++;
        set<int> s(nums.begin(), nums.end());
        for(auto i : s){
            if(mp.find(i+1) != mp.end())
                ans = max(ans, mp[i+1]+mp[i]);
            
            if(mp.find(i-1) != mp.end())
                ans = max(ans, mp[i-1]+mp[i]);
        }
        return ans;
    }
};