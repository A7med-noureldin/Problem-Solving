class Solution {
public:
    vector<int> bestTower(vector<vector<int>>& towers, vector<int>& center, int r) {
        vector<vector<int>> reachable;
        int xc = center[0], yc = center[1];
        for(auto t : towers){
            int x = t[0], y = t[1], q = t[2];
            if((abs(xc-x)+abs(yc-y)) <= r){
                reachable.push_back(t);
            }
        }

        sort(reachable.begin(), reachable.end(), [&](vector<int> &a, vector<int> &b){
            if(a[2] != b[2]) return a[2] > b[2];   
            if(a[0] != b[0]) return a[0] < b[0];  
            return a[1] < b[1];
        });
        if(reachable.size() == 0) return {-1, -1};
        return {reachable[0][0], reachable[0][1]};
    }
};