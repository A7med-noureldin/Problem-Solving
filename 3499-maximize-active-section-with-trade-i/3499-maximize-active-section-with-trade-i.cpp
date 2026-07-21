class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        vector<int> zeros(1e5+10, 0);
        int n = s.size(), cnt = 0, j = 0;
        char prev = '$';
        for(auto c : s){
            cnt += (c=='1');
            j += (prev != c && c == '0');
            zeros[j] += (c=='0');
            prev = c;
        }
        int ans = 0;
        for(int i = 1; i < j; i++) ans = max(ans, zeros[i]+zeros[i+1]);
        return cnt+ans;
    }
};