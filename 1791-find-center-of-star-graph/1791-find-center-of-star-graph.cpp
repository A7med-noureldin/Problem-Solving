class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        map<int, int> mp;
        int n = edges.size(), ans = 0;
        for(int i = 0; i < n; i++){
            mp[edges[i][0]]++;
            mp[edges[i][1]]++;
        }
        
        for(auto [p, q] : mp){
            if(q == n){
                return p;
            }
        }
        return -1;
    }
};