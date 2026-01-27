class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(n+1);
        for(auto v : edges){
            adj[v[0]].push_back({v[1], v[2]});
            adj[v[1]].push_back({v[0], 2*v[2]});
        } 
        const int oo = 0x3f3f3f3f;
        vector<int> dist(n+1, oo);
        vector<bool> used(n+1, 0);
        queue<int> q;
        q.push(0);
        dist[0] = 0;
        while(!q.empty()){
            int u = q.front(); q.pop();
            if(used[u]) continue;
            used[u] = 1;
            for (auto vec : adj[u]) {
                int v = vec.first;
                int w = vec.second;
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    q.push(v);
                }
            }
        } 
        if(dist[n-1] == oo) return -1;
        return dist[n-1];
    }
};