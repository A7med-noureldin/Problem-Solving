const int N = 1e3;
int n, m;
string temp, ss;
int dp[N][N];
class Solution {
public:
    int calc(int i = 0, int j = 0){
        if(j == m) return 1;
        if(i == n) return 0;
        int &ret = dp[i][j];
        if(~ret) return ret;
        // leave
        int x = 0;
        x += calc(i+1, j);
        // pick
        if(ss[i] == temp[j]) x += calc(i+1, j+1);
        return ret = x;
    }
    int numDistinct(string s, string t) {
        n = s.size(), m = t.size();
        temp = t, ss = s;
        memset(dp, -1, sizeof dp);
        return calc();
    }
};

//rabbitrabbit