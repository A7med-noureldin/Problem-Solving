#define ll long long
const int mod = 1e9+7;
class Solution {
public:
    int distinctSubseqII(string s) {
        int n = s.size();
        vector<ll> dp(n+1, 0);
        vector<int> lst(26, -1);
        auto sub = [&](ll &a, ll b){
            a %= mod, b %= mod;
            a = (a-b+mod)%mod;
        };
        dp[0] = 1;
        for(int i = 1; i <= n; i++){
            int idx = s[i-1]-'a';
            dp[i] = 2*dp[i-1]%mod;
            if(lst[idx] != -1){
                if(lst[idx] == 0) sub(dp[i], 1);
                else sub(dp[i], dp[lst[idx]-1]);
            }
            lst[idx] = i;
            // cout << i << " " << dp[i] << "\n"; 
        }
        sub(dp[n], 1);
        return (int)dp[n];
    }
};