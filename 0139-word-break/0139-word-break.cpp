class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = (int) wordDict.size(), m = s.size();
        vector<bool> dp(m, false);
        dp[m] = true;
        for(int i = m-1; i >= 0; i--){
            for(auto w : wordDict){
                int x = w.size();
                if((i+x) <= m && s.substr(i, x) == w){
                    //cout << i << " " << w << "\n";
                    dp[i] = dp[i+x];
                }
                if(dp[i]) break;
            }
        }
        return dp[0];
    }
};