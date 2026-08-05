class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<bool> remove(n, false);
        vector<vector<int>> adj(n+1);
        for(auto v : invocations){
            adj[v[0]].push_back(v[1]);
        }

        function<void(int)> badDfs = [&](int u) {
            remove[u] = true;
            for(auto v : adj[u]) {
                if(!remove[v]) badDfs(v);
            }
        };

        badDfs(k);

        
        for(auto v : invocations){
            if(!remove[v[0]] && remove[v[1]]){
                vector<int> ans(n);
                iota(ans.begin(), ans.end(), 0);
                return ans;
            }
        }
        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(!remove[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};