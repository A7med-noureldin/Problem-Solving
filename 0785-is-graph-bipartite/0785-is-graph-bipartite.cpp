class Solution {
public:
    vector<int> color;
    bool ok = true;

    void dfs(int u, int c, vector<vector<int>>& graph) {
        color[u] = c;

        for (int v : graph[u]) {
            if (color[v] == -1)
                dfs(v, 1 - c, graph);
            else if (color[v] == c)
                ok = false;
        }
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        color.assign(n, -1);

        for (int i = 0; i < n; i++) {
            if (color[i] == -1)
                dfs(i, 0, graph);
        }

        return ok;
    }
};