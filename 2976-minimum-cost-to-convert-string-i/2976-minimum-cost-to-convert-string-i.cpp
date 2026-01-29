#define ll long long 
class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n = source.size(), oo = 0x3f3f3f3f, m = original.size();
        vector<vector<ll>> dist(26, vector<ll>(26, oo));

        for(int i = 0; i < m; i++){
            int s = original[i]-'a';
            int d = changed[i]-'a';

            dist[s][d] = min(dist[s][d], (ll)cost[i]);
        }

        for(int k = 0; k < 26; k++){
            for(int i = 0; i < 26; i++){
                for(int j = 0; j < 26; j++){
                    // min(i->j, i->k->j)
                    dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
                }
            }
        }
        ll ans = 0;
        for(int i = 0; i < n; i++){
            int s = source[i]-'a';
            int d = target[i]-'a';

            if(s==d) continue;
            if(dist[s][d] == oo) return -1;
            ans += dist[s][d];
        }
        return ans;
    }
};