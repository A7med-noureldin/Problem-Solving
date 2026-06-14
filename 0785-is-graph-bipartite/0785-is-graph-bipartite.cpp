class Solution {
public:
    vector<int> color;
    vector<int> adj[105];
    bool isbipartite;
    void dfs(int u, int c){
        if(!isbipartite) return;
        color[u] = c;
        for(auto v : adj[u]){
            if(color[v] == -1) dfs(v, 1-c);
            else if (c == color[v]) isbipartite = false;
        }
    }

    bool isBipartite(vector<vector<int>>& graph) {
        color.assign(graph.size(), -1);
        isbipartite = true;
        for(int i = 0; i < graph.size(); i++){
            for(int j = 0; j < graph[i].size(); j++){
                adj[i].push_back(graph[i][j]);
                adj[graph[i][j]].push_back(i);
            }
        }

        for(int i = 0; i < graph.size(); i++){
            if(color[i] == -1) {
                dfs(i, 0);
            }
        }
        return isbipartite;
    }
};