class Solution {
public:
    int ans = 0;
    void backtrack(int pos, int n, vector<bool> &vis){
        if(pos > n){
            ans++;
            return;
        }
        for(int i = 1; i <= n; i++){
            if(!vis[i] && (i % pos ==0 || pos % i == 0)){
                vis[i] = true;
                backtrack(pos + 1, n, vis);
                vis[i] = false;
            }
        }
    }
    int countArrangement(int n) {
        vector<bool> vis(n+1, false);
        backtrack(1, n, vis);
        return ans;
    }   
};